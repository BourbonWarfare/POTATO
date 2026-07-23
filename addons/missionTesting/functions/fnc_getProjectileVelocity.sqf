#define CONST_DT 5e-4
#define CONST_G -9.80665
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function takes a friction, initial velocity and an array of distances
* and returns an array of approximate velocities of the projectiles at the
* given ranges. The calculation is made assuming a level initial shot and the,
* distance as X-Y plan distance rather than full trajectory traveled.
* This calculation will be off by a few m/s. If a projectile is too slow
* to reach the given distances in three seconds, the result will be truncated
* to the longest distance.
*
* Arguments:
* _friction - The projectile friction (NUMBER)
* _v0 - The projectile initial velocity (NUMBER)
* _distance - (ARRAY, default [50, 100, 200, 300, 500])
*
* Return:
* Array of velocities matching each distance
*
* Example:
* [-0.01, 1000] call potato_missionTesting_fnc_getProjectileVelocity;
*//***************************************************************************/
params ["_friction", "_v0", ["_distances", [50, 100, 200, 300, 500]]];
private _v = [[_v0, 0]];
private _r = 0;

private _itr = 0;
private _index = 0;

private _velocities = [];
private _vMag = -1;
private _vIdx = [];
private _distCount = count _distances;
private _dr = 0;
while {_itr * CONST_DT < 3 && _index < _distCount} do {
    _vIdx = _v select -1;
    _vMag = vectorMagnitude _vIdx;
    _v pushBack [
        (_vIdx#0) + _friction * _vMag * (_vIdx#0) * CONST_DT,
        (_vIdx#1) + (CONST_G + _friction * _vMag * (_vIdx#1)) * CONST_DT
    ];
    _dr = (_vIdx#0) * CONST_DT / 2;
    _vIdx = _v select -1;
    _r = _r + (_vIdx#0) * CONST_DT / 2 + _dr;
    if (_r >= _distances#_index) then {
        _velocities pushBack vectorMagnitude _vIdx;
        _index = _index + 1;
    };
    _itr = _itr + 1;
};
_velocities
