/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_paramsStrings", "", ["",true]]];
if (_paramsStrings isEqualType true && {_paramsStrings}) exitWith { LOG("ACRE global data not set, or in strange state, exiting early"); };

[_paramsStrings] call FUNC(acreGlobalSetGVarsFromString);
[_ctrlGroup] call FUNC(acreGlobalSetControlsFromGVars);
