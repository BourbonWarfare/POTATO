/*
 * Author: AACO
 * Function used to handle a unit's death'
 * Should only be called by events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_handleKilled;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(running)) then {
    [] call FUNC(updateList);
};
