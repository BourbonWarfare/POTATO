/*
 * Author: AACO
 * Function used to handle a unit's death
 * Should only be called by events
 *
 * Arguments:
 * 0: Unit killed <OBJECT>
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

params ["_unit"];

[_unit] call FUNC(removeEventHandlers);

[] call FUNC(updateList);
