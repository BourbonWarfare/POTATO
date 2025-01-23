#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the QGVAR(claimMarkerEvent) event, which updates
 * marker ownership to a new unit
 *
 * Arguments:
 * 0: Hashkey of marker, we send the event because the object
 *     may change over time <STRING>
 * 1: Object marker will be attached to <OBJECT>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_hasMarkerAttached;
 *
 * Public: No
 */
params [
    ["_hashKey", "", [""]],
    ["_object", objNull]
];
TRACE_1("claimMarker Event",_this);
if (_hashKey == "") exitWith {};
private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, []];
if (_markerArray isEqualTo []) exitWith {
    TRACE_1("Failed to find marker entry",keys GVAR(markerHash));
};
TRACE_1("claimMarker Found Entry",_markerArray);

if (side _object != side _markerArray#0) then {
    GVAR(drawHash) deleteAt _hashKey;
};

_markerArray set [0, _object];