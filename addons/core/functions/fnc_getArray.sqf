/*
 * Author: AACO
 * Function used to convert a config path to an array, with optional fallback
 *
 * Arguments:
 * 0: The config path to convert <CONFIG>
 * 1: The fallback value, default [] <ARRAY>
 *
 * Return Value:
 * The parsed array from the config path. If the path isn't an array will
 * return the specified default value or [] if it isn't <ARRAY>
 *
 * Examples:
 * [configFile >> "thisIsAnArray"] call potato_core_fnc_getArray; // returns value in path
 * [configFile >> "thisIsNotAnArray"] call potato_core_fnc_getArray; // returns []
 * [configFile >> "thisIsAnArray", ['default']] call potato_core_fnc_getArray; // returns value in path
 * [configFile >> "thisIsNotAnArray", ['default']] call potato_core_fnc_getArray; // returns ['default']
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_config", configFile, [configFile]],
    ["_defaultValue", [], [[]]]
];

if (isArray _config) then {
    getArray _config
} else {
    _defaultValue
}
