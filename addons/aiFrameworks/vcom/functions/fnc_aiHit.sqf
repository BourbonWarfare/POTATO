#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (isPlayer _unit || {(vehicle _unit) != _unit}) exitWith {};

//Lay down
_unit setUnitPos "DOWN";
[_unit] spawn VFUNC(moveToCover);
