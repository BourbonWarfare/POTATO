/*
 * Author: AACO
 * Function used to ensure a min/max set is within a range and is properly ordered
 *
 * Arguments:
 * 0: The proposed minimum number <NUMBER>
 * 1: The proposed maximum number <NUMBER>
 * 3: The lower bound used to validate <NUMBER>
 * 4: The upper bound used to validate <NUMBER>
 *
 * Return Value:
 * Returns an array with: <ARRAY>
 *     0: The ensured minimum number within a range <NUMBER>
 *     1: The ensured maximum number within a range <NUMBER>
 *
 * Examples:
 * [1, 0, 0, 1] call potato_core_fnc_ensureBoundedMinMax; // returns [0,1]
 * [2, 0, 0, 1] call potato_core_fnc_ensureBoundedMinMax; // returns [0,1]
 * [0, 1, 0.5, 1] call potato_core_fnc_ensureBoundedMinMax; // returns [0.5, 1]
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_inputMin","_inputMax","_lowerBound","_upperBound"];

_inputMin = [_inputMin, _lowerBound, _upperBound] call FUNC(ensureRange);
_inputMax = [_inputMax, _lowerBound, _upperBound] call FUNC(ensureRange);

[_inputMin, _inputMax] call FUNC(ensureMinMax)
