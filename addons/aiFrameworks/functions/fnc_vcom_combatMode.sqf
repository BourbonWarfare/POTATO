#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"]

//VCOMAI_CombatMode
private _timeShot = _unit getVariable [VQGVAR(firedTime), 0];

private _nearestEnemy = [_unit] call VFUNC(closestEnemy);

if ((diag_tickTime - _timeShot) > 60 && ((_nearestEnemy distance _unit) > 1000 || {isNull _nearestEnemy})) then {
	_unit setBehaviour (_unit getVariable [VQGVAR(lastStance), behaviour _unit]);
};
