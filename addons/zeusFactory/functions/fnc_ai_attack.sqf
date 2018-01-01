#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];

TRACE_3("ai_attack",_leader,_group,_radius);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
if (isNull _currentBeacon) exitWith {
    WARNING_1("No Becacons [%1]",_currentBeacon);
};

[_group, _currentBeacon, _radius, "SAD", "AWARE", "RED", "NORMAL", "LINE"] call CBA_fnc_addWaypoint;
