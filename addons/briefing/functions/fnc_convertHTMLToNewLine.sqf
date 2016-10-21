/*
 * Author: AACO
 * Function used to convert <br/> to \r inside a string
 *
 * Arguments:
 * 0: String to sanitize <STRING>
 *
 * Return Value:
 * String with <br/> instances replaced with \r <STRING>
 *
 * Examples:
 * ["test <br/> break"] call potato_briefing_fnc_convertHTMLToNewLine; // "test \r break"
 * ["why <br/> not?"] call potato_briefing_fnc_convertHTMLToNewLine; // "why \r not?"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params", _this);

params ["_input"];

(_input splitString "<br/>") joinString (toString [10])
