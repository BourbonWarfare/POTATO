#include "..\script_component.hpp"
/*
 * Author: commy2, kymckay, LinkIsGrim modified by johnb43 & Lambda.Tiger
 * Original:
 * HandleDamage EH where wound events are raised based on incoming damage.
 * Be aware that for each source of damage, the EH can fire multiple times (once for each hitpoint).
 * We store these incoming damages and compare them on our final hitpoint: "ace_hdbracket".
 * Added:
 * Handling of damage to allow armor modifcation.
 *
 * Arguments:
 * Handle damage EH
 *
 * Return Value:
 * Damage to be inflicted <NUMBER>
 *
 * Public: No
 */
#define INSTAKILL_ALLOWED(unit) (unit isNotEqualTo (unit getVariable [QACEGVAR(medical_engine,blockInstaKill), objNull]))
params ["_args", ["_ignoreAllowDamageACE", false]];
_args params ["_unit", "_selection", "_damage", "_shooter", "_ammo", "_hitPointIndex", "_instigator", "_hitpoint", "_directHit", "_context"];

// HD sometimes triggers for remote units - ignore.
if !(local _unit) exitWith {nil};

// Get missing meta info
private _oldDamage = 0;
private _structuralDamage = _context == 0;

if (_structuralDamage) then {
    _hitPoint = "#structural";
    _oldDamage = damage _unit;
} else {
    _oldDamage = _unit getHitIndex _hitPointIndex;
};

// Damage can be disabled with old variable or via sqf command allowDamage
if !(isDamageAllowed _unit && {_unit getVariable [QACEGVAR(medical,allowDamage), true] || _ignoreAllowDamageACE}) exitWith {_oldDamage};

// Killing units via End key is an edge case (#10375)
// This didn't matter pre-Arma 3 2.18 but now this goes through the event handler
// TODO: Structural fire damage >= 1 in a single damage event could still be caught here and we don't want that, but we haven't found a better way to catch this, fire damage should be small most of the time anyway
// Also triggers for catastrophic vehicle explosions which would kill crew outright, check for blocking
private _newDamage = _damage - _oldDamage;
if (_structuralDamage && {(abs (_newDamage - 1)) < 0.001 && _ammo == "" && isNull _shooter && isNull _instigator} && {INSTAKILL_ALLOWED(_unit)}) exitWith {
    TRACE_1("unit killed by curator or engine",_unit);

    _damage
};

// _newDamage == 0 happens occasionally for vehiclehit events (see line 80 onwards), just exit early to save some frametime
// context 4 is engine "bleeding". For us, it's just a duplicate event for #structural which we can ignore without any issues
// Leverage this to block insta-kills on the same frame (see above)
if (_context != 2 && {_context == 4 || _newDamage == 0}) exitWith {
    TRACE_4("Skipping engine bleeding or zero damage, blocking insta kills until next frame",_ammo,_newDamage,_directHit,_context);

    if (INSTAKILL_ALLOWED(_unit)) then {
        _unit setVariable [QACEGVAR(medical_engine,blockInstaKill), _unit];
        [{_this setVariable [QACEGVAR(medical_engine,blockInstaKill), nil]}, _unit] call CBA_fnc_execNextFrame;
    };

    _oldDamage
};

// Get armor value of hitpoint and calculate damage before armor
// We scale using passThrough to handle explosive-resistant armor properly (#9063)
// We need realDamage to determine which limb was hit correctly
[_unit, _hitpoint] call FUNC(getHitpointArmor) params ["_armor"];
private _realDamage = _newDamage * _armor;
TRACE_6("Received hit",_hitpoint,_ammo,_newDamage,_realDamage,_directHit,_context);

// Drowning doesn't fire the EH for each hitpoint so the "ace_hdbracket" code never runs
// Damage occurs in consistent increments
if (
    _structuralDamage &&
    {getOxygenRemaining _unit <= 0.5} &&
    {_damage isEqualTo (_oldDamage + 0.005)}
) exitWith {
    TRACE_5("Drowning",_unit,_shooter,_instigator,_damage,_newDamage);
    [QACEGVAR(medical,woundReceived), [_unit, [[_newDamage, "Body", _newDamage]], _unit, "drowning"]] call CBA_fnc_localEvent;

    0
};

// Faster than (vehicle _unit), also handles dead units
private _vehicle = objectParent _unit;
private _inVehicle = !isNull _vehicle;
private _environmentDamage = _ammo == "";

// Crashing a vehicle doesn't fire the EH for each hitpoint and never triggers _context=2 (LastHitPoint)
// It does fire the EH multiple times, but this seems to scale with the intensity of the crash
if (
    ACEGVAR(medical,enableVehicleCrashes) &&
    {_environmentDamage && _inVehicle && _structuralDamage} &&
    {vectorMagnitude (velocity _vehicle) > 5}
    // todo: no way to detect if stationary and another vehicle hits you
) exitWith {
    TRACE_5("Crash",_unit,_shooter,_instigator,_damage,_newDamage);
    [QACEGVAR(medical,woundReceived), [_unit, [[_newDamage, _hitPoint, _newDamage]], _unit, "vehiclecrash"]] call CBA_fnc_localEvent;

    0
};

// Receiving explosive damage inside a vehicle doesn't trigger for each hitpoint
// This is the case for mines, explosives, artillery, and catasthrophic vehicle explosions
if (
    (!_environmentDamage && _inVehicle && _structuralDamage) &&
    {
        private _ammoCfg = configFile >> "CfgAmmo" >> _ammo;
        GET_NUMBER(_ammoCfg >> "explosive",0) > 0 ||
        {GET_NUMBER(_ammoCfg >> "indirectHit",0) > 0}
    }
) exitWith {
    TRACE_5("Vehicle hit",_unit,_shooter,_instigator,_damage,_newDamage);

    _unit setVariable [QACEGVAR(medical,lastDamageSource), _shooter];
    _unit setVariable [QACEGVAR(medical,lastInstigator), _instigator];

    [QACEGVAR(medical,woundReceived), [_unit, [[_newDamage, _hitPoint, _newDamage]], _shooter, "vehiclehit"]] call CBA_fnc_localEvent;

    0
};

// Get setting for particular unit
private _multiplierArray = _unit getVariable [QGVAR(armorHash),
    GVAR(armorValueHash) getOrDefault [
        side _unit,
        GVAR(defaultArmorHash)
    ]
] getOrDefault [toLowerANSI _hitPoint, DEFAULT_SETTINGS, true];

private _modifiedNewDamage = _newDamage;

// If default settings, we don't need to change anything, so skip calculcations and let ace handle damage
TRACE_3("Premanipulation",_multiplierArray,_armor,_modifiedNewDamage);
if (_multiplierArray isNotEqualTo DEFAULT_SETTINGS) then {
    _multiplierArray params ["_hitPointTimeser", "_armorMin", "_armorMax"];

    switch (true) do {
        case (_armorMin >= 1 && {_armor < _armorMin}): {
            // This will decrease damage
            _modifiedNewDamage = _realDamage / _armorMin;

            TRACE_5("Under min armor",_armor,_armorMin,_newDamage,_modifiedNewDamage,_realDamage);
        };
        case (_armorMax >= 1 && {_armor > _armorMax}): {
            // This will increase damage
            _modifiedNewDamage = _realDamage / _armorMax;

            TRACE_5("Over max armor",_armor,_armorMax,_newDamage,_modifiedNewDamage,_realDamage);
        };
    };

    _modifiedNewDamage = _modifiedNewDamage / _hitPointTimeser;

    TRACE_4("Hitpoint damage multiplied",_armor,_newDamage,_modifiedNewDamage,_realDamage);
};
TRACE_1("Post-manipulation",_modifiedNewDamage);

// Damages are stored for last iteration of the HandleDamage event (_context == 2)
_unit setVariable [format [QACEGVAR(medical_engine,$%1), _hitPoint], [_realDamage, _modifiedNewDamage]];

// Ref https://community.bistudio.com/wiki/Arma_3:_Event_Handlers#HandleDamage
// Context 2 means this is the last iteration of HandleDamage, so figure out which hitpoint took the most real damage and send wound event
// Don't exit, as the last iteration can be one of the hitpoints that we need to keep _oldDamage for
if (_context == 2) then {
    _unit setVariable [QACEGVAR(medical,lastDamageSource), _shooter];
    _unit setVariable [QACEGVAR(medical,lastInstigator), _instigator];

    private _damageStructural = _unit getVariable [QACEGVAR(medical_engine,$#structural), [0,0,0]];

    // --- Head
    private _damageHead = [
        _unit getVariable [QACEGVAR(medical_engine,$HitFace), [0,0]],
        _unit getVariable [QACEGVAR(medical_engine,$HitNeck), [0,0]],
        _unit getVariable [QACEGVAR(medical_engine,$HitHead), [0,0]]
    ];
    _damageHead sort false;
    _damageHead = _damageHead select 0;

    // --- Body
    private _damageBody = [
        _unit getVariable [QACEGVAR(medical_engine,$HitPelvis), [0,0]],
        _unit getVariable [QACEGVAR(medical_engine,$HitAbdomen), [0,0]],
        _unit getVariable [QACEGVAR(medical_engine,$HitDiaphragm), [0,0]],
        _unit getVariable [QACEGVAR(medical_engine,$HitChest), [0,0]]
        // HitBody removed as it's a placeholder hitpoint and the high armor value (1000) throws the calculations off
    ];
    _damageBody sort false;
    _damageBody = _damageBody select 0;

    // --- Arms and Legs
    private _damageLeftArm = _unit getVariable [QACEGVAR(medical_engine,$HitLeftArm), [0,0]];
    private _damageRightArm = _unit getVariable [QACEGVAR(medical_engine,$HitRightArm), [0,0]];
    private _damageLeftLeg = _unit getVariable [QACEGVAR(medical_engine,$HitLeftLeg), [0,0]];
    private _damageRightLeg = _unit getVariable [QACEGVAR(medical_engine,$HitRightLeg), [0,0]];

    // Find hit point that received the maxium damage
    // Priority used for sorting if incoming damage is equal
    private _allDamages = [
        // Real damage,                                   Damage (with armor),                       Modified damage (with armor)
        [_damageHead select 0,       PRIORITY_HEAD,       _damageHead select 1,       "Head"],
        [_damageBody select 0,       PRIORITY_BODY,       _damageBody select 1,       "Body"],
        [_damageLeftArm select 0,    PRIORITY_LEFT_ARM,   _damageLeftArm select 1,    "LeftArm"],
        [_damageRightArm select 0,   PRIORITY_RIGHT_ARM,  _damageRightArm select 1,   "RightArm"],
        [_damageLeftLeg select 0,    PRIORITY_LEFT_LEG,   _damageLeftLeg select 1,    "LeftLeg"],
        [_damageRightLeg select 0,   PRIORITY_RIGHT_LEG,  _damageRightLeg select 1,   "RightLeg"],
        [_damageStructural select 0, PRIORITY_STRUCTURAL, _damageStructural select 1, "#structural"]
    ];
    TRACE_2("incoming",_allDamages,_damageStructural);

    _allDamages sort false;
    // Use modified damages instead of initial ones
    _allDamages = _allDamages apply {[_x select 2, _x select 3, _x select 0]};

    // Environmental damage sources all have empty ammo string
    // No explicit source given, we infer from differences between them
    if (_environmentDamage) then {
        // Any collision with terrain/vehicle/object has a shooter
        // Check this first because burning can happen at any velocity
        if (isNull _shooter) then {
            // Anything else is almost guaranteed to be fire damage
            _ammo = "fire";
            TRACE_5("Fire Damage",_unit,_shooter,_instigator,_damage,_allDamages);
        } else {
            /*
              If shooter != unit then they hit unit, otherwise it could be:
               - Unit hitting anything at speed
               - An empty vehicle hitting unit
               - A physX object hitting unit
               Assume fall damage for downward velocity because it's most common
            */
            if (_shooter == _unit && {(velocity _unit select 2) < -2}) then {
                _ammo = "falling";
                TRACE_5("Fall",_unit,_shooter,_instigator,_damage,_allDamages);
            } else {
                _ammo = "collision";
                TRACE_5("Collision",_unit,_shooter,_instigator,_damage,_allDamages);
            };
        };
    };

    // No wounds for minor damage
    // TODO check if this needs to be changed for burning damage (occurs as lots of small events that we add together)
    if ((_allDamages select 0 select 0) > 1E-3) then {
        TRACE_1("received",_allDamages);
        [QACEGVAR(medical,woundReceived), [_unit, _allDamages, _shooter, _ammo]] call CBA_fnc_localEvent;
    };

    // Clear stored damages otherwise they will influence future damage events
    // (aka wounds will pile onto the historically most damaged hitpoint)
    {
        _unit setVariable [_x, nil];
    } forEach [
        QACEGVAR(medical_engine,$HitFace),QACEGVAR(medical_engine,$HitNeck),QACEGVAR(medical_engine,$HitHead),
        QACEGVAR(medical_engine,$HitPelvis),QACEGVAR(medical_engine,$HitAbdomen),QACEGVAR(medical_engine,$HitDiaphragm),QACEGVAR(medical_engine,$HitChest),QACEGVAR(medical_engine,$HitBody),
        QACEGVAR(medical_engine,$HitLeftArm),QACEGVAR(medical_engine,$HitRightArm),QACEGVAR(medical_engine,$HitLeftLeg),QACEGVAR(medical_engine,$HitRightLeg),
        QACEGVAR(medical_engine,$#structural)
    ];
};

// Engine damage to these hitpoints controls blood visuals, limping, weapon sway
// Handled in fnc_damageBodyPart, persist here
// For all other hitpoints, we store our own damage values, so engine damage is unnecessary
[0, _oldDamage] select (_hitPoint in ["hithead", "hitbody", "hithands", "hitlegs"])
