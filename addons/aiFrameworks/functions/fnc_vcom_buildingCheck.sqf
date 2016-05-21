#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (!([_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold))
        || {!([_unit,VQGVAR(clearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold))}
        || {_unit getVariable [VQGVAR(startedInside),false]}) exitWith { false };

private _enemy = [_unit] call VFUNC(closestEnemy);
if (isNull _enemy) exitWith { false };
if ((typeName _enemy) isEqualType []) exitWith { false };

[_enemy] call VFUNC(inBuilding)
