#include "script_component.hpp"

/*
 * Author: Bailey
 * Cleans up cells
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_cleanupPFH;
 *
 * Public: No
 */

private _cellsToCleanup = [];
{
    _y params ["_sideLength", "_deadUnits", "_lastTimeObserved"];
    if (CBA_missionTime - _lastTimeObserved >= TIME_BEFORE_CLEANUP) then {
        _cellsToCleanup pushBack [_x];
    };
} forEach GVAR(cells);

{
    _x params ["_key"];
    [_key] call FUNC(cleanCell);
} forEach _cellsToCleanup;