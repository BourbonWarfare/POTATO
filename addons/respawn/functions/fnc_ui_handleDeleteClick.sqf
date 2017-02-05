/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

(tvCurSel GROUP_TREE_IDC) params [["_groupIndex", -1, [0]]];

if (_groupIndex < 0) exitWith { LOG("Delete called, without a valid group selection"); };

[_groupIndex] call FUNC(deleteGroup);
