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

private _groupPath = tvCurSel GROUP_TREE_IDC;

if (count _groupPath != 2) exitWith { LOG("Bad path when trying to slot"); };

// ensure player doesn't double slot
[] call FUNC(ui_handleClientUnslotClick);

[player, _groupPath, false] call FUNC(slotUnit);
