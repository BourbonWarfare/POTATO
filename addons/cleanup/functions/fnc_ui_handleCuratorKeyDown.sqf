/*
 * Author: AACO
 * Function used intercept and handle zeus delete events
 * Should only be called by UI Events
 *
 * Examples:
 * [] call potato_cleanup_fnc_ui_handleCuratorKeyDown;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);

if (inputAction "curatorDelete" > 0 && {GVAR(deadCleanupEnabled)}) exitWith {
    curatorSelected params ["_objects", "_groups", "_waypoints", "_markers"];

    { // delete waypoints
        deleteWaypoint _x;
    } forEach _waypoints;

    { // delete markers
        deleteMarker _x;
    } forEach _markers;

    // aggrigate objects to be cleaned up.
    private _objectsForCleanup = [];
    private _fnc_checkObjectForCleanup = {
        params [["_object", objNull, [objNull]]];
        if (!(isNull _object || {isPlayer _object} || {_object getVariable [QGVAR(wasPlayer), false]})) then {
            _objectsForCleanup pushBackUnique _object;
            if (!(_object isKindOf "Man")) then {
                {
                    [_x#0] call _fnc_checkObjectForCleanup;
                } forEach (fullCrew _x);
            };
        };
    };

    { // check direct objects
        [_x] call _fnc_checkObjectForCleanup;
    } forEach _objects;

    { // check groups
        _x deleteGroupWhenEmpty true;
        {
            [_x] call _fnc_checkObjectForCleanup;
        } forEach (units _x);
    } forEach _groups;

    [_objectsForCleanup] call FUNC(cleanObjects);

    true
};

false
