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
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
if (!GVAR(usePotato)) exitWith { LOG("asignGearMan disabled"); };

params ["_unit"];
TRACE_2("",_unit,local _unit);

#ifdef DEBUG_MODE_FULL
    private _startTime = diag_tickTime; // only define counter if debug mode is on
#endif

private _faction = toLower faction _unit;
private _unitClassname = [typeOf _unit] call FUNC(cleanPrefix);
private _loadout = _unit getVariable ["F_Gear", _unitClassname]; //Check variable f_gear, otherwise default to typeof
private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if ((!isClass(_path)) && GVAR(useFallback)) then {
    _path = missionConfigFile >> "CfgLoadouts" >> _faction >> "fallback";
};

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
    TRACE_1("loadout array: ", _loadoutArray);
    GVAR(loadoutCache) setVariable [_loadoutKey, _loadoutArray];
};

_unit setUnitLoadout _loadoutArray;

if (isText (_path >> "init")) then {
    TRACE_1("calling init code",getText (_path >> "init"));
    _unit call compile ("this = _this;"+ getText (_path >> "init"));
};

_unit setVariable [QGVAR(gearSetup), true, true];
_unit setVariable ["F_Gear_Setup", true, true]; //TODO: legacy variable sync for radios, remove eventually

#ifdef DEBUG_MODE_FULL
    private _runTime = diag_tickTime - _startTime;

    if (isNil QGVAR(agmRunCount)) then {
        GVAR(agmRunCount) = 0;
        GVAR(agmRunTime) = 0;
    };

    INC(GVAR(agmRunCount));
    GVAR(agmRunTime) = GVAR(agmRunTime) + _runTime;
    diag_log format ["[POTATO-assignGear] - assignGearMan ran for class %1, with a run time of %2", _loadout, _runTime];
    diag_log format ["[POTATO-assignGear] - assignGearMan ran %1 times, with an average run time of %2", GVAR(agmRunCount), GVAR(agmRunTime) / GVAR(agmRunCount)];
#endif
