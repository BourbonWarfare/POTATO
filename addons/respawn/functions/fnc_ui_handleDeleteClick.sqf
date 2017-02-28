/*
 * Author: AACO
 * Handles a user deleting a group
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleDeleteClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

(tvCurSel GROUP_TREE_IDC) params [["_groupIndex", -1, [0]]];

if (_groupIndex < 0) exitWith { LOG("Delete called, without a valid group selection"); };

[_groupIndex] call FUNC(deleteGroup);
