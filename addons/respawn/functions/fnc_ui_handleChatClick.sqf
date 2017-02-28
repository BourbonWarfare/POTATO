/*
 * Author: AACO
 * Handles clicking the chat button, to join/leave spectate chat
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleChatClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

GVAR(currentSpecChat) = !GVAR(currentSpecChat);
[GVAR(currentSpecChat)] call acre_api_fnc_setSpectator;

[] call FUNC(updateChatButton);
