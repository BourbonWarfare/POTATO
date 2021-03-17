#include "script_component.hpp"

params ["_leader"];

private _group = group _leader;
private _radius = _group getVariable [QGVAR(radius), 200];
private _attackTarget = _group getVariable [QGVAR(attackTarget), true];
private _useLAMBS = _group getVariable [QGVAR(useLAMBS), true];

TRACE_5("ai_garrison",_leader,_group,_radius,_attackTarget,_useLAMBS);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

private _positionToGarrison = getPos _leader;
if (_attackTarget) then {
	private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
    if !(isNull _currentBeacon) then {
		_positionToGarrison = _currentBeacon;
    } else {
		WARNING_1("No Beacons [%1]",_currentBeacon);
	};
};

if (_useLAMBS) then {
	[_group, _positionToGarrison, _radius] call lambs_wp_fnc_taskGarrison;
} else {
	//Todo tweak defend garrison ratio: https://github.com/CBATeam/CBA_A3/pull/573/
	[_group, _positionToGarrison, _radius] call CBA_fnc_taskDefend;
};
