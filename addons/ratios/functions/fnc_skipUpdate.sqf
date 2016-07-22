/*
 * Author: AACO
 * Function used to check if the ratio display should be updated
 *
 * Arguments:
 * 0: Ratio #1 input text <STRING>
 * 1: Ratio #2 input text <STRING>
 * 2: Ratio #3 input text <STRING>
 * 3: Number of players in the server <NUMBER>
 * 4: Check #1 value <BOOL>
 * 5: Check #2 value <BOOL>
 * 6: Check #3 value <BOOL>
 *
 * Return Value:
 * True if the ratio update can be skipped, false otherwise <BOOL>
 *
 * Examples:
 * [_ratioInput1, _ratioInput2, _ratioInput3, _players, _ratioChecked1, _ratioChecked2, _ratioChecked3] call potato_ratios_skipUpdate;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_radioInput1","_radioInput2","_radioInput3"];

// if all the inputs are empty, exit with TRUE
if (_radioInput1 == "" && {_radioInput2 == ""} && {_radioInput3 == ""}) exitWith { true };

// if this is the first run, set the last value var, and exit with FALSE
private _lastValues = GET_UI_VAR(lastValues);
if (isNil "_lastValues") exitWith { SET_UI_VAR(lastValues,_this); false };

// if the inputs haven't changed, exit with TRUE
if (_this isEqualTo _lastValues) exitWith { true };

// otherwise, set the last input, to the current input and finish with FALSE
SET_UI_VAR(lastValues,_this);
false
