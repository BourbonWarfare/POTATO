/*
 * Author: AACO
 * Function used to read the stored briefing settings and display them to the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the briefing component <CONTROL>
 * 1: The stored settings <STRING>
 *
 * Examples:
 * [_ctrlGroup, "true,true"] call potato_briefing_fnc_briefingSettingsAttributeLoad;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_paramsStrings", "", ["", true]]];
if (isNil "_ctrlGroup" && !isServer) exitWith { LOG("Skip settings running on clients"); };
if (_paramsStrings isEqualType true && {_paramsStrings}) exitWith { LOG("Briefing setting data not set, or in strange state, exiting early"); };

private _paramsArray = _paramsStrings splitString ",";
missionNamespace setVariable [QGVAR(brief_addCredits), [_paramsArray select 0] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(brief_addOrbat), [_paramsArray select 1] call CFUNC(parseBool), true];

if !(isNil "_ctrlGroup") then {
    [_ctrlGroup] call FUNC(briefingSettingsSetControlsFromGVars);
};
