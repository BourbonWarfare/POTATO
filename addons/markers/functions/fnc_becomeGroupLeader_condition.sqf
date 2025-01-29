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
_this call ACEFUNC(interaction,canBecomeLeader) ||
    (GVAR(groupAndUnitEnabled) && {
   private _markerArray = GVAR(markerHash) getOrDefault [groupId group _player, [_player]];
   _markerArray#0 isEqualType objNull && {_markerArray#0 != _player}
})
