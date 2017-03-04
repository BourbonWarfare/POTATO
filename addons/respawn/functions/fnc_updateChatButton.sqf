/*
 * Author: AACO
 * Updates the state of the chat button based on the current spectator chat value
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_updateChatButton;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

ctrlShow [ADMIN_CHAT_BUTTON_ON_IDC, GVAR(currentSpecChat)];
ctrlShow [ADMIN_CHAT_BUTTON_OFF_IDC, !GVAR(currentSpecChat)];
