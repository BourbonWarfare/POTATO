/*
 * Author: AACO
 * Function used to convert a config path to a boolean, with optional fallback
 *
 * Arguments:
 * 0: The config path to convert <CONFIG>
 * 1: The fallback value, default false <BOOL>
 *
 * Return Value:
 * The parsed boolean from the config path. If the path isn't a number/string will
 * return the specified default value or false if it isn't <BOOL>
 *
 * Examples:
 * [configFile >> "thisIsANumber1"] call potato_core_fnc_getBoolean; // returns true
 * [configFile >> "thisIsANumber0"] call potato_core_fnc_getBoolean; // returns false
 * [configFile >> "thisIsAString1"] call potato_core_fnc_getBoolean; // returns true
 * [configFile >> "thisIsAString0"] call potato_core_fnc_getBoolean; // returns false
 * [configFile >> "thisIsAStringTrue"] call potato_core_fnc_getBoolean; // returns true
 * [configFile >> "thisIsAStringFalse"] call potato_core_fnc_getBoolean; // returns false
 * [configFile >> "thisIsAStringGibberish"] call potato_core_fnc_getBoolean; // returns false
 * [configFile >> "thisIsNotANumberOrString"] call potato_core_fnc_getBoolean; // returns false
 * [configFile >> "thisIsNotANumberOrString", true] call potato_core_fnc_getBoolean; // returns true
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_config", configFile, [configFile]],
    ["_defaultValue", false, [false]
];

if (isNumber _config) exitWith {
    [getNumber _config] call FUNC(parseBoolean);
};

if (isText _config) exitWith {
    [getText _config] call FUNC(parseBoolean);
};

_defaultValue
