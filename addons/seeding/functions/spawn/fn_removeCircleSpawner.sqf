#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Delete the arc spawner.
*
* Arguments:
* _posASL - Center point to defend (Array, default [0, 0, 0]).
* _radius - Radius to search within to delete spawners (Scalar, default 200m).
*
* Return:
* None
*
* Example:
* [getPosASL player, 300] call lmd_fnc_removeCircleSpawner;
*//***************************************************************************/
params [
    ["_posASL", [0, 0, 0], [[]]],
    ["_radius", 200, [0, {}]]
];

if (_posASL isEqualTo [0, 0, 0] || _radius <= 0 ||
    isNil QGVAR(circleSpawners) || {GVAR(circleSpawners) isEqualTo []}) exitWith {};

private _deleteArr = [];
private _spawnerArr = GVAR(circleSpawners);
{
    if ((_x#1#0) distance2D _posASL < _radius) then {
        _deleteArr pushBack _forEachIndex;
    }
} forEach _spawnerArr;

{
    _spawnerArr deleteAt _x;
} forEachReversed _deleteArr;
