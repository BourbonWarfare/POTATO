/*
 * Author: AACO
 * Handles an admin unslotting a spectator
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleUnslotClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _groupPath = tvCurSel GROUP_TREE_IDC;

if (count _groupPath != 2) exitWith { LOG("Bad selections when trying to unslot"); };

[objNull, _groupPath, true] call FUNC(slotUnit);
