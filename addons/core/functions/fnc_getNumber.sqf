/*
 * Author: AACO
 * Function used to convert a config path to a number, with optional fallback
 *
 * Arguments:
 * 0: The config path to convert <CONFIG>
 * 1: The fallback value <NUMBER> (default: 0)
 *
 * Return Value:
 * The parsed number from the config path. If the path isn't a number will
 * return the specified default value or 0 if it isn't <NUMBER>
 *
 * Examples:
 * [configFile >> "thisIsANumber"] call potato_core_fnc_getNumber; // returns value in path
 * [configFile >> "thisIsNotANumber"] call potato_core_fnc_getNumber; // returns 0
 * [configFile >> "thisIsANumber", 6969] call potato_core_fnc_getNumber; // returns value in path
 * [configFile >> "thisIsNotANumber", 6969] call potato_core_fnc_getNumber; // returns 6969
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_config", configFile, [configFile]],
    ["_defaultValue", 0, [0]]
];

if (isNumber _config) then {
    getNumber _config
} else {
    _defaultValue
}
