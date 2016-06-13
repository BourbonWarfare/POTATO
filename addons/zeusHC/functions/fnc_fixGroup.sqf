/*
 * Author: AACO
 * Function used try to "unstick" groups that have become unresponsive
 *
 * Arguments:
 * 0: group you want to try to fix <GROUP>
 *
 * Return Value: Nothing
 *
 * Examples:
 * [group player] call potato_zeusHC_fnc_fixGroup;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_group", grpNull, [grpNull]]
];

// if the group is not local, exit
if (isNull _group || !(local _group)) exitWith { ERROR("Group is null/not local, can not even try to fix"); };

// try to cycle the leader, unset any doWatches
private _leader = leader _group;
private _leaderNotSwapped = true;
{
    _x doWatch objNull;
    if (_leaderNotSwapped && {_leader != _x}) then {
        _leaderNotSwapped = false;
        _group selectLeader _x;
    };
    nil
} count (units _group);
_group selectLeader _leader;

// set the behavior to normal, sometimes "COMBAT" locks a group up.
_group setBehaviour "NORMAL";

// remove all waypoints, then add a move waypoint at the groups location
while { count (waypoints _group) > 0 } do {
    deleteWaypoint ((waypoints _group) select 0);
};
private _tmpWaypoint = _group addWaypoint [_leader getRelPos [15, getDir _leader], 0];
_tmpWaypoint setWaypointType "MOVE";
