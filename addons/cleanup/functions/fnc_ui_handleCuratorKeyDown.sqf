#include "script_component.hpp"


TRACE_1("params",_this);

if (inputAction "curatorDelete" > 0) exitWith {
    curatorSelected params ["_objects", "_groups", "_waypoints", "_markers"];

    { // delete waypoints
        deleteWaypoint _x;
    } forEach _waypoints;

    { // delete waypoints
        deleteMarker _x;
    } forEach _markers;

    // aggrigate objects to be cleaned up.
    private _objectsForCleanup = _objects;
    {
        _x deleteGroupWhenEmpty true;
        {
            _objectsForCleanup pushBackUnique _x;
        } forEach (units _x);
    } forEach _groups;

    [_objectsForCleanup] call FUNC(cleanObjects);

    true
};

false
