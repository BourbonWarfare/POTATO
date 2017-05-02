/*
 * Author: AACO
 * Function used to convert a config path to a string, with optional fallback
 *
 * Arguments:
 * 0: The config path to convert <CONFIG>
 * 1: The fallback value, default "" <STRING>
 *
 * Return Value:
 * The parsed string from the config path. If the path isn't a string will
 * return the specified default value or "" if it isn't <STRING>
 *
 * Examples:
 * [configFile >> "thisIsAString"] call potato_core_fnc_getText; // returns value in path
 * [configFile >> "thisIsNotAString"] call potato_core_fnc_getText; // returns ""
 * [configFile >> "thisIsAString", "sixtyninesixtynine"] call potato_core_fnc_getText; // returns value in path
 * [configFile >> "thisIsNotAString", "sixtyninesixtynine"] call potato_core_fnc_getText; // returns "sixtyninesixtynine"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_config", configFile, [configFile]],
    ["_defaultValue", "", [""]]
];

if (isText _config) then {
    getText _config
} else {
    _defaultValue
}
