#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

[_unit] call VFUNC(defaultSetup);
[_unit] call VFUNC(startBrain);
