/*
 * Author: AACO
 * Function used to try and parse prefilled ratio information
 *
 * Arguments:
 * 0: Array of prefill ratio data <ARRAY>
 * 1: Count of active sides <NUMBER>
 * 2: Index to pull the ratio data from <NUMBER>
 * 3: Ratio input control to prefill <CONTROL>
 * 4: Ratio check control to preset <CONTROL>
 *
 * Examples:
 * [_ratioArray,_ratioCount,0,RATIO_INPUT_1,RATIO_CHECK_1] call potato_ratios_prefillInput;
 * [_ratioArray,_ratioCount,1,RATIO_INPUT_2,RATIO_CHECK_2] call potato_ratios_prefillInput;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ratioArray","_ratioCount","_index","_inputControl","_checkControl"];

// setup the default return value
private _input = str 1;
private _check = false;

// skip if the index is out of bounds
if (_index < _ratioCount) then {
    private _stringToParse = (_ratioArray select _index);
    if (_stringToParse select ((count _stringToParse - 1)) == "C") then {
        _check = true;
    };

    // set the return value to the parsed number (if it's valid)
    private _ratioValue = parseNumber _stringToParse;
    if (_ratioValue > 0) then {
        _input = str _ratioValue;
    }
};

TRACE_2("setting",_input,_check);

_inputControl ctrlSetText _input;
_checkControl ctrlSetChecked _check;
