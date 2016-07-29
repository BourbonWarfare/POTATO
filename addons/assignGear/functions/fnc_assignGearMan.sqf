/*
 * Author: PabstMirror
 * Applies a loadout to a unit
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player] call potato_assignGear_fnc_assignGearMan;
 */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("params",_this);
if (!GVAR(usePotato)) exitWith {TRACE_1("disabled",GVAR(usePotato))};

params ["_unit"];
TRACE_2("",_unit,local _unit);

// if (!local _unit) exitWith {};

private _startTime = diag_tickTime;

private _faction = toLower faction _unit;
private _unitClassname = typeOf _unit;
//Check variable f_gear, otherwise default to typeof
private _loadout = _unit getVariable ["F_Gear", _unitClassname];
private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if ((!isClass(_path)) && GVAR(useFallback)) then {
    _path = missionConfigFile >> "CfgLoadouts" >> _faction >> "fallback";
};

// diag_log text format ["[POTATO-assignGear] Gear values: { _unit: %1, _faction: %2, _unitClassname: %3, _loadout: %4, _path: %5  }", _unit, _faction, _unitClassname, _loadout, _path];

if (!isClass(_path)) exitWith {
    TRACE_2("No Class Found",_unit,typeOf _unit);

    //TODO: legacy variable sync for radios, remove eventually
    _unit setVariable ["F_Gear_Setup", true, true];

    // send event to the system where the owner is local
    if (isPlayer _unit) then {
        [QGVAR(gearAssigned), [], _unit] call CBA_fnc_targetEvent;
    };
};

private _randomIndex = floor (random GVAR(maxRandomization));
private _loadoutKey = format ["%1:%2", _path, _randomIndex];

private _loadoutArray = GVAR(loadoutCache) getVariable _loadoutKey;

if (isNil "_loadoutArray") then {
    TRACE_1("compiling new",_loadoutKey);
    _loadoutArray = [_path] call FUNC(getLoadoutFromConfig);
    GVAR(loadoutCache) setVariable [_loadoutKey, _loadoutArray];
};

_unit setUnitLoadout _loadoutArray;

if (isText (_path >> "init")) then {
    TRACE_1("calling init code",getText (_path >> "init"));
    _unit call compile ("this = _this;"+ getText (_path >> "init"));
};

//TODO: legacy variable sync for radios, remove eventually
_unit setVariable ["F_Gear_Setup", true, true];

// send event to the system where the owner is local
if (isPlayer _unit) then {
    TRACE_1("Sending targetEvent",_unit);
    [QGVAR(gearAssigned), [], _unit] call CBA_fnc_targetEvent;
};

TRACE_2("done",_unit,(diag_tickTime - _startTime));
