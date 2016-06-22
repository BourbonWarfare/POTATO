/*
 * Author: AACO
 * Function used to convert a color string to a color array
 *
 * Arguments:
 * 0: Unit or Group to add to the marker color to <OBJECT/GROUP>
 * 1: String of the color to set <STRING>
 *
 * Examples:
 * [player, "pink"] call potato_markers_fnc_setMarkerColor;
 * [group player, "black"] call potato_markers_fnc_setMarkerColor;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_markerObject","_markerColor"];

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

SETVAR(_markerObject,GVAR(markerColor),_colorArray);
