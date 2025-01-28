#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles visual updates to a marker already in the marker cache
 *
 * Arguments:
 * 0: Hashkey of marker <STRING>
 * 1: Marker text <STRING>
 * 2: Marker icon size DEFAULT_MARKER_SIZE <SCALAR>
 * 3: Color array of the  or default color array index <ARRAY/NUMBER>
 *      (OPTIONAL, default -1 or no change)
 * 4: Icon of the marker to show or default marker array index <STRING/NUMBER>
 *      (OPTIONAL, default -1 or no change)
 *
 * Example:
 * [groupID player, "Yar", 3,] call potato_markers_fnc_addMarkerEvent;
 *
 * Public: No
 */
params [
    ["_hashKey", "", [""]],
    ["_newText", DEFAULT_MARKER_TEXT, [DEFAULT_MARKER_TEXT]],
    ["_newSize", DEFAULT_MARKER_SIZE, [DEFAULT_MARKER_SIZE]],
    ["_newColor", -1, [DEFAULT_MARKER_COLOR, DEFAULT_MARKER_COLOR_INDEX]],
    ["_newIcon", -1, [DEFAULT_MARKER_ICON, DEFAULT_MARKER_ICON_INDEX]]
];

private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, []];

if (_markerArray isEqualTo []) exitWith {
    TRACE_1("No entry found in marker hash:",_this);
};

if (_newIcon isEqualType 0 && {_newIcon >= 0 && _newIcon < 20}) then {
    _newIcon = [UNIT_MARKERS_STRINGS]#_newIcon;
};
if (_newColor isEqualType 0 && {_newColor >= 0 && _newColor < 8}) then {
    _newColor = COLOR_INDEX_ARRAY#_newColor;
};

// Update marker array
_markerArray set [1, _newText];
if (_newIcon isEqualType "") then {
    _markerArray set [2, _newIcon];
};
if (_newColor isEqualType []) then {
    _markerArray set [3, _newColor];
};
_markerArray set [4, _newSize];
_markerArray set [5, getPosATL _markerArray#0];

if (isServer) then {
    CBA_UPDATE_JIPQUEUE(_hashKey,_markerArray);
};

if (_markerArray#6 in ([] call FUNC(getSideArray))) then {
    GVAR(drawHash) set [_hashKey, _markerArray];
};
