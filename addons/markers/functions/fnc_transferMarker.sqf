#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles transfer of a marker that does not require
 * change in marker name. This means group markers may become single
 * unit markers until that group attempts to reclaim the marker.
 * It operates locally and should be called by remoteExecCall or by global event.
 *
 * Arguments:
 * 0: Hashkey of marker <STRING>
 * 1: Object marker will be attached to <OBJECT>
 *    (OPTIONAL, default detach marker)
 * 2: Side of object marker will be attached to <SIDE>
 *    (OPTIONAL, default no change)
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_transferMarker;
 *
 * Public: Yes
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
TRACE_2("Transfering marker",_this,_markerArray);

_markerArray set [0, _newObject];
private _newPosATL = getPosATL _newObject;
if (_newPosATL isNotEqualTo [0, 0, 0]) then {
    _markerArray set [5, _newPosATL];
};
if !(isNull _newSide) then {
    _markerArray set [6, _newSide];
};

if (isServer) then {// server updates cache for JIPs
    private _markerCacheEntry = GVAR(markerCache) getVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, []];
    if (_markerCacheEntry isEqualTo []) exitWith {
        WARNING_1("Invalid marker transfer attempt with key: %1",_hashKey);
    };
    _markerCacheEntry set [1, getPosATL _newObject];
    _markerCacheEntry set [2, _newObject];
    GVAR(markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, _markerCacheEntry, true];
};

if (_markerArray#6 in ([] call FUNC(getSideArray))) then {
    GVAR(drawHash) set [_hashKey, _markerArray];
};

