#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
* Arguments:
* _posATL - center of position of region to garrison (ARRAY).
* _marker - Marker that sets bounds for buildings to be garrisoned (STRING, default "").
* _patrolCount - Number of patrols to make (SCALAR, 2).
* _patrolSize - Number of units in a patrol (SCALAR, 3).
* _sidePatrols - Side of the garrison units (SIDE, east).
* _patrolPerimeter - Should the units patrol the perimeter instead of everywhere (BOOL, false).
*
* Return:
* The number of patroling units spawned
*
* Example:
* ["zone_0", 3, 10, east] call bw_fnc_spawnPatrols;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_patrolCount", 2, [2]],
    ["_patrolSize", 3, [3]],
    ["_sidePatrols", east, [east]],
    ["_patrolPerimeter", false, [false]]
];

if (_marker == "" ||
    _patrolCount == 0 ||
    _patrolSize == 0) exitWith {};
// Randomize patrol size
private _randomSize = [0.75, 1, 1.25] apply {_patrolSize * _x};
private _perimiterOffset = 0;
private _unitSum = 0;
for "_i" from 1 to _patrolCount do { // spawn N patrols
    private _directionConst = selectRandom [-1, 1];
    _perimiterOffset = _perimiterOffset + 8.7 + random 0.6;
    private _unitCount = round random _randomSize;
    _unitSum = _unitSum + _unitCount;
    [{
        [_this, QFUNC(spawnPatrol)] call PFUNC(zeusHC,hcPassthrough);
    }, [_marker, _unitCount, _sidePatrols, _perimiterOffset, _patrolPerimeter],
        _i * 5 *  PGVAR(zeusHC,delayBetweenUnitCreation)
    ] call CBA_fnc_waitAndExecute;
};

_unitSum
