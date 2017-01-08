/*
 * Author: AACO
 * Function used straggle update information
 * Should only be called from events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_ui_straggleUpdate;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

[] call FUNC(updateList);
[] call FUNC(updateInfo);
