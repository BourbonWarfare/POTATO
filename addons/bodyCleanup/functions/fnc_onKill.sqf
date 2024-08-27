#include "script_component.hpp"

/*
 * Author: Bailey
 * Adds entity to dead pool for future cleanup
 *
 * Arguments:
 * 0: The entity which was killed <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] spawn potato_bodyCleanup_fnc_onKill;
 *
 * Public: No
 */
params ["_entity"];

private _cell = [CELL_SIZE, getPosASLVisual _entity] call FUNC(initCell);
_cell params ["_key", "_data"];

private _deadUnits = _data select 1;
_deadUnits pushBack _entity;
_cell set [1, _deadUnits];

GVAR(cells) set [_key, _data];

