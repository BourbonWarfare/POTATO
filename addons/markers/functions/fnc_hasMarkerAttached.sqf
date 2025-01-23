#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will take an object and check whether it has a
 * marker attached to it.
 *
 * Arguments:
 * 0: Object to check if it has a marker attached <OBJECT>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_hasMarkerAttached;
 *
 * Public: Yes
 */
params [
    ["_object", objNull, [objNull]]
];

private _hashKey = groupId _object;
private _array = GVAR(markerHash) getOrDefault [_hashKey, [grpNull]];
_array#0 isEqualTo _object
