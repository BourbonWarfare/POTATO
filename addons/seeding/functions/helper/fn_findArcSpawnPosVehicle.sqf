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
* [] call bw_fnc_findArcSpawnPosVehicle;
******************************************************************************/
params [
    ["_center", [0, 0, 0], [[]]],
    ["_hideFromSide", east, [east]],
    ["_rad", 800, [800]],
    ["_angleParms", [0, 360, 20], []]
];
if (_center isEqualTo [0, 0, 0]) exitWith {[0, 0, 0]};

_angleParms params [
    ["_minAngle", 0, [0]],
    ["_maxAngle", 360, [360]]
];
private _unitEyePosASL = (units _hideFromSide select {_x distance _center < 2500 && ({(ASLToAGL getPosASL _x)#2 < 25})}) apply {ASLToAGL eyePos _x};

private _itr = 0;
private _exit = false;
private _posToSpawn = [0, 0, 0];
private _arcLength = _maxAngle - _minAngle;
private _stepSize = 360 * 400 / (_rad * 2 * pi);
private _dir = random _arcLength;
_dir = _minAngle + _dir;
private _steps = ceil (_arcLength / _stepSize);
private _road = objNull;
while {!_exit && _itr < _steps} do {
    private _testPos = _center getPos [_rad, _dir];
    _dir = (((_dir - _minAngle) + _stepSize) mod _arcLength) + _minAngle;
    _itr = _itr + 1;
    if (surfaceIsWater _testPos) then {continue;};
    _testPos = _testPos nearRoads 200;
    if (_testPos isEqualTo []) then {continue;};
    _road = selectRandom _testPos;
    _testPos = getPosASL _road;
    _testPos set [2, 2.5];
    {
        _exit = _exit || !terrainIntersect [_x, _testPos];
    } forEach _unitEyePosASL;
    if (!_exit) then {
        _exit = true;
        _posToSpawn = +_testPos;
    };
};
_posToSpawn set [2, 0];
[_posToSpawn, _road]
