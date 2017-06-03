/*
 * Helper method to create a value that has the correct format for a map
 *
 * Arguments:
 * 0: Array of pairs <ARRAY>
 *
 * Return Value:
 * Created Map structure <ARRAY>
 */
#include "script_component.hpp"

#define DEFAULT_STRUCTURE [[], []]

params [["_pairs", [], [[]]]];

if (_pairs isEqualTo []) exitWith {DEFAULT_STRUCTURE};

private _result = DEFAULT_STRUCTURE;

_pairs params ["_keys", "_values"];

{
    _x params ["_key", "_value"];
    [_result, _key, _value] call FUNC(map_put);
} forEach _pairs;

_result
