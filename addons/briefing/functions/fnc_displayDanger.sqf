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
#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define TEXT_VERY_HIGH "<font color='#FF0000'>VERY HIGH</font>"
#define TEXT_HIGH "<font color='#FF4A4A'>HIGH</font>"
#define TEXT_MED "<font color='#FFAF2E'>MEDIUM</font>"
#define TEXT_LOW "<font color='#11AD00'>LOW</font>"
#define TEXT_VERY_LOW "<font color='#00E823'>VERY LOW</font>"

#define INVERSE_TEXT_VERY_HIGH "<font color='#00E823'>VERY HIGH</font>"
#define INVERSE_TEXT_HIGH "<font color='#11AD00'>HIGH</font>"
#define INVERSE_TEXT_LOW "<font color='#FF4A4A'>LOW</font>"
#define INVERSE_TEXT_VERY_LOW "<font color='#FF0000'>VERY LOW</font>"

TRACE_1("params",_this);
params ["_value", "_min", "_range", ["_inverse", false, [false]]];
TRACE_1("", _inverse);

private _offsetValue = _value - _min;

if (_offsetValue <= (_range * 0.20)) exitWith {
    if (_inverse) then {
        INVERSE_TEXT_VERY_LOW
    } else {
        TEXT_VERY_LOW
    }
};

if (_offsetValue <= (_range * 0.40)) exitWith {
    if (_inverse) then {
        INVERSE_TEXT_LOW
    } else {
        TEXT_LOW
    }
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    TEXT_MED
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    if (_inverse) then {
        INVERSE_TEXT_HIGH
    } else {
        TEXT_HIGH
    }
};

if (_inverse) then {
    INVERSE_TEXT_VERY_HIGH
} else {
    TEXT_VERY_HIGH
}
