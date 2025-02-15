#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Attach marker to a unit based on currrent selections in the admin menu;
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_adminMenu_uihook_attachMarkerUnit;
 *
 * Public: No
 */

private _markerList = UI_TAB_MARKERS_MARKERS;
private _selectedMarkerIndex = lbCurSel _markerList;
if (_selectedMarkerIndex < 0) exitWith {
    TRACE_1("Marker not selected",_selectedMarkerIndex);
};
private _hashKey = _markerList lbData _selectedMarkerIndex;

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
    objNull
];

TRACE_2("Found unit & marker",_selectedUnit,_hashKey);

if (isNull _selectedUnit) exitWith {
    WARNING_1("Bad unit [%1] - disconnect?",_selectedUnit);
};

private _markerArray = EGVAR(markers,markerHash) getOrDefault [_hashKey, []];
if (_markerArray isEqualTo []) exitWith {
    TRACE_1("Bad marker selected",_hashKey);
};

private _newHashKey = str _selectedUnit;
[
    _newHashKey,
    getPosATL _selectedUnit, _selectedUnit, side _selectedUnit,
    _markerArray#1, _markerArray#3, _markerArray#2, _markerArray#4
] remoteExecCall [QEFUNC(markers,addMarker)];
[_hashKey] remoteExecCall [QEFUNC(markers,deleteMarker)];

["potato_adminMsg", [
    format ["Transfering marker %1 to %2",
        _hashKey,
        _selectedUnit
    ],
    profileName
]] call CBA_fnc_globalEvent;

[] call FUNC(reloadMarkersTab);
