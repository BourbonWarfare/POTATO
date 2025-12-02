/*
 * Author: AACO
 * Function used to convert \r to <br/> inside a string
 *
 * Arguments:
 * 0: Value <NUMBER>
 * 1: Min <NUMBER>
 * 2: Range <NUMBER>
 * 3: Inverse colors <BOOL>(Default: false)
 *
 * Return Value:
 * String with \r instances replaced with <br/> <STRING>
 *
 * Examples:
 * [0, 1, 2, false] call potato_briefing_fnc_displayDanger
 *
 * Public: Yes
 */

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

private _offsetValue = _value - _min;

if (_offsetValue <= (_range * 0.20)) exitWith {
    [TEXT_VERY_LOW, INVERSE_TEXT_VERY_LOW] select _inverse;
};

if (_offsetValue <= (_range * 0.40)) exitWith {
    [TEXT_LOW, INVERSE_TEXT_LOW] select _inverse;
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    TEXT_MED
};

if (_offsetValue <= (_range * 0.60)) exitWith {
    [TEXT_HIGH, INVERSE_TEXT_HIGH] select _inverse
};


[TEXT_VERY_HIGH, INVERSE_TEXT_VERY_HIGH] select _inverse
