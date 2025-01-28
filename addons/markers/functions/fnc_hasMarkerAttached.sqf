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

private _array = GVAR(markerHash) getOrDefault [groupId _object, []];
if (_array isEqualTo []) then {
    GVAR(markerHash) getOrDefault [str _object, [objNull]];
};
_array#0 isEqualTo _object
