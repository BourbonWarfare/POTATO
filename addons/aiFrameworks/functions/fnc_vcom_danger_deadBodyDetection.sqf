#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if !([_unit,VQGVAR(lastDeadBodyCheck),VGVAR(deadBodyCheckThreshold)] call VFUNC(pastThreshold)) exitWith { false };

private _closestDead = [allDeadMen, _unit] call VFUNC(closestObject);
if (isNull _closestDead) exitWith { false };

(_closestDead distance _unit) <= VGVAR(deadBodyDetectionRange)
