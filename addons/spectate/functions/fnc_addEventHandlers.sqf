/*
 * Author: AACO
 * Function used to add event handlers to a unit
 *
 * Arguments:
 * 0: Unit to add event handlers to <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_addEventHandlers;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit"];

if (_unit getVariable [QGVAR(firedEHID), -1] == -1) then {
    _unit setVariable [
        QGVAR(firedEHID),
        _unit addEventHandler ["Fired", {call FUNC(handleFired)}]
    ];
};

if (_unit getVariable [QGVAR(killedEHID), -1] == -1) then {
    _unit setVariable [
        QGVAR(killedEHID),
        _unit addEventHandler ["Killed", {call FUNC(handleKilled)}]
    ];
};
