/*
 * Author: AACO
 * Updates the open respawn button based on the current open state
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_updateOpenButton;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

ctrlShow [ADMIN_OPEN_RESPAWN_BUTTON_IDC, !GVAR(open)];
ctrlShow [ADMIN_CLOSE_RESPAWN_BUTTON_IDC, GVAR(open)];
