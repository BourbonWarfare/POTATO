#include "..\script_component.hpp"
/*
 * Author: Lambda.Tigers
 * Function used to reinitialize the marker hash
 *
 *
 * Examples:
 * [] call potato_markers_fnc_reinitMarkerHash;
 *
 * Public: Yes
 */

// reset markers and
GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;

// We keep the JIP queue accurate, this takes a moment to do for large JIP queues
private _markerJIPs = (allVariables CBA_JIP_QUEUE_OBJECT) select {
    _x select [0, POTATO_MARKER_JIP_PREFIX_LENGTH] == POTATO_MARKER_JIP_PREFIX
};

{
    private _CBAjipArray = CBA_JIP_QUEUE_OBJECT getVariable [_x, []];
    if (_CBAjipArray isEqualType []) then {
        _CBAjipArray params ["", ["_eventArray", []]];
        _eventArray params ["", ["_eventArgs", []]];
        _eventArgs params ["", ["_markerArray", []]];
        if (_markerArray isEqualTo []) then {continue};
        _markerArray call FUNC(addMarkerEvent);
    };
} forEach _markerJIPs;
