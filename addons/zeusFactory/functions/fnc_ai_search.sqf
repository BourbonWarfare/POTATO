#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];

TRACE_3("ai_search",_leader,_group,_radius);

[_group, [(getPos _leader), _radius, _radius, 0, false]] call CBA_fnc_taskSearchArea;
