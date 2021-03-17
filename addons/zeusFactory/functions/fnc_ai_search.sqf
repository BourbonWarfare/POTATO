#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];
private _attackTarget = _group getVariable [QGVAR(attackTarget), true];
private _useLAMBS = _group getVariable [QGVAR(useLAMBS), true];

TRACE_5("ai_search",_leader,_group,_radius,_attackTarget,_useLAMBS);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

private _positionToSearch = getPos _leader;
if (_attackTarget) then {
	private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
    if !(isNull _currentBeacon) then {
		_positionToSearch = _currentBeacon;
    } else {
		WARNING_1("No Beacons [%1]",_currentBeacon);
	};
};

if (_useLAMBS) then {
	[_group, _positionToSearch, _radius] spawn lambs_wp_fnc_taskCQB;
} else {
	[_group, [getPos _positionToSearch, _radius, _radius, 0, false]] call CBA_fnc_taskSearchArea;
}

