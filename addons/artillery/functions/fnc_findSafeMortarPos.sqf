/**************************************************************//*
* Helper function that finds mortar points far from avoid list
*
* Arguments:
* _tPos - target position
* _dist - min distance from _tPos to search
* _dir - direction from _tPos to search
* _avoidList - list of targets to ignore
*//**************************************************************/
params ["_tPos", "_dist", "_dir", "_avoidList"];

private _farEnough = true;
{
  if (_x distance2D _tPos < 50) then
  {
    _farEnough = false;
    break;
  };
} forEach _avoidList;
if (_farEnough) exitWith {_tPos};

_dir = _dir - 20;

private _mTarg = _tPos getPos [_dist + (random 50), _dir + (random 40)];
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
