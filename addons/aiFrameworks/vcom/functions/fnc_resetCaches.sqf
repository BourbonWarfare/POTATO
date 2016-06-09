#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

// (re)set cached defaults
_unit setVariable [VQGVAR(cachedNearestEnemy),objNull];
