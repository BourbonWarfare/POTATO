/*
 * Author: AACO
 * Handles closing the admin respawn from the close button
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleCloseClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[] call FUNC(closeAdminRespawn);
