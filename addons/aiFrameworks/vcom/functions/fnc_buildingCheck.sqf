#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

_unit setVariable [VQGVAR(isInside), [_unit] call VFUNC(inBuilding)];
