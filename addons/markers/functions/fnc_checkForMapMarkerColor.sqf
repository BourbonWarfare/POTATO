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

params [["_newPlayer", objNull, [objNull]]];

if (isNull _newPlayer) exitWith { WARNING("Provided new player is null"); };

if (_newPlayer getVariable [QGVAR(addMarker), false]) then {
    [_newPlayer getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR]] call FUNC(setMapMarkerColor);
} else {
    private _group = group _newPlayer;
    if (_group getVariable [QGVAR(addMarker), false]) then {
        [_group getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR]] call FUNC(setMapMarkerColor);
    };
};
