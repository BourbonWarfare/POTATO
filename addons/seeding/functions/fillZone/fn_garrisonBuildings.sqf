#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function garrisons a nubmer of buildings using the potato HC passthrough
* to balance AI load. It begins by taking a position, radius, and optional
* marker (default ""). The marker is uesd to select only buildings within it
* for the given radius. The buildings are filled to a random percentage within
* within the bounds given by first the _occupyBounds.
* Finally, some units are allowed to move and won't have pathing disabled,
* to set the percentage that aren't static alter _chanceToMove, higher
* correlating to a lower chance of having pathing disabled.
*
* Arguments:
* _posATL - center of position of region to garrison (ARRAY).
* _radius - radius of area to garrison (SCALAR, default 50 m).
* _marker - Marker that sets bounds for buildings to be garrisoned (STRING, default "").
* _minToOccupy - The minimum units to put in a building (SCALAR< default 2).
* _occupyBounds - Min and max count of units per building, if < 1 then ratio of building (ARRAY, default [2, 6]).
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
    ["_minToOccupy", 2, [2]],
    ["_occupyBounds", [2, 6], [[]], [2]],
    ["_chanceToMove", 0.1, [0.1]],
    ["_canSkipBuildings", true, [true]],
    ["_sideGarrison", east, [east]],
    ["_allowMovementOnShot", true, [true]]
];

if (_posATL isEqualTo [0, 0, 0]) exitWith {};

private _buildings = _posATL nearObjects ["building", _radius];

if (_marker != "") then {
    _buildings = _buildings inAreaArray _marker;
};

_occupyBounds params ["_minUnits", "_maxUnits"];
private _sumPoses = 0;
private _posHash = createHashMap;
_minToOccupy = 1 max _minToOccupy;
{
    private _poses = _x buildingPos -1;
    private _countPoses = 15 min count _poses;
    switch (typeOf _x) do {
        case "Land_A_Crane_02a": {_countPoses = 0;};
        case "Land_A_Crane_02b": {_countPoses = 3;};
        case "Land_Trafostanica_velka": {_countPoses = [0, 1] selectRandomWeighted [2, 1]};
    };
    if (_countPoses >= _minToOccupy) then {
        _sumPoses = _sumPoses + _countPoses;
        _posHash set [_forEachIndex, [_countPoses, _x, _poses]];
    };
} forEach _buildings;

private _ratio = 0.8 min (_maxUnits/_sumPoses);
{
    _y params ["_countPoses"];
    _y set [0, _minUnits max _minToOccupy max round (_countPoses * _ratio)];
} forEach _posHash;

private _maxTime = 0;
private _unitSum = 0;
private _skipCount = 0;
private _delayTime = 1.5 * PGVAR(zeusHC,delayBetweenUnitCreation);
{
    _y params ["_countUnits", "_building"];

    if (_countUnits == 0 ||
        (_canSkipBuildings && _countUnits < _minUnits) ||
        (typeOf _building) in BW_IGNORE_GARRISON_BUILDINGS) then {
        _skipCount = _skipCount + 1;
        continue
    };
    _maxTime = _maxTime + _delayTime * _countUnits;

    [{
        [_this, "bw_fnc_garrisonBuilding"] call potato_zeusHC_fnc_hcPassthrough;
    }, [
        _building,
        _countUnits,
        0,
        _sideGarrison,
        true
    ], _maxTime] call CBA_fnc_waitAndExecute;
    _unitSum = _unitSum + _countUnits;
    if (_unitSum >= _maxUnits) exitWith {};
} forEach _posHash;
[_maxTime + 10, _unitSum]
