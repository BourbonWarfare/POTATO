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

#include "script_component.hpp"
TRACE_1("params",_this);

ctrlShow [ADMIN_CHAT_BUTTON_ON_IDC, GVAR(currentSpecChat)];
ctrlShow [ADMIN_CHAT_BUTTON_OFF_IDC, !GVAR(currentSpecChat)];
