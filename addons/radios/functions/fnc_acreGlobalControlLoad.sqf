/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

[_ctrlGroup] call FUNC(acreGlobalSetControlsFromGVars);
