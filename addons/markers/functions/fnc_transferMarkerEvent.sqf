#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles transfer of a marker that does not require
 * change in marker name. This means group markers may become single
 * unit markers until that group attempts to reclaim the marker
 *
 * Arguments:
 * 0: Hashkey of marker <STRING>
 * 1: Object marker will be attached to <OBJECT>
 *    (OPTIONAL, default detach marker)
 * 2: Side of object marker will be attached to <SIDE>
 *    (OPTIONAL, default no change)
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_updateMarkerEvent;
 *
 * Public: No
 */
params [
    ["_hashKey", "", [""]],
    ["_newObject", objNull, [objNull]],
    ["_newSide", sideNull, [sideNull]]
];

private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, []];

if (_markerArray isEqualTo []) exitWith {
    TRACE_1("No entry found in marker hash:",_this);
};

_markerArray set [0, _newObject];
if !(isNull _newSide) then {
    _markerArray set [6, _newSide];
};

if (isServer) then {
    CBA_UPDATE_JIPQUEUE(_hashKey,_markerArray);
};

if (_markerArray#6 in ([] call FUNC(getSideArray))) then {
    GVAR(drawHash) set [_hashKey, _markerArray];
};

