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

#define TEXT_VERY_HIGH "<font color='DARK_RED'>VERY HIGH</font>"
#define TEXT_HIGH "<font color='LIGHT_RED'>HIGH</font>"
#define TEXT_MED "<font color='ORANGE'>MEDIUM</font>"
#define TEXT_LOW "<font color='DARK_GREEN'>LOW</font>"
#define TEXT_VERY_LOW "<font color='LIGHT_GREEN'>VERY LOW</font>"

TRACE_1("params",_this);
params ["_value", "_min", "_range", ["_inverse", false]];

private _offsetValue = _value - _min;

if (_offsetValue <= (_range * 0.20)) exitWith {
    if (_inverse) then {
        TEXT_VERY_HIGH
    } else {
        TEXT_VERY_LOW
    }
};

if (_offsetValue <= (_range * 0.40)) exitWith {
    if (_inverse) then {
        TEXT_HIGH
    } else {
        TEXT_LOW
    }
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    TEXT_MED
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    if (_inverse) then {
        TEXT_LOW
    } else {
        TEXT_HIGH
    }
};

if (_inverse) then {
    TEXT_VERY_LOW
} else {
    TEXT_VERY_HIGH
}
