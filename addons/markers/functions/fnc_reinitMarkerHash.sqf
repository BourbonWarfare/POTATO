#include "..\script_component.hpp"
/*
 * Author: Lambda.Tigers
 * Function used to reinitialize the marker hash from the shared marker
 * cache object
 *
 * Arguments:
 * 0: Whether to sync marker positions with server, default false <BOOL>
 *
 * Examples:
 * [] call potato_markers_fnc_reinitMarkerHash;
 *
 * Public: Yes
 */
params [["_forceSyncPos", false, [false]]];
// reset markers and
GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;

// We keep the JIP queue accurate, this takes a moment to do for large JIP queues
private _markerJIPs = (allVariables GVAR(markerCache)) select {
    _x select [0, POTATO_MARKER_JIP_PREFIX_LENGTH] == POTATO_MARKER_JIP_PREFIX
};
TRACE_1("Found markers in JIP",count _markerJIPs);
{
    private _markerArray = GVAR(markerCache) getVariable [_x, []];
    if (_markerArray isEqualType [] && _markerArray isNotEqualTo []) then {
        _markerArray call FUNC(addMarker);
    };
} forEach _markerJIPs;

if (_forceSyncPos) then {
    [] call FUNC(requestMarkerPosSync);
};
