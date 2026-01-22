#include "..\script_component.hpp"
/**************************************************************//*
* Divides N guns equally along a given line to barrage
*
* Arguments:
* _lineParams - array of two positions defining the line
* _artilleryPieces - array of guns to use to fufill the mission
* _magazine - Type of magazine to fire
* _rounds - Number of rounds per gun to fire
* _avoidList - optional list of targets to avoid
*
* Example:
* [getpos target, getpos mortarPos, units west, 4] execVM "mortarWarning.sqf";
*//**************************************************************/

// Initialization
params [
  "_lineParams",
  "_artilleryGun",
  ["_magazine", "CUP_30Rnd_122mmSMOKE_D30_M"],
  ["_rounds", 8],
  ["_barragesPerArea", 1],
  ["_shufflePoints", true]
];

_lineParams params [
    ["_beginPosATL", [0, 0, 0]],
    ["_endPosATL", [0, 0, 0]]
];
if (_beginPosATL isEqualTo [0, 0, 0] || _endPosATL isEqualTo [0, 0, 0]
    || !alive _artilleryGun) exitWith {};

private _step = (_endPosATL vectorDiff _beginPosATL) vectorMultiply 1/(_rounds-1);
private _pointsToHit = [];
for "_i" from 1 to _rounds do {
    for "_j" from 1 to _barragesPerArea do {
        _pointsToHit pushBack _beginPosATL;
    };
    _beginPosATL = _beginPosATL vectorAdd _step;
};


if (_shufflePoints) then {
    [_pointsToHit, true] call CBA_fnc_shuffle;
};

[_artilleryGun, _pointsToHit, _magazine] call FUNC(fireOnArray);
