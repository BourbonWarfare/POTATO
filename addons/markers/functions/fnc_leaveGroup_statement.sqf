#include "..\script_component.hpp"
/*
 * Author: AACO
 * Function used to draw markers
 *
 * Arguments:
 * 0: Map control <CONTROL>
 *
 * Examples:
 * [(findDisplay 12) displayCtrl 52] call potato_markers_fnc_drawMarkers; // draw markers on map
 * [(findDisplay 133) displayCtrl 101] call potato_markers_fnc_drawMarkers; // draw markers on GPS
 *
 * Public: No
 */
private _hashKey = groupId group _player;
_oldGroup = units group _player;
_newGroup = createGroup side group _player;
[_player] joinSilent _newGroup;
{_player reveal _x} forEach _oldGroup;
if !(GVAR(groupAndUnitEnabled)) exitWith {};
private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, [objNull]];
if (_markerArray#0 == _player && _hashKey != "") then {
    [_hashKey] remoteExecCall [QFUNC(transferMarker)];
};
