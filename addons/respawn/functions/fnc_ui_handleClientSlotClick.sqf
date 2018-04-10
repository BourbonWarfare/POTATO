/*
 * Author: AACO
 * Handles when a client hits the slot button, or double clicks on the slot they want
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleClientSlotClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _groupPath = tvCurSel GROUP_TREE_IDC;

if (count _groupPath != 2) exitWith { LOG("Bad path when trying to slot"); };

// ensure player doesn't double slot
[] call FUNC(ui_handleClientUnslotClick);

// give a frame for the previous function to hit the server
[FUNC(slotUnit), [player, _groupPath, false]] call CBA_fnc_execNextFrame;
