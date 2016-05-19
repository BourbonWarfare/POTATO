#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

//AllDeadMen because, you know, WOMEN DONT EXIST IN THIS GAME... -_-
private _closestDead = [allDeadMen, _unit] call VFUNC(closestObject);
if (isNull _closestDead) then { _closestDead = [0,0,0]; };
_closestDead
