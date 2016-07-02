/*
 * Author: AACO
 * Function used to try and parse prefilled ratio information
 *
 * Arguments:
 * 0: Array of prefill ratio data <ARRAY>
 * 1: Count of active sides <NUMBER>
 * 2: Index to pull the ratio data from <NUMBER>
 *
 * Return Value:
 * The parsed ratio, 1 if the ratio couldn't be parsed <STRING>
 *
 * Examples:
 * [_ratioArray,_ratioCount,0] call potato_ratios_prefillInput;
 * [_ratioArray,_ratioCount,1] call potato_ratios_prefillInput;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ratioArray","_ratioCount","_index"];

// setup the default return value
private _returnString = str 1;

// skip if the index is out of bounds
if (_index < _ratioCount) then {
    private _ratioValue = parseNumber (_ratioArray select _index);

    // set the return value to the parsed number (if it's valid)
    if (_ratioValue > 0) then {
        _returnString = str _ratioValue;
    }
};

TRACE_1("return",_returnString);
_returnString
