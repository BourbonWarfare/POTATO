/*
 * Author: AACO
 * Handles a user triggering respawn
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleTriggerClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[false] call FUNC(changeRespawnState);

ctrlShow [ADMIN_MAP_IDC, true];
ctrlSetFocus ADMIN_MAP;
