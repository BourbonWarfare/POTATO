/*
 * Author: Lambda.Tiger
 * Helper function that finds artillery positions far from objects
 * on the avoid list
 *
 * Arguments:
 * _tPos - target position, ARRAY, posATL
 * _dist - min distance from _tPos to search, NUMBER
 * _dir - direction from _tPos to search, NUMBER
 * _avoidList - list of targets to ignore, ARRAY
 *
 * Return:
 * None
 *
 * Example:
 * [getPosATL player, 250, 90, [player]] call potato_artillery_fnc_findSafeMortarPos;
 *
 * Public: No
 */
params ["_tPos", "_dist", "_dir", "_avoidList"];

private _farEnough = true;
private _mTarg = _tPos getPos [_dist + (random 50), _dir + (random 40)];
{
  if (_x distance2D _mTarg < 50) then
  {
    _farEnough = false;
    break;
  };
} forEach _avoidList;
if (_farEnough) exitWith {_mTarg};

_dir = _dir - 20;

_mTarg = _tPos getPos [_dist + (random 50), _dir + (random 40)];
{
  if (_x distance2D _mTarg < 50) then
  {
    _farEnough = false;
    break;
  };
} forEach _avoidList;

private _loopCount = 20;
while {!_farEnough && _loopCount > 0} do {
  _dist = _dist + 10;
  _mTarg = _tPos getPos [_dist + (random 50), _dir + (random 40)];
  _farEnough = true;
  {
    if ((_x distance2D _mTarg) < 50) exitWith {
      _farEnough = false;
      _mTarg = [0, 0, 0];
    };
  } forEach _avoidList;
  _loopCount = _loopCount - 1;
};

_mTarg
