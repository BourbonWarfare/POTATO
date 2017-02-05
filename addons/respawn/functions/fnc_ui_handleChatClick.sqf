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

GVAR(currentSpecChat) = !GVAR(currentSpecChat);
[GVAR(currentSpecChat)] call acre_api_fnc_setSpectator;

[] call FUNC(updateChatButton);
