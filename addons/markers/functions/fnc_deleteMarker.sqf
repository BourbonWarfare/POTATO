#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function deletes a marker event, removing markers from all players
 * and from the JIP sync'd variable
 *
 * Arguments:
 * 0: Hashkey of marker to delete <STRING>
 *
 * Example:
 * ["fuckYeah"] call potato_markers_fnc_deleteMarkerEvent;
 * ["Blufor A1"] call potato_markers_fnc_deleteMarkerEvent;
 *
 * Public: Yes
 */
params [["_hashKey", "", [""]]];

if (_hashKey == "" || !(_hashKey in GVAR(markerHash))) exitWith {
    TRACE_1("Delete event| invalid hashkey:",_hashKey);
};

if (isServer) then {// server updates cache for JIPs
    GVAR(markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, nil, true];
};

GVAR(markerHash) deleteAt _hashKey;
GVAR(drawHash) deleteAt _hashKey;
