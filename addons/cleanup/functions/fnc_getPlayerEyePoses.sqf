/*
 * Author: AACO
 * Function used get all player eye positions
 *
 * Examples:
 * [] call potato_cleanup_fnc_getPlayerEyePoses;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);

private _positions = [];
{
    if (isPlayer _x) then {
        _positions pushBackUnique eyePos vehicle _x;
    };
} forEach allUnits;

_positions
