/*
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_paramsStrings", "", ["", true]]];
if (isNil "_ctrlGroup" && !isServer) exitWith { LOG("Skip settings running on clients"); };
if (_paramsStrings isEqualType true && {_paramsStrings}) exitWith { LOG("Briefing setting data not set, or in strange state, exiting early"); };

systemChat format ["%1", potato_briefing_brief_addCredits];
systemChat format ["%1", missionNamespace getVariable "potato_briefing_brief_addCredits"];

private _paramsArray = _paramsStrings splitString ",";
missionNamespace setVariable [QGVAR(brief_addCredits), [_paramsArray select 0] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(brief_addOrbat), [_paramsArray select 1] call CFUNC(parseBool), true];

systemChat format ["%1", potato_briefing_brief_addCredits];
systemChat format ["%1", missionNamespace getVariable "potato_briefing_brief_addCredits"];

if !(isNil "_ctrlGroup") then {
    [_ctrlGroup] call FUNC(briefingSettingsSetControlsFromGVars);
};
