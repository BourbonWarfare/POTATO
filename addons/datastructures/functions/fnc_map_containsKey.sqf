/*
 * Checks if the map contains the given key.
 *
 * Arguments:
 * 0: Map Datastructure <ARRAY>
 * 1: Key <ANY>
 *
 * Return Value:
 * Has Key <BOOL>
 */
#include "script_component.hpp"

params ["_map", "_key"];

_map params ["_keys"];

_key in _keys
