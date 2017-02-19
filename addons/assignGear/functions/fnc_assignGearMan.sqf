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
    _unit setVariable [QGVAR(gearSetup), true, true];
    _unit setVariable ["F_Gear_Setup", true, true]; //TODO: legacy variable sync for radios, remove eventually
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

_w = (parseNumber ([_unit] call ace_movement_fnc_getWeight));
if ((_w > 35) && (_w < 40)) then {
    diag_log format ["[SCMF] Heavy loadout found %1 (%2 - %3)", _unit, (typeof _unit), ([_unit] call ace_movement_fnc_getWeight)];
    systemChat format ["Heavy loadout found %1 (%2 - %3)", _unit, (typeof _unit), ([_unit] call ace_movement_fnc_getWeight)];
};
if (_w > 40) then {
    diag_log format ["[SCMF] Loadout too heavy for %1 (%2 - %3)", _unit, (typeof _unit), ([_unit] call ace_movement_fnc_getWeight)];
    systemChat format ["Loadout too heavy for %1 (%2 - %3)", _unit, (typeof _unit), ([_unit] call ace_movement_fnc_getWeight)];
};


_unit setVariable [QGVAR(gearSetup), true, true];
_unit setVariable ["F_Gear_Setup", true, true]; //TODO: legacy variable sync for radios, remove eventually


TRACE_2("done",_unit,(diag_tickTime - _startTime));
