#include "script_component.hpp"
#include "\z\potato\addons\markers\defaultMarkerDefines.hpp"
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

private _newHashKey = str side _selectedUnit + str _selectedUnit;
private _itr = 0;
while {(_newHashKey == _hashKey || (_newHashKey in EGVAR(markers,markerHash))) && _itr < 25 } do {
    _newHashKey = str side _selectedUnit + str _selectedUnit + str _itr;
    _itr = _itr + 1;
};
private _newMarkerArray = [_newHashKey, getPosATL _selectedUnit, _selectedUnit, side _selectedUnit, _markerArray#1, _markerArray#3, _markerArray#2, _markerArray#4];
private _endIndex = 8;
if (_size == DEFAULT_MARKER_SIZE) then {_endIndex = 7};
if (_icon == DEFAULT_MARKER_ICON_INDEX && _endIndex == 7) then {_endIndex = 6};
_newMarkerArray = _newMarkerArray select [0, _endIndex];
EGVAR(markers,markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _newHashKey, _newMarkerArray, true];
_newMarkerArray remoteExecCall [QEFUNC(markers,addMarker)];
[_hashKey] remoteExecCall [QEFUNC(markers,deleteMarker)];

["potato_adminMsg", [
    format ["Transfering marker %1 to %2",
        _hashKey,
        _selectedUnit
    ],
    profileName
]] call CBA_fnc_globalEvent;

[] call FUNC(reloadMarkersTab);
