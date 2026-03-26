#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function garrisons a nubmer of buildings using the potato HC passthrough
* to balance AI load. It begins by taking a position, radius, and optional
* marker (default ""). The marker is uesd to select only buildings within it
* for the given radius. The buildings are filled to a random percentage within
* within the bounds given _occupyBounds.
* Finally, some units are allowed to move and won't have pathing disabled,
* to set the percentage that aren't static alter _chanceToMove, higher
* correlating to a lower chance of having pathing disabled.
*
* Arguments:
* _posATL - center of position of region to garrison (ARRAY).
* _radius - radius of area to garrison (SCALAR, default 50 m).
* _marker - Marker that sets bounds for buildings to be garrisoned (STRING, default "").
* _spawnConstant - Constant for exponential distance modifier (SCALAR, default 8).
* _occupyBounds - Min and max count of units per building (ARRAY, default [2, 6]).
* _chanceToMove - Chance that any one garrisoned unit will leave their position and move (SCALAR, default 0.1).
* _canSkipBuildings - Whether to skip buildings under the bar (BOOL, default true).
* _sideGarrison - Side of the garrison units (SIDE, east).
* _allowMovementOnShot - When shot near, allow a unit to move (BOOL, true).
*
* Return:
* Returns an array cotaining:
*  0: Time until the buildings will be occupied (SCALAR)
*  1: The number of units that will be spawned (SCALAR)
*
* Example:
* [getPosATL player, 50, "zone_0", [1, 1], [0, 100], 0.1] call bw_fnc_garrisonBuildings;
*//***************************************************************************/
if !(isServer) exitWith {};
params [
    ["_posATL", [0, 0, 0], [[]], [3]],
    ["_radius", 50, [50]],
    ["_marker", "", [""]],
    ["_spawnConstant", 8, [8]],
    ["_occupyBounds", [2, 6], [[]], [2]],
    ["_chanceToMove", 0.1, [0.1]],
    ["_canSkipBuildings", true, [true]],
    ["_sideGarrison", east, [east]],
    ["_allowMovementOnShot", true, [true]]
];

if (_posATL isEqualTo [0, 0, 0]) exitWith {
    diag_log formatText ["[SEED][Garrison Buidlings] Bad position given: %1", _posATL];
};

private _buildings = _posATL nearObjects ["building", _radius];

if (_marker != "") then {
    _buildings = _buildings select {0 < count (_x buildingPos -1) && _x inArea _marker};
} else {
    _buildings = _buildings select {0 < count (_x buildingPos -1)};
};

_occupyBounds params ["_minUnits", "_maxUnits"];
private _maxTime = 0;
private _unitSum = 0;
private _skipCount = 0;
private _expConstant = -5 / _radius;
{
    private _building = _x;
    private _countPoses = count (_building buildingPos -1);
    private _distance = _posATL distance2D _building;
    private _countUnits = _maxUnits min _countPoses min round (_spawnConstant * exp(_expConstant * _distance));

    if (_countUnits == 0 ||
        (_canSkipBuildings && _countUnits < _minUnits) ||
        (typeOf _building) in BW_IGNORE_GARRISON_BUILDINGS) then {
        _skipCount = _skipCount + 1;
        continue
    };
    _countUnits = round _countUnits;
    _maxTime = 2.05 * (_forEachIndex - _skipCount);
    [{
        [_this, QFUNC(garrisonBuilding)] call PFUNC(zeusHC,hcPassthrough);
    }, [
        _building,
        _countUnits,
        _chanceToMove,
        _sideGarrison
    ], _maxTime] call CBA_fnc_waitAndExecute;
    _unitSum = _unitSum + _countUnits;
} forEach _buildings;

[_maxTime + 10, _unitSum]
