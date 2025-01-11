/*
 * Author: AACO
 * Function used to add player/group marker information into the marker hash on
 * a player change event
 *
 * Arguments:
 * 0: changed unit <OBJECT>
 *
 * Examples:
 * [player] call potato_markers_fnc_handleCheckPlayerForMarkers;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Handle Check Player",_this);

params ["_newPlayer"];
private _newPlayerGroup = group _newPlayer;

private _sideArray = [] call FUNC(getSideArray);

if (!(isNull _newPlayerGroup) && {side _newPlayerGroup in _sideArray}) then {
    [_newPlayerGroup] call FUNC(addMarkerInfoToHash);
    [_newPlayer] call FUNC(addMarkerInfoToHash);
};
