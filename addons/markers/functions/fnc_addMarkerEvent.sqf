#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the QGVAR(addMarkerEvent) event, which adds both
 * local and non-local markers to a players marker hash.
 *
 * Arguments:
 * 0: Hashkey of marker, we send the event because the object
 *     may change over time <STRING>
 * 1: Object marker is attached to <OBJECT>
 * 2: Marker text <STRING>
 * 3: Icon of the marker to show <STRING>
 * 4: Color array of the marker <ARRAY>
 * 5: Marker icon size DEFAULT_MARKER_SIZE <SCALAR>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_hasMarkerAttached;
 *
 * Public: No
 */
params [
    ["_hashKey", "", [""]],
    ["_object", objNull, [objNull]],
    ["_text", DEFAULT_MARKER_TEXT, [DEFAULT_MARKER_TEXT]],
    ["_icon", DEFAULT_MARKER_ICON, [DEFAULT_MARKER_ICON]],
    ["_color", DEFAULT_MARKER_COLOR, [DEFAULT_MARKER_COLOR]],
    ["_size", DEFAULT_MARKER_SIZE, [DEFAULT_MARKER_SIZE]]
];

if (_hashKey == "") exitWith {
    WARNING_1("No hashkey passed",_this);
};

private _posATL = if (isNull _object) then {
    [-100, -100, 0]
} else {
    getPosATL _object;
};
GVAR(markerHash) set [_hashKey, [_object, _text, _icon, _color, _size, _posATL]];
