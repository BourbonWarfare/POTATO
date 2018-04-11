/*
 * Author: AACO
 * Function used to start the spectate script from the placeable spectate unit
 * Should only be called from the spectate unit init event dispacher
 *
 * Arguments:
 * 0: Spectate unit <OBJECT>
 *
 * Examples:
 * [player] call potato_spectate_fnc_initSpectatorUnit;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (!hasInterface) exitWith {};

[
    {player == player && {time > 0}},
    {
        if (player == (_this select 0)) then {
            [FUNC(setup), _this, 1] call CBA_fnc_waitAndExecute;
        };
    },
    _this
] call CBA_fnc_waitUntilAndExecute;
