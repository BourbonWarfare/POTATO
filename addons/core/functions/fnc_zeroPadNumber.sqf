/*
 * Author: AACO
 * Function used to convert a number into a two digit zero padded string
 *
 * Arguments:
 * 0: Number to convert <NUMBER>
 *
 * Return Value:
 * A two digit zero padded string representation of the provided number <STRING>
 *
 * Examples:
 * [5] call potato_core_fnc_zeroPadNumber; // returns "05"
 * [17] call potato_core_fnc_zeroPadNumber; // return "17"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_number"];

if (_number < 10) then {
    format ["0%1", _number]
} else {
    str _number
}
