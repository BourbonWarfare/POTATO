#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the QGVAR(deleteMarker) event, which removed
 * markers from the players markers
 *
 * Arguments:
 * 0: Hashkey of marker to delete <STRING>
 *
 * Example:
 * ["fuckYeah"] call potato_markers_fnc_deleteMarkerEvent;
 * ["Blufor A1"] call potato_markers_fnc_deleteMarkerEvent;
 *
 * Public: No
 */
params [["_hashKey", "", [""]]];

if (_hashKey == "") exitWith {
    TRACE_1("Delete event| no hashkey:"_hashKey);
};

if (isServer) then {
    [POTAOT_MARKER_JIP_PREFIX + _hashKey] call CBA_fnc_removeGlobalEventJIP;
};

GVAR(markerHash) deleteAt _hashKey;
GVAR(drawHash) deleteAt _hashKey;
