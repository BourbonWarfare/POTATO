#include "..\script_component.hpp"
/**************************************************************//*
* Helper function that fires mortar rounds
*
* Arguments:
* _tPos - target position
* _dist - min distance from _tPos to search
* _dir - direction from _tPos to search
* _avoidList - list of targets to ignore
*//**************************************************************/
params [
  "_gunner",
  "_artillery",
  "_targetPosAGL",
  "_radius",
  "_magazine",
  "_weapon",
  "_rounds",
  ["_rotMat", [[1, 0], [0, 1]]],
  ["_avoidList", []],
  ["_reloadTime", -1]
];

if !(alive _artillery && alive _gunner && _rounds > 0) exitWith {};

if (magazinesAmmo _artillery isNotEqualTo []) exitWith {
  if (_artillery magazineTurretAmmo [_magazine, [0]] == 0) then {
    _artillery setMagazineTurretAmmo [_magazine, 1, [0]];
  };
  [{_this call FUNC(fireOnPos)}, _this, 0.25] call CBA_fnc_waitAndExecute;
};

if (_reloadTime < 0 && _rounds > 1) then {
    _reloadTime = (_weapon call FUNC(getArtyReloadTime)) + random 1;
    _this set [9, _reloadTime];
};

removeAllWeapons _artillery;
{
  _artillery removeMagazinesTurret [_x,  [0]];
} forEach getArtilleryAmmo [_artillery];

if (_artillery currentMagazineTurret [0] != "") then {
  _artillery removeMagazineTurret [_artillery currentMagazineTurret [0], [0]];
};

_artillery addMagazineTurret [_magazine, [0], 1];

[
  {
    params ["_artillery", "_weapon", "_gunner", "_targetPosAGL", "_radius", "_magazine", "_rotMat", "_avoidList"];
    _artillery addWeapon _weapon;
    private _angle = random 360;
    private _rad = _radius * sqrt(random 1);
    private _offset = flatten (_rotMat matrixMultiply [[_rad * cos _angle],[ARTILLERY_ELLIPSE_COMPRESSION * _rad * sin _angle]]);
    private _targPos = _targetPosAGL vectorAdd _offset;
    if (_avoidList isNotEqualTo []) then {
        _targPos = [_targPos, 30, random 360, _avoidList] call FUNC(findSafeMortarPos);
    };
    _gunner doArtilleryFire [_targPos, _magazine, 1];
  },
  [_artillery, _weapon, _gunner, _targetPosAGL, _radius, _magazine, _rotMat, _avoidList],
  1
] call CBA_fnc_waitAndExecute;

if (_rounds <= 1) then {
    [{ // free gun
        params ["_artillery", "_magazine"];
        _artillery setVariable [QGVAR(artyMission), nil];
        _artillery removeMagazinesTurret [_magazine, [0]];
    }, [_artillery, _magazine], 7 max _reloadTime] call CBA_fnc_waitAndExecute;
} else {
  _this set [6, _rounds - 1];
  [{call FUNC(fireOnPos)}, _this, 7 max _reloadTime] call CBA_fnc_waitAndExecute;
}
