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

TRACE_1("params",_this);
params ["_input"];

private _output = _input;

private _index = _output find "<br/>";
while {_index > -1} do {
    if (_index + 5 >= count _output) then {
        _output = format ["%1%2", _output select [0, _index], toString [10]];
    } else {
        _output = format ["%1%2%3", _output select [0, _index], toString [10], _output select [_index + 5]];
    };
    _index = _output find "<br/>";
};

TRACE_1("output",_output);
_output
