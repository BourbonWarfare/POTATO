/*
 * Author: AACO
 * Function used to handle the creation of a unit
 * Should only be called by events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_handleCreated;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit"];

_unit addEventHandler ["Fired", FUNC(handleFired)];
_unit addEventHandler ["Killed", FUNC(handleKilled)];

if (GVAR(running)) then {
    [] call FUNC(updateList);
};
