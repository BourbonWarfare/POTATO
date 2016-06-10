#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

if (!(_unit getVariable [VQGVAR(inCover),true])
        || {!([_unit,VQGVAR(movedRecently),VGVAR(movedRecentlyThreshold)] call VFUNC(pastThreshold))}
        || {isNull _nearestEnemy}
        || {!(alive _nearestEnemy)}) exitWith {};

private _distance = abs (_nearestEnemy distance _unit);
if (_distance > VGVAR(maxThreatDistance)) exitWith {};

private _intersections = lineIntersectsSurfaces [eyePos _unit, eyepos _nearestEnemy, _unit, _nearestEnemy, true, 1];

if ((count _intersections) == 0 && (_distance < VGVAR(maxEngagementDistance))) then {
    _unit setVariable [VQGVAR(canVisuallySee),true];
    _unit forceSpeed 0;
    _unit setUnitPos "AUTO";
    _unit suppressFor 5;
} else {
    _unit setVariable [VQGVAR(canVisuallySee),false];
};
