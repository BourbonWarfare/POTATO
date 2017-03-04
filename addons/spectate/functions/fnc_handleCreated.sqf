/*
 * Author: AACO
 * Function used to handle the creation of a unit
 * Should only be called by events
 *
 * Arguments:
 * 0: Unit to add event handlers to <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_handleCreated;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit"];

if (GVAR(running)) then {
    [_unit] call FUNC(addEventHandlers);
    [] call FUNC(updateList);
};
