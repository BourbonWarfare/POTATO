#include "..\script_component.hpp"
/*
 * Author: AACO
 * Function used to check a unit for a map marker color
 *
 * Arguments:
 * 0: First Attempt <BOOL> - If true try again if group data not available (OPTIONAL, default: true)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_markers_fnc_checkForMapMarkerColor;
 *
 * Public: No
 */

params [["_firstAttempt", true, [true]]];
private _group = group player;

INFO_2("checkForMapMarkerColor [%1-%2]",_group,_firstAttempt);

if (_firstAttempt && {_group isNil QGVAR(markerColor)}) exitWith {
    WARNING_1("Group [%1] data not available - trying again in 10 seconds",_group);
    [{
        params ["_maxWaitTime"];
        diag_tickTime > _maxWaitTime
    }, {
        [false] call FUNC(checkForMapMarkerColor);
    }, [diag_tickTime + 10]] call CBA_fnc_waitUntilAndExecute;
};

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
