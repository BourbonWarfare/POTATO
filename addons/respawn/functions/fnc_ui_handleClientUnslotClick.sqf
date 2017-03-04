/*
 * Author: AACO
 * Handles unslotting a client
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleClientUnslotClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _groupPath = [[player] call BIS_fnc_objectVar, GROUP_TREE_IDC] call EFUNC(spectate,findPathInList);

if (_groupPath isEqualTo [-1] || count _groupPath != 2) exitWith { LOG("Bad selections when trying to unslot"); };

[objNull, _groupPath, true] call FUNC(slotUnit);
