#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];
private _attackTarget = _group getVariable [QGVAR(attackTarget), true];
private _useLAMBS = _group getVariable [QGVAR(useLAMBS), true];

TRACE_5("ai_attack",_leader,_group,_radius,_attackTarget,_attackTarget,_useLAMBS);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

if !(_attackTarget) then {
    // if we don't want to attack a target, search the area instead.
    this call FUNC(ai_search);
} else {
    private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
    if (isNull _currentBeacon) exitWith {
        WARNING_1("No Beacons [%1]",_currentBeacon);
    };

    if (_useLAMBS) then {
        [_group, _currentBeacon getPos [_radius, random 360]] spawn lambs_wp_fnc_taskAssault;
    } else {
        [_group, _currentBeacon, _radius, "SAD", "AWARE", "RED", "NORMAL", "LINE"] call CBA_fnc_addWaypoint;
    }
};
