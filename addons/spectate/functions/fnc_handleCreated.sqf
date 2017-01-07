/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
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
