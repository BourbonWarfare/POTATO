/*
 * Author: AACO
 * Function used to get a random value between an ordered min/max set
 *
 * Arguments:
 * 0: The ensured minimum number (inclusive) <NUMBER>
 * 1: The ensured maximum number (exclusive) <NUMBER>
 *
 * Return Value:
 * Random number between the min (inclusive) and the max (exclusive): <NUMBER>
 *
 * Examples:
 * [0, 1] call potato_core_fnc_getBoundedRandom; // random number between 0 and 1
 * [2, 5] call potato_core_fnc_getBoundedRandom; // random number between 2 and 5
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_min","_max"];

_min + round (random (_max - _min))
