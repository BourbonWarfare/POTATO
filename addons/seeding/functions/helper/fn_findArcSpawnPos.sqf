#include "..\..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This function displays gear and setting deviations from "standard."
* Focusing on navigation tools like GPS, night vision / flashlight equipment,
* settings like group markers. This setting does expect to find
*
* Arguments:
* 0: The center of
*
* Return:
* None
*
* Example:
* [] call lmd_fnc_findArcSpawnPos;
******************************************************************************/
params [
    ["_center", [0, 0, 0], [[]]],
    ["_hideFromSide", east, [east]],
    ["_rad", 800, [800]],
    ["_angleCount", [], [[]]],
    ["_minRad", 400, [400]],
    ["_angleParms", [0, 360, 20], []]
];
if (_center isEqualTo [0, 0, 0]) exitWith {[0, 0, 0]};

_rad = _rad max _minRad;
_angleParms params [
    ["_minAngle", 0, [0]],
    ["_maxAngle", 360, [360]],
    ["_stepSize", 20, [20]]
];
private _unitEyePosASL = (units _hideFromSide select {_x distance _center < 2500 && ({(ASLToAGL getPosASL _x)#2 < 25})}) apply {ASLToAGL eyePos _x};

/*{
    if ("testSpotMark" in _x) then {deleteMarker _x};
} forEach allMapMarkers;*/
/*private _mk = createMarker ["testSpotMark_" + str _itr, _posToSpawn];
_mk setMarkerType "mil_dot_noshadow";*/
if (count _angleCount < ceil ((_maxAngle - _minAngle)/_stepSize)) then {
    _angleCount resize [ceil ((_maxAngle - _minAngle)/_stepSize), 0];
};
private _minDir = selectMin _angleCount;
private _canSee = true;
private _posToSpawn = [0, 0, 0];
private _dir = random (_maxAngle - _minAngle);
while {_minDir < _angleCount#(floor (_dir/20))} do {
    _dir = random (_maxAngle - _minAngle);
};
_angleCount set [floor (_dir/20), _minDir + 1];
_dir = _minAngle + _dir;
while {_canSee && _rad < 3500 && _rad >= _minRad} do {
    private _angle = _dir + random 10;
    private _testPos = _center getPos [_rad, _angle];
    _testPos set [2, 2.5];
    _canSee = false;
    if (surfaceIsWater _testPos) then {continue;};
    {
        _canSee = _canSee || !terrainIntersect [_x, _testPos];
    } forEach _unitEyePosASL;
    if (!_canSee) then {
        _posToSpawn = +_testPos;
        _canSee = true;
    };
    _rad = _rad - 50;
};
_posToSpawn set [2, 0];
_posToSpawn
