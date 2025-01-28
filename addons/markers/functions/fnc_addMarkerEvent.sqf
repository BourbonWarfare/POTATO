#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the QGVAR(addMarker) event, which adds both
 * local and non-local markers to a players marker hash.
 *
 * Arguments:
 * 0: Hashkey of marker, we send the event because the object
 *     may change over time <STRING>
 * 1: Position ATL of the marker <ARRAY>
 * 2: Object marker is attached to <OBJECT>
 * 3: Side of the marker <SIDE>
 * 4: Marker text <STRING>
 * 6: Color array of the  or default color array index <ARRAY/NUMBER>
 * 5: Icon of the marker to show or default marker array index <STRING/NUMBER>
 * 7: Marker icon size DEFAULT_MARKER_SIZE <SCALAR>
 *
 * Example:
 * [groupID player, getPosATL player, player, side player, "Yar"] call potato_markers_fnc_addMarkerEvent;
 *
 * Public: No
 */
TRACE_1("Add marker event",_this);
params [
    ["_hashKey", "", [""]],
    ["_pos", [-10000, -10000, 0], [[]], [2,3]],
    ["_object", objNull, [objNull]],
    ["_side", sideLogic, [sideLogic]],
    ["_text", DEFAULT_MARKER_TEXT, [DEFAULT_MARKER_TEXT]],
    ["_color", DEFAULT_MARKER_COLOR, [DEFAULT_MARKER_COLOR, DEFAULT_MARKER_COLOR_INDEX]],
    ["_icon", DEFAULT_MARKER_ICON, [DEFAULT_MARKER_ICON, DEFAULT_MARKER_ICON_INDEX]],
    ["_size", DEFAULT_MARKER_SIZE, [DEFAULT_MARKER_SIZE]]
];

if (_hashKey == "") exitWith {
    WARNING_1("No hashkey passed| _this:%1",_this);
};

_pos = if (isNull _object) then {
    _pos
} else {
    getPosATL _object;
};

if (_icon isEqualType 0) then {
    _icon = [UNIT_MARKERS_STRINGS]#_icon;
};
if (_color isEqualType 0) then {
    _color = COLOR_INDEX_ARRAY#_color;
};

GVAR(markerHash) set [_hashKey, [_object, _text, _icon, _color, _size, _pos, _side]];

if (_side in ([] call FUNC(getSideArray))) then {
    GVAR(drawHash) set [_hashKey, [_object, _text, _icon, _color, _size, _pos, _side]];
};
