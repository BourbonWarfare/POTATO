/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (!isServer) exitWith {};

params ["_ctrlGroup",["_paramsStrings", [], [[],true]]];
if (_paramsStrings isEqualType true && {_paramsStrings}) exitWith { LOG("data not set, or in strange state, exiting early"); };

[_paramsStrings] call FUNC(acreSideSetGVarsFromString);
