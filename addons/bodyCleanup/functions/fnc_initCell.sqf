#include "script_component.hpp"

/*
 * Author: Bailey
 * Initialises grid cell which bodies are kept in
 *
 * Arguments:
 * 0: The side length of the grid cell <NUMBER>
 * 1: Units to inititally populate cell with <ARRAY>
 * 2: Position of cell in world <ARRAY>
 *
 * Return Value:
 * Cell key <ARRAY>
 * Cell data <ARRAY>
 *  Array in form ["_sideLength", "_deadUnits", "_lastTimeObserved", "_isHidden", "_position", "_key"]
 *                [Number,        Array,        Number,              Boolean,     Array,       Array]
 *
 * Example:
 * [50] spawn potato_bodyCleanup_fnc_initCell;
 *
 * Public: No
 */
params ["_sideLength", "_position"];

private _key = [
    floor ((_position select 0) / _sideLength),
    floor ((_position select 1) / _sideLength),
    0
];

// If cell exists in our hashmap, then we just return the cell that already exists rather than update
if (_key in GVAR(cells)) exitWith {
    [_key, GVAR(cells) get _key]
};

private _cell = [];

_cell pushBack _sideLength;
_cell pushBack [];
_cell pushBack CBA_missionTime;
_cell pushBack false;
_cell pushBack ((_key vectorMultiply _sideLength) vectorAdd [_sideLength / 2, _sideLength / 2, 0]);
_cell pushBack _key;

[_key, _cell]
