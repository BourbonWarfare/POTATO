/*
 * Author: AACO
 * Function used to check a unit for a map marker color
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_markers_fnc_checkForMapMarkerColor;
 *
 * Public: No
 */

#include "..\script_component.hpp"
TRACE_1("Params",_this);

private _group = group player;

private _debugAdd = _group getVariable [QGVAR(addMarker), -1];
private _debugColor = _group getVariable [QGVAR(markerColor), -1];
INFO_3("DEBUG: checkForMapMarkerColor Group %1: addMarker=%2, markerColor=%3",_group,_debugAdd,_debugColor);

if (_group getVariable [QGVAR(addMarker), false]) then {
    [_group getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR]] call FUNC(setMapMarkerColor);
} else {
    if ((leader _group) getVariable [QGVAR(addMarker), false]) then {
        [(leader _group) getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR]] call FUNC(setMapMarkerColor);
    };
};
