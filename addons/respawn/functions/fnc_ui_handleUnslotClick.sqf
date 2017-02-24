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
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

private _groupPath = tvCurSel GROUP_TREE_IDC;

if (count _groupPath != 2) exitWith { LOG("Bad selections when trying to unslot"); };

[objNull, _groupPath, true] call FUNC(slotUnit);
