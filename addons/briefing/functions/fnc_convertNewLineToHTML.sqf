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

private _output = _input;

private _index = _output find (toString [10]);
while {_index > -1} do {
 if (_index >=  count _output) then {
     _output = format ["%1<br/>", _output select [0, _index]];
 } else {
     _output = format ["%1<br/>%2", _output select [0, _index], _output select [_index + 1]];
 };
 _index = _output find (toString [10]);
};

TRACE_1("output", _output);
_output
