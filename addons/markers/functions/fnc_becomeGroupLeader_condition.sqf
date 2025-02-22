#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the condition for the ACE "become group leader"
 * action condition override.
 *
 * Arguments:
 * 0: The unit attempting to become leader <OBJECT>
 *
 * Examples:
 * [cursorObject] call potato_markers_fnc_becomeGroupLeader_condition;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_target", "_player"];

call ACEFUNC(interaction,canBecomeLeader) ||
    (GVAR(groupAndUnitEnabled) && {
   private _markerArray = GVAR(markerHash) getOrDefault [groupId group _player, [_player]];
   _markerArray#0 isEqualType objNull && {_markerArray#0 != _player}
})
