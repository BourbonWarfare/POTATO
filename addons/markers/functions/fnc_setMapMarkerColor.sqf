/*
 * Author: AACO
 * Function used to set a map marker color on a unit
 *
 * Arguments:
 * 0: Marker color <ARRAY>
 *
 * Return Value:
 * None
 *
 * Examples:
 * [[0.9,0,0,1]] call potato_markers_fnc_setMapMarkerColor;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_markerColor", [], []]];

if (count _markerColor != 4) exitWith { WARNING("Provided color doesn't have correct arguments"); };

private _lookup = (COLOR_TO_MARKER_HASH select 0) find (str _markerColor);

if (_lookup < 0) exitWith { WARNING("Provided color doesn't have matching cfg marker color"); };

private _markerColorString = (COLOR_TO_MARKER_HASH select 1) select _lookup;

_lookup = -1;

{
    TRACE_2("loop",_markerColorString,_x select 0);
    if (_markerColorString == (_x select 0)) exitWith {
        _lookup = _forEachIndex;
    };
} forEach ACEGVAR(markers,MarkerColorsCache);

TRACE_4("vars",str _markerColor,_markerColorString,_lookup,ACEGVAR(markers,MarkerColorsCache));

if (_lookup < 0) exitWith { WARNING("Provided color doesn't have matching ace MarkerColorsCache"); };

INFO_3("Setting Map Draw Color [Array:%1][Color:%2][Index:%3]",_markerColor,_markerColorString,_lookup);

// brute force lb selection
if !(isNull findDisplay 12) then { ((findDisplay 12) displayCtrl 1090) lbSetCurSel _lookup; };
if !(isNull findDisplay 37) then { ((findDisplay 37) displayCtrl 1090) lbSetCurSel _lookup; };
if !(isNull findDisplay 52) then { ((findDisplay 52) displayCtrl 1090) lbSetCurSel _lookup; };
if !(isNull findDisplay 53) then { ((findDisplay 53) displayCtrl 1090) lbSetCurSel _lookup; };

ACEGVAR(markers,curSelMarkerColor) = _lookup;
