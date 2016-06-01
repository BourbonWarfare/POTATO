/*
 * Author: AACO
 * Function used to ensure a min/max set is properly ordered
 *
 * Arguments:
 * 0: The proposed minimum number <NUMBER>
 * 1: The proposed maximum number <NUMBER>
 *
 * Return Value:
 * Returns an array with: <ARRAY>
 *     0: The ensured minimum number <NUMBER>
 *     1: The ensured maximum number <NUMBER>
 *
 * Examples:
 * [1, 0] call potato_core_fnc_ensureMinMax; // returns [0,1]
 * [2, 0] call potato_core_fnc_ensureMinMax; // returns [0,2]
 * [0, 1] call potato_core_fnc_ensureMinMax; // returns [0,1]
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_inputMin","_inputMax"];

private _outputMin = _inputMin min _inputMax;
private _outputMax = _inputMin max _inputMax;

[_outputMin,_outputMax]
