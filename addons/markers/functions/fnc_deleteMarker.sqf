#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function deletes a marker locally, the marker can still be initialized
 * unless this function is run on the server. To remove a marker on all clients
 * remoteExecCall this function
 *
 * Arguments:
 * 0: Hashkey of marker to delete <STRING>
 *
 * Example:
 * ["fuckYeah"] call potato_markers_fnc_deleteMarker;
 * ["Blufor A1"] call potato_markers_fnc_deleteMarker;
 * // Deletes marker everywhere
 * ["Blufor A1"] remoteExecCall ["potato_markers_fnc_deleteMarker"];
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
