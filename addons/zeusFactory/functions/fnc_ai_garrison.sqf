#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];

TRACE_3("ai_garrison",_leader,_group,_radius);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

//Todo tweak defend garrison ratio: https://github.com/CBATeam/CBA_A3/pull/573/
[_group, getPos _leader, _radius] call CBA_fnc_taskDefend;
