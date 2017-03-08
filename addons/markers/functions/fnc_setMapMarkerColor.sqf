/*
 * Author: AACO
 * Function used to add unit/group marker information into the marker hash
 *
 * Arguments:
 * 0: Unit or Group to add to the marker system <OBJECT/GROUP>
 *
 * Return Value:
 * True if the info was added to the hash, false otherwise <BOOL>
 *
 * Examples:
 * [player] call potato_markers_fnc_addMarkerInfoToHash;
 * [group player] call potato_markers_fnc_addMarkerInfoToHash;
 *
 * Public: Yes
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
    if (_markerColorString == (_x select 0)) exitWith {
        _lookup = _forEachIndex;
    };
} forEach ACEGVAR(markers,MarkerColorsCache);

if (_lookup < 0) exitWith { WARNING("Provided color doesn't have matching ace MarkerColorsCache"); };

ACEGVAR(markers,curSelMarkerColor) = _lookup;
