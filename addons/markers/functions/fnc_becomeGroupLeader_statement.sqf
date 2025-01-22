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
if (_this call ACEFUNC(interaction,canBecomeLeader)) then {
    _this call ACEFUNC(interaction,doBecomeLeader);
};

if (!GVAR(groupAndUnitEnabled)) exitWith {};

private _hashKey = groupID group _player;
private _markerArray = GVAR(drawHash) getOrDefault [_hashKey, []];
if (_markerArray isNotEqualTo [] &&
    _hashKey != "" &&
    (_markerArray#0 isEqualType grpNull || {_markerArray#0 != _player})) then {
    [QGVAR(claimMarker), [_hashKey, _player], _hashKey] call CBA_fnc_globalEventJIP;
};
