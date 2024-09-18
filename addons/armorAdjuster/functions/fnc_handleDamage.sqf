#include "..\script_component.hpp"

/*
 * Author: commy2, kymckay, modified by johnb43 & Lambda.Tiger
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

params ["_args", ["_ignoreAllowDamageACE", false]];
_args params ["_unit", "_selection", "_damage", "_shooter", "_ammo", "_hitPointIndex", "_instigator", "_hitpoint", "_directHit", "_context"];

// HD sometimes triggers for remote units - ignore.
if !(local _unit) exitWith {nil};

// Get missing meta info
private _oldDamage = 0;
private _structuralDamage = _context == 0;

if (_hitPoint isEqualTo "") then {
    _hitPoint = "#structural";
    _oldDamage = damage _unit;
} else {
    _oldDamage = _unit getHitIndex _hitPointIndex;
};

// Damage can be disabled with old variable or via sqf command allowDamage
if !(isDamageAllowed _unit && {_unit getVariable ["ace_medical_allowDamage", true] || _ignoreAllowDamageACE}) exitWith {_oldDamage};

private _newDamage = _damage - _oldDamage;

// _newDamage == 0 happens occasionally for vehiclehit events (see line 80 onwards), just exit early to save some frametime
// context 4 is engine "bleeding". For us, it's just a duplicate event for #structural which we can ignore without any issues
if (_context != 2 && {_context == 4 || _newDamage == 0}) exitWith {
    TRACE_4("Skipping engine bleeding or zero damage",_ammo,_newDamage,_directHit,_context);
    _oldDamage
};

// Get scaled armor value of hitpoint and calculate damage before armor
// We scale using passThrough to handle explosive-resistant armor properly (#9063)
// We need realDamage to determine which limb was hit correctly
[_unit, _hitpoint] call ace_medical_engine_fnc_getHitpointArmor params ["_armor", "_armorScaled"];
private _realDamage = _newDamage * _armor;
if (!_structuralDamage) then {
    private _armorCoef = _armor/_armorScaled;
    private _damageCoef = linearConversion [0, 1, ace_medical_engine_damagePassThroughEffect, 1, _armorCoef];
    _newDamage = _newDamage * _damageCoef;
};
TRACE_6("Received hit",_hitpoint,_ammo,_newDamage,_realDamage,_directHit,_context);

// Drowning doesn't fire the EH for each hitpoint so the "ace_hdbracket" code never runs
// Damage occurs in consistent increments
if (
    _structuralDamage &&
    {getOxygenRemaining _unit <= 0.5} &&
    {_damage isEqualTo (_oldDamage + 0.005)}
) exitWith {
    TRACE_5("Drowning",_unit,_shooter,_instigator,_damage,_newDamage);
    ["ace_medical_woundReceived", [_unit, [[_newDamage, "Body", _newDamage]], _unit, "drowning"]] call CBA_fnc_localEvent;

    0
};

// Faster than (vehicle _unit), also handles dead units
private _vehicle = objectParent _unit;
private _inVehicle = !isNull _vehicle;
private _environmentDamage = _ammo == "";

// Crashing a vehicle doesn't fire the EH for each hitpoint so the "ace_hdbracket" code never runs
// It does fire the EH multiple times, but this seems to scale with the intensity of the crash
if (
    ace_medical_enableVehicleCrashes &&
    {_environmentDamage && _inVehicle && _structuralDamage} &&
    {vectorMagnitude (velocity _vehicle) > 5}
    // todo: no way to detect if stationary and another vehicle hits you
) exitWith {
    TRACE_5("Crash",_unit,_shooter,_instigator,_damage,_newDamage);
    ["ace_medical_woundReceived", [_unit, [[_newDamage, _hitPoint, _newDamage]], _unit, "vehiclecrash"]] call CBA_fnc_localEvent;

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

    _unit setVariable ["ace_medical_lastDamageSource", _shooter];
    _unit setVariable ["ace_medical_lastInstigator", _instigator];

    ["ace_medical_woundReceived", [_unit, [[_newDamage, _hitPoint, _newDamage]], _shooter, "vehiclehit"]] call CBA_fnc_localEvent;

    0
};

// Get setting for particular unit
// I don't think we truely need 3 methods avaiable, I would rather choose two 2
private _multiplierArray = _unit getVariable [QGVAR(armorHash),
    GVAR(armorValueHash) getOrDefault [
        side _unit,
        GVAR(defaultArmorHash)
    ]
] getOrDefault [_hitPoint, DEFAULT_SETTINGS, true];

private _modifiedNewDamage = _newDamage;
private _modifiedRealDamage = _realDamage;

// If default settings, we don't need to change anything, so skip calculcations and let ace handle damage
if (_multiplierArray isNotEqualTo DEFAULT_SETTINGS) then {
    _multiplierArray params ["_hitPointTimeser", "_armorMin", "_armorMax"];

    switch (true) do {
        case (_armorMin >= 1 && {_armor < _armorMin}): {
            // This will decrease damage
            _modifiedNewDamage = _newDamage * _armor / _armorMin;
            _modifiedRealDamage = _realDamage * _armor / _armorMin;

            TRACE_6("Under min armor",_armor,_armorMin,_newDamage,_modifiedNewDamage,_realDamage,_modifiedRealDamage);
        };
        case (_armorMax >= 1 && {_armor > _armorMax}): {
            // This will increase damage
            _modifiedNewDamage = _newDamage * _armor / _armorMax;
            _modifiedRealDamage = _realDamage * _armor / _armorMax;

            TRACE_6("Over max armor",_armor,_armorMax,_newDamage,_modifiedNewDamage,_realDamage,_modifiedRealDamage);
        };
    };

    _modifiedNewDamage = _modifiedNewDamage / _hitPointTimeser;
    _modifiedRealDamage = _modifiedRealDamage / _hitPointTimeser;

    TRACE_5("Hitpoint damage multiplied",_armor,_newDamage,_modifiedNewDamage,_realDamage,_modifiedRealDamage);
};

// Damages are stored for last iteration of the HandleDamage event (_context == 2)
_unit setVariable [format ["ace_medical_engine_$%1", _hitPoint], [_realDamage, _newDamage, _modifiedRealDamage, _modifiedNewDamage]];

// Ref https://community.bistudio.com/wiki/Arma_3:_Event_Handlers#HandleDamage
// Context 2 means this is the last iteration of HandleDamage, so figure out which hitpoint took the most real damage and send wound event
// Don't exit, as the last iteration can be one of the hitpoints that we need to keep _oldDamage for
if (_context == 2) then {
    _unit setVariable ["ace_medical_lastDamageSource", _shooter];
    _unit setVariable ["ace_medical_lastInstigator", _instigator];

    private _damageStructural = _unit getVariable ["ace_medical_engine_$#structural", [0,0,0,0]];

    // --- Head
    private _damageHead = [
        _unit getVariable ["ace_medical_engine_$HitFace", [0,0,0,0]],
        _unit getVariable ["ace_medical_engine_$HitNeck", [0,0,0,0]],
        _unit getVariable ["ace_medical_engine_$HitHead", [0,0,0,0]]
    ];
    _damageHead sort false;
    _damageHead = _damageHead select 0;

    // --- Body
    private _damageBody = [
        _unit getVariable ["ace_medical_engine_$HitPelvis", [0,0,0,0]],
        _unit getVariable ["ace_medical_engine_$HitAbdomen", [0,0,0,0]],
        _unit getVariable ["ace_medical_engine_$HitDiaphragm", [0,0,0,0]],
        _unit getVariable ["ace_medical_engine_$HitChest", [0,0,0,0]]
        // HitBody removed as it's a placeholder hitpoint and the high armor value (1000) throws the calculations off
    ];
    _damageBody sort false;
    _damageBody = _damageBody select 0;

    // --- Arms and Legs
    private _damageLeftArm = _unit getVariable ["ace_medical_engine_$HitLeftArm", [0,0,0,0]];
    private _damageRightArm = _unit getVariable ["ace_medical_engine_$HitRightArm", [0,0,0,0]];
    private _damageLeftLeg = _unit getVariable ["ace_medical_engine_$HitLeftLeg", [0,0,0,0]];
    private _damageRightLeg = _unit getVariable ["ace_medical_engine_$HitRightLeg", [0,0,0,0]];

    // Find hit point that received the maxium damage
    // Priority used for sorting if incoming damage is equal
    private _allDamages = [
        // Real damage (ignoring armor),                  Actual damage (with armor),                Real damage modified (ignoring armor),                     Modified damage (with armor)
        [_damageHead select 0,       PRIORITY_HEAD,       _damageHead select 1,       "Head",        _damageHead param [2, _damageHead select 0],               _damageHead param [3, _damageHead select 1]],
        [_damageBody select 0,       PRIORITY_BODY,       _damageBody select 1,       "Body",        _damageBody param [2, _damageBody select 0],               _damageBody param [3, _damageBody select 1]],
        [_damageLeftArm select 0,    PRIORITY_LEFT_ARM,   _damageLeftArm select 1,    "LeftArm",     _damageLeftArm param [2, _damageLeftArm select 0],         _damageLeftArm param [3, _damageLeftArm select 1]],
        [_damageRightArm select 0,   PRIORITY_RIGHT_ARM,  _damageRightArm select 1,   "RightArm",    _damageRightArm param [2, _damageRightArm select 0],       _damageRightArm param [3, _damageRightArm select 1]],
        [_damageLeftLeg select 0,    PRIORITY_LEFT_LEG,   _damageLeftLeg select 1,    "LeftLeg",     _damageLeftLeg param [2, _damageLeftLeg select 0],         _damageLeftLeg param [3, _damageLeftLeg select 1]],
        [_damageRightLeg select 0,   PRIORITY_RIGHT_LEG,  _damageRightLeg select 1,   "RightLeg",    _damageRightLeg param [2, _damageRightLeg select 0],       _damageRightLeg param [3, _damageRightLeg select 1]],
        [_damageStructural select 0, PRIORITY_STRUCTURAL, _damageStructural select 1, "#structural", _damageStructural param [2, _damageStructural select 0],   _damageStructural param [3, _damageStructural select 1]]
    ];
    TRACE_2("incoming",_allDamages,_damageStructural);

    _allDamages sort false;
    // Use modified damages instead of initial ones
    _allDamages = _allDamages apply {[_x select 5, _x select 3, _x select 4]};

    // Environmental damage sources all have empty ammo string
    // No explicit source given, we infer from differences between them
    if (_environmentDamage) then {
        // Any collision with terrain/vehicle/object has a shooter
        // Check this first because burning can happen at any velocity
        if !(isNull _shooter) then {
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
        } else {
            // Anything else is almost guaranteed to be fire damage
            _ammo = "fire";
            TRACE_5("Fire Damage",_unit,_shooter,_instigator,_damage,_allDamages);
        };
    };

    // No wounds for minor damage
    // TODO check if this needs to be changed for burning damage (occurs as lots of small events that we add together)
    if ((_allDamages select 0 select 0) > 1E-3) then {
        TRACE_1("received",_allDamages);
        ["ace_medical_woundReceived", [_unit, _allDamages, _shooter, _ammo]] call CBA_fnc_localEvent;
    };

    // Clear stored damages otherwise they will influence future damage events
    // (aka wounds will pile onto the historically most damaged hitpoint)
    {
        _unit setVariable [_x, nil];
    } forEach [
        "ace_medical_engine_$HitFace","ace_medical_engine_$HitNeck","ace_medical_engine_$HitHead",
        "ace_medical_engine_$HitPelvis","ace_medical_engine_$HitAbdomen","ace_medical_engine_$HitDiaphragm","ace_medical_engine_$HitChest","ace_medical_engine_$HitBody",
        "ace_medical_engine_$HitLeftArm","ace_medical_engine_$HitRightArm","ace_medical_engine_$HitLeftLeg","ace_medical_engine_$HitRightLeg",
        "ace_medical_engine_$#structural"
    ];
};

// Engine damage to these hitpoints controls blood visuals, limping, weapon sway
// Handled in fnc_damageBodyPart, persist here
// For all other hitpoints, we store our own damage values, so engine damage is unnecessary
[0, _oldDamage] select (_hitPoint in ["hithead", "hitbody", "hithands", "hitlegs"])
