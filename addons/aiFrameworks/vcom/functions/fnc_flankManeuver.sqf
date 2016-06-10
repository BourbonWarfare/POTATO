#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _nearestEnemy = _unit findNearestEnemy _unit;
if (isNull _nearestEnemy) exitWith {};

private _unitGroup = group _unit;
if ((count (waypoints _unitGroup)) > 0) then { //they're busy, free them for the task to come`
    while {count (waypoints _unitGroup) > 1} do {
        deleteWaypoint [_unitGroup, 1];
    };
    [_unitGroup, 0] setWaypointPosition [position (leader _unitGroup), 100];
};

_unit setVariable [VQGVAR(flanking),diag_tickTime];

//Check to see if the AI should just press the advantage!
private _enemyGroupCount = count (units (group _nearestEnemy));
private _groupCount = count (units _unitGroup);
private _enemyPos = getposATL _nearestEnemy;

if ((floor (random 100)) <= 75 && {(_enemyGroupCount/_groupCount) <= 0.25}) exitWith { //direct attack
    private _waypoint = _unitGroup addwaypoint [_enemyPos,0];
    _waypoint setwaypointtype "SAD";
    _waypoint setWaypointSpeed "FULL";
    _waypoint setWaypointBehaviour "COMBAT";
};

private _distance  = (random 100) + 100;
private _direction = random 360;
private _position = [(_enemyPos select 0) + (sin _direction) * _distance, (_enemyPos select 1) + (cos _direction) * _distance, 0];

private _places = selectBestPlaces [_enemyPos, 400,"((6*hills + 2*forest + 4*houses + 2*meadow) - sea + (2*trees)) - (1000*deadbody)", 100, 5];
private _randomLocation = (selectRandom _myPlaces) select 0;

_unitGroup setBehaviour "COMBAT";

private _flankWP1 = _unitGroup addWaypoint [_randomLocation,10];
_flankWP1 setWaypointType "MOVE";
_flankWP1 setWaypointSpeed "NORMAL";
_flankWP1 setWaypointBehaviour "COMBAT";
_unitGroup setCurrentWaypoint _flankWP1;

private _flankWP2 = _unitGroup addwaypoint [_position,10];
_flankWP2 setwaypointtype "MOVE";
_flankWP2 setWaypointSpeed "NORMAL";
_flankWP2 setWaypointBehaviour "COMBAT";

private _attackWP = _unitGroup addwaypoint [_enemyPos,10];
_attackWP setWaypointType "SAD";
_attackWP setWaypointSpeed "FULL";
_attackWP setWaypointBehaviour "COMBAT";
