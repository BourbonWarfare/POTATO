/*
 * Author: AACO
 * Handles when a user cancels a respawn setup
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleCancelClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[] call FUNC(resetGroupInfo);
[false] call FUNC(changeRespawnState);
[] call FUNC(closeAdminRespawn);
