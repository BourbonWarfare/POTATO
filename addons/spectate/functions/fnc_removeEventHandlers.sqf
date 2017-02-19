/*
 * Author: AACO
 * Function used to remove event handlers from a unit
 *
 * Arguments:
 * 0: Unit to remove event handlers from <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_removeEventHandlers;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit"];

private _index = _unit getVariable [QGVAR(firedEHID), -1];
if (_index > -1) then {
    _unit removeEventHandler ["Fired", _index];
    _unit setVariable [QGVAR(firedEHID), -1];
};

_index = _unit getVariable [QGVAR(killedEHID), -1];
if (_index > -1) then {
    _unit removeEventHandler ["Killed", _index];
    _unit setVariable [QGVAR(killedEHID), -1];
};
