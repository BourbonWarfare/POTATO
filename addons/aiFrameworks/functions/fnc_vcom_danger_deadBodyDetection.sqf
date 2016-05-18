#include "script_component.hpp"
TRACE_1("params",_this);

private ["_ClosestDead"];

//AllDeadMen because, you know, WOMEN DONT EXIST IN THIS GAME... -_-
_ClosestDead = [allDeadMen,_this] call VCOMAI_ClosestObject;
if (isNil ("_ClosestDead")) then {_ClosestDead = [0,0,0];};
_ClosestDead
