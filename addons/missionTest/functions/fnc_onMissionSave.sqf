#include "script_component.hpp"

diag_log text "";
diag_log text "[POTATO] Saving - Doing mission test:";
diag_log text "------------------------------------------------------";

private _allMissionObjects = (all3DENEntities select 0);
private _allUnits = _allMissionObjects select {_x isKindOf "CaManBase"};
INFO_2("Placed on mission: [Units: %1] [Non-unit Objects: %2]", count _allUnits, (count _allMissionObjects) - (count _allUnits));

private _bwmfDate = getText (missionConfigFile >> "bwmfDate");
if (_bwmfDate == "") exitWith {
    systemChat "Non-framework mission (missing description.ext?)";
    WARNING("Non-framework mission (missing description.ext?)");
};
if (!(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false])) exitWith {
    systemChat "Potato Gear is off (missing description.ext?)";
    WARNING("Potato Gear is off (missing description.ext?)");
};


private _problems = [];

// Floating units / Fall Damage:
private _floatingUnits = [];
{
    if (((getPos _x) select 2) > 0.5) then {
        WARNING_3("[%1:%2] is floating %3", _x, typeOf _x, getPos _x);
        _floatingUnits pushBack _x;
    };
} forEach _allUnits;
if (!(_floatingUnits isEqualTo [])) then {
    _problems pushBack ["Possible Fall Damage (Soldier placed above ground level)", _floatingUnits];
};


// Verify loadouts exist for all units:
private _classesFallback = [];
private _classesNone= [];
{
    private _faction = toLower faction _x;
    private _unitClassname = [typeOf _x] call EFUNC(assignGear,cleanPrefix);
    private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _unitClassname;

    if ((!isClass(_path)) && EGVAR(assignGear,useFallback)) then {
        _path = missionConfigFile >> "CfgLoadouts" >> _faction >> "fallback";
        if (isClass _path) then {
            WARNING_1("[%1] is using fallback", typeOf _x);
            _classesFallback pushBackUnique (typeOf _x);
        } else {
            WARNING_1("[%1] is has no fallback", typeOf _x);
            _classesNone pushBackUnique (typeOf _x);
        };
    };
    if (!isClass(_path)) exitWith {};
} forEach _allUnits;
if (!(_classesFallback isEqualTo [])) then {
    _problems pushBack ["Minor: Unit placed that are using fallback", _classesFallback];
};
if (!(_classesNone isEqualTo [])) then {
    _problems pushBack ["Unit placed that have no loadout", _classesNone];
};


// Verify units have weapons:
private _checkWeapons = [];
private _checkMagazines = [];
{
    private _unit = _x;
    if ((side _unit) != civilian) then {
        if ((primaryWeapon _unit) == "") then {
            if ((typeOf _unit) == "potato_msv_pol") exitWith {};
            WARNING_1("[%1] has no rifle", typeOf _unit);
            _checkWeapons pushBackUnique (typeOf _unit);
        };
        {
            private _weapon = _x;
            if (_x != "") then {
                private _ammoCount = 0;
                private _weaponMags = (getArray (configFile >> "cfgWeapons" >> _weapon >> "magazines")) apply {toLower _x};
                {
                    _x params ["_xMagName", "_xAmmo"];
                    if ((toLower _xMagName) in _weaponMags) then {
                        _ammoCount = _ammoCount + _xAmmo;
                    };
                } forEach (magazinesAmmoFull _unit);
                if (_ammoCount == 0) then {
                    if ((toLower _weapon) in ["rhs_weap_rpg26", "rhs_weap_m136", "launch_nlaw_f"]) then {
                        // TRACE_1("ignoring special AT reloads",_weapon);
                    } else {
                        WARNING_2("[%1]'s %2 has zero ammo", typeOf _unit, _weapon);
                        _checkMagazines pushBackUnique (typeOf _unit);
                    };
                };
                if (_weapon == (primaryWeapon _unit)) then {
                    private _desiredAmmo = switch (true) do {
                    case (((toLower typeOf _unit) find "marksman") > 0);
                    case (((toLower typeOf _unit) find "spotter") > 0);
                    case (((toLower typeOf _unit) find "sniper") > 0): { 10 };
                    case (((toLower typeOf _unit) find "_ar") > 0);
                    case (((toLower typeOf _unit) find "_mg") > 0): { 250 };
                        default { 100 };
                    };
                    if (_ammoCount <= _desiredAmmo) then {
                        WARNING_4("[%1]'s %2 has limited rifle ammo [%3/%4]", typeOf _unit, _weapon, _ammoCount, _desiredAmmo);
                        _checkMagazines pushBackUnique (typeOf _unit);
                    };
                };
            };
        } forEach [primaryWeapon _x, secondaryWeapon _x, handgunWeapon _x];
    };
} forEach _allUnits;
if (!(_checkWeapons isEqualTo [])) then {
    _problems pushBack ["Units with no rifle (primaryWeapon)", _checkWeapons];
};
if (!(_checkMagazines isEqualTo [])) then {
    _problems pushBack ["Units with magazine problems", _checkMagazines];
};


systemChat "Mission test results::";
if (_problems isEqualTo []) then {
    private _msg = "No Problems Detected!";
    systemChat _msg;
    [_msg] call BIS_fnc_3DENNotification;
} else {
    [_problems] spawn {
        params ["_problems"];
        disableSerialization;
        {
            private _msg =  format ["[%1/%2] %3", (_forEachIndex + 1), count _problems, _x];
            systemChat _msg;
            [_msg] call BIS_fnc_3DENNotification;
            uiSleep 1.5;
        } forEach _problems;
    };
};

TRACE_1("",_problems);
INFO_1("Finished test with %1 problems", count _problems);
nil
