/*
 * Author: AACO
 * Gets all an array of all spectators
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Array of all spectators not currently slotted
 *
 * Example:
 * [] call potato_respawn_fnc_getSpectators;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _spectators = [];

{
    //if (!isNull _x && {_x isKindOf QEGVAR(spectate,spectator)}  && {alive _x} && {isPlayer _x}
    //    && {[[_x] call BIS_fnc_objectVar, GROUP_TREE_IDC] call EFUNC(spectate,findPathInList) isEqualTo [-1]}) then {
    //    _spectators pushBack _x;
    //};
    _spectators pushBack _x;
    nil
} count (units EGVAR(spectate,group) + allDeadMen); // count used here for speed, ensure nil is above this line

_spectators
