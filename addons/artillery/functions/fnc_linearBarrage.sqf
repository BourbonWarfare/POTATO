#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Local handler for creating a linear barrage mission. This function takes
 * arguments sent by the server for a linear barrage mission and creates an
 * array of targets to engage. It takes the beginning and end positions
 * and creates points along the spaced by the line length divided by _rounds.
 * Each point is added to a target array _barragesPerArea times. Once the
 * target area is constructed, it may be shuffled if _shufflePoints is true.
 * This target array is then passed to the fireOnArray function.
 *
 * Arguments:
 * _lineParams - An array of the start and end positions in ATL format, ARRAY
 * _artilleryGun - The artillery piece assigned to the mission, OBJECT
 * _magazine - The magazine the artillery piece should fire. STRING, default "CUP_30Rnd_122mmSMOKE_D30_M"
 * _rounds - The number of rounds to fire along the defined line. NUMBER, default 8
 * _barragesPerArea - The number of rounds to fire per each point along the line.
 *                    This number multiplies _rounds. NUBMER, default 1
 * _shufflePoints - Whether the points calculated along the line should be shuffled. BOOLEAN, default true
 *
 * Return:
 * None
 *
 * Example:
 * [[player getPos [100, 90], player getPos [100, -90]], d30_0] call potato_artillery_fnc_linearBarrage;
 *
 * Public: No
 */
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
