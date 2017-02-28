/*
 * Author: AACO
 * Handles opening/closing respawn
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleRespawnStateClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[!GVAR(open)] call FUNC(changeRespawnState);
