/*
 * Author: AACO
 * Function used to ensure a value is between two bounds (inclusive)
 *
 * Arguments:
 * 0: The number to validate <NUMBER>
 * 1: The lower bound used to validate <NUMBER>
 * 2: The upper bound used to validate <NUMBER>
 *
 * Return Value:
 * The input value if it's between the bounds, upper bound if above, lower bound if below <NUMBER>
 *
 * Examples:
 * [1, 0, 2] call potato_core_fnc_ensureRange; // returns 1
 * [2, 0, 1] call potato_core_fnc_ensureRange; // returns 1
 * [0, 1, 2] call potato_core_fnc_ensureRange; // returns 1
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_inputNumber","_lowerBound","_upperBound"];

private _outputNumber = _inputNumber max _lowerBound;
_outputNumber = _outputNumber min _upperBound;

_outputNumber
