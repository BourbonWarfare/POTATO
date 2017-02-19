#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];

TRACE_3("ai_attack",_leader,_group,_radius);

private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
if (isNull _currentBeacon) exitWith {
    WARNING_1("No Becacons [%1]",_currentBeacon);
};

[_group, _currentBeacon, _radius, "SAD", "AWARE", "RED", "NORMAL", "LINE"] call CBA_fnc_addWaypoint;
