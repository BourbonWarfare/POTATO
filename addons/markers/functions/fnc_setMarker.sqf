/*
 * Author: AACO
 * Function to set marker vars on groups
 * Should only be called through 3DEN
 *
 * Arguments:
 * 0: Object/Group to add attributes to <GROUP>
 * 1: MarkerInfo <STRING,BOOL>
 *
 * Example:
 * [object, true] call potato_markers_fnc_setGroupVar;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);
params ["_object",["_markerInfo","",["",false]]];
if (_markerInfo isEqualType true && {_markerInfo}) exitWith { LOG("Marker not set, or in strange state, exiting early"); };

[{
    params ["_object","_markerInfo"];
    (_markerInfo splitString ",") params [
        ["_markerText", DEFAULT_MARKER_TEXT, [""]],
        ["_markerSize", str DEFAULT_MARKER_SIZE, [""]],
        ["_markerColor", DEFAULT_MARKER_COLOR_TEXT, [""]],
        ["_markerIcon", DEFAULT_MARKER_ICON, [""]]
    ];

    _markerSize = parseNumber _markerSize;
    if (_markerSize < 1) then { _markerSize = DEFAULT_MARKER_SIZE; };

    private _colorArray = switch (_markerColor) do {
        case ("red"): { RED_ARRAY };
        case ("blue"): { BLUE_ARRAY };
        case ("green"): { GREEN_ARRAY };
        case ("orange"): { ORANGE_ARRAY };
        case ("yellow"): { YELLOW_ARRAY };
        case ("pink"): { PINK_ARRAY };
        case ("black"): { BLACK_ARRAY };
        default { WHITE_ARRAY };
    };

    TRACE_5("Object properies",_object, _markerText, _markerIcon, _colorArray, _markerSize);

    _object setVariable [QGVAR(addMarker), true, true];
    _object setVariable [QGVAR(markerText), _markerText, true];
    _object setVariable [QGVAR(markerTexture), _markerIcon, true];
    _object setVariable [QGVAR(markerColor), _colorArray, true];
    _object setVariable [QGVAR(markerSize), _markerSize, true];
}, _this] call CBA_fnc_execNextFrame;
