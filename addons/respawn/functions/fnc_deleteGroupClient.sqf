/*
 * Author: AACO
 * Client method the server calls to remove a group from the tree
 *
 * Arguments:
 * 0: Group index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [1] call potato_respawn_fnc_deleteGroupClient;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_groupIndex"];

tvDelete [GROUP_TREE_IDC, [_groupIndex]];
