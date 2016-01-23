/*
 * Put new key value combination in the map.
 *
 * Arguments:
 * 0: Map Datastructure <ARRAY>
 * 1: Key <ANY>
 * 2: Value <ANY>
 *
 * Return Value:
 * Assigned Map Index (volatile on map changes) <NUMBER>
 */
#include "script_component.hpp"

params ["_map", "_key", "_value"];

_map params ["_keys", "_values"];

private _index = if (_key in _keys) then {
    _keys find _key
} else {
    _keys pushBack _key
};

_values set [_index, _value];

_index
