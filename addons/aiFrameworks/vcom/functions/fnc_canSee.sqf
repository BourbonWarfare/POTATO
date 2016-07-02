#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

if (isNull _unit || isNull _nearestEnemy) exitWith { false };

private _intersections = lineIntersectsSurfaces [eyePos _unit, eyePos _nearestEnemy, _unit, _nearestEnemy];

count _intersections < 1
