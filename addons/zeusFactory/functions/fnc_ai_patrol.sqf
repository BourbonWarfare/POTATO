#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];

TRACE_3("ai_patrol",_leader,_group,_radius);

[_group, getPos _leader, _radius] call CBA_fnc_taskPatrol;
