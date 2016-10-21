/*
 * Author: AACO
 * Function used to convert \r to <br/> inside a string
 *
 * Arguments:
 * 0: String to sanitize <STRING>
 *
 * Return Value:
 * String with \r instances replaced with <br/> <STRING>
 *
 * Examples:
 * ["test \r break"] call potato_briefing_fnc_convertNewLineToHTML; // "test <br/> break"
 * ["why \r not?"] call potato_briefing_fnc_convertNewLineToHTML; // "why <br/> not?"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params", _this);

params ["_input"];

(_input splitString (toString [9] + toString [10])) joinString "<br/>"
