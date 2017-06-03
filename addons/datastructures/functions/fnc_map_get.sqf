/*
 * Get value by key from map.
 *
 * Arguments:
 * 0: Map Datastructure <ARRAY>
 * 1: Key <ANY>
 *
 * Return Value:
 * Value, nil if no matching key found <ANY>
 */
#include "script_component.hpp"

params ["_map", "_key"];

_map params ["_keys", "_values"];

if (!(_key in _keys)) exitWith {nil};

private _index = _keys find _key;

_values select _index
