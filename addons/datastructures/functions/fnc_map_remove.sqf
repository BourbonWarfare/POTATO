/*
 * Remove key from map.
 *
 * Arguments:
 * 0: Map Datastructure <ARRAY>
 * 1: Key <ANY>
 *
 * Return Value:
 * Deleted Value, nil if no matching key found <ANY>
 */
#include "script_component.hpp"

params ["_map", "_key"];

_map params ["_keys", "_values"];

if (!(_key in _keys)) exitWith {nil};

private _index = _keys find _key;

_keys deleteAt _index;
_values deleteAt _index
