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
private _markerJIPs = (allVariables GVAR(markerCache)) select {
    _x select [0, POTATO_MARKER_JIP_PREFIX_LENGTH] == POTATO_MARKER_JIP_PREFIX
};

{
    private _markerArray = GVAR(markerCache) getVariable [_x, []];
    if (_markerCache isEqualType [] && _markerCache isNotEqualTo []) then {
        _markerArray call FUNC(addMarkerEvent);
    };
} forEach _markerJIPs;
