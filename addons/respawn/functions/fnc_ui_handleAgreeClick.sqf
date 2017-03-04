/*
 * Author: AACO
 * Handles when a user agrees to the EULA, stores in the profileNamespace to ensure persistence
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleAgreeClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

closeDialog 1;
profileNamespace setVariable [EULA_CHECK, true];
[] call FUNC(openAdminRespawn);
