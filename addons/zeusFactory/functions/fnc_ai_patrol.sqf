#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];
private _attackTarget = _group getVariable [QGVAR(attackTarget), true];
private _useLAMBS = _group getVariable [QGVAR(useLAMBS), true];

TRACE_5("ai_patrol",_leader,_group,_radius,_attackTarget,_useLAMBS);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

private _positionToPatrol = getPos _leader;
if (_attackTarget) then {
	private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
	if !(isNull _currentBeacon) then {
		_positionToPatrol = _currentBeacon;
	} else {
		WARNING_1("No Beacons [%1]",_currentBeacon);
	};
};

if (_useLAMBS) then {
	[_group, _positionToPatrol, _radius] call lambs_wp_fnc_taskPatrol;
} else {
	[_group, _positionToPatrol, _radius] call CBA_fnc_taskPatrol;
};
