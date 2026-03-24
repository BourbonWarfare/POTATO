#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function finds road positions and retursn a begin and end position
* of the closest road within a radius (default 50 m) of the given position.
*
* Arguments:
* 0: Position ATL to search around (default [0, 0, 0])
* 1: Radius in meters to search (default 50 m)
*
* Return:
* Road position ATL and road direction
*
* Example:
* [getPosATL player, 25] call bw_fnc_findRoadPos;
*//***************************************************************************/
params [
    ["_posATL", [0, 0, 0], [[]]],
    ["_radius", 50]
];
diag_log text str _this;

if (_posATL isEqualTo [0, 0, 0]) exitWith {
    [[0, 0, 0], 0]
};

private _roads = (_posATL nearRoads _radius) apply {[_posATL distance2D _x, _x]};
if (_roads isEqualTo []) exitWith {
    [[0, 0, 0], 0]
};
_roads sort true;
private _road = _roads#0#1;
(getRoadInfo _road) params ["", "", "", "", "", "", "_begPos", "_endPos"];

diag_log text str [getPosATL _road, _begPos getDir _endPos];
[getPosATL _road, _begPos getDir _endPos]
