/*
 * Author: AACO
 * Function used to convert a number into a 24 hour HH:MM:SS formatted string
 *
 * Arguments:
 * 0: Number to convert (default CBA_missionTime) <NUMBER>
 *
 * Return Value:
 * A number into a 24 hour HH:MM:SS formatted string <STRING>
 *
 * Examples:
 * [5] call potato_core_fnc_getTimeText; // returns "00:00:05"
 * [61] call potato_core_fnc_getTimeText; // return "00:01:01"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_time", CBA_missionTime, [0]]];

_time = _time max 0;

[
    [floor (((_time / 60) / 60) % 24)] call FUNC(zeroPadNumber),
    [floor ((_time / 60) % 60)] call FUNC(zeroPadNumber),
    [floor (_time % 60)] call FUNC(zeroPadNumber)
] joinString ":"
