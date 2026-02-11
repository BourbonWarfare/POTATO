#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Recursive function that manages a single gun firing on an elliptical area
 * using a specified magazine, gun, and gunner. A round delay can be specified,
 * or if the delay is less than 0 the config value is used. The relevant
 * artillery piece has it's magazines and weapons manipulated to load a single
 * round and then fire that round within an ellipse. The number of rounds to
 * fire, _rounds, is decremented each time the function calls itself
 *
 * Arguments:
 * _gunner - The gunner of the artillery piece, OBJECT
 * _artillery - The artillery piece to shoot, OBJECT
 * _targetPoSAGL - The center of the target area in AGL format, ARRAY
 * _radius - The minor axis of the area to be fired on, NUMBBER
 * _magazine - The magazine the artillery piece should fire, STRING
 * _weaponPars - Array of both the weapon and turret, ARRAY
 * _rounds - The number of rounds to fire, NUMBER
 * _rotMat - A 2D rotation matrix to adjust the angle the beaten zone is shaped, ARRAY, default I
 * _avoidList - A list of objects to avoid hitting. ARRAY, default []
 * _roundDelay - Simulated time between shots. NUMBER, default -1
 *
 * Return:
 * None
 *
 * Example:
 * [gunner arty0, arty0, getPosATL player, 200, "artilleryMag", "artilleryWeapon", 10] call potato_artillery_fnc_fireOnPos;
 *
 * Public: No
 */
params [
  "_gunner",
  "_artillery",
  "_targetPosAGL",
  "_radius",
  "_magazine",
  "_weaponPars",
  "_rounds",
  ["_rotMat", [[1, 0], [0, 1]]],
  ["_avoidList", []],
  ["_reloadTime", -1]
];

if (_artillery getVariable [QGVAR(artyMission), []] isEqualTo []) exitWith {};

if !(alive _artillery && alive _gunner && _rounds > 0) exitWith {};

_weaponPars params ["_weapon", "_turret"];
if (magazinesAmmo _artillery isNotEqualTo []) exitWith {
  if (_artillery magazineTurretAmmo [_magazine, _turret] == 0) then {
    _artillery setMagazineTurretAmmo [_magazine, 1, _turret];
  };
  [{_this call FUNC(fireOnPos)}, _this, 0.25] call CBA_fnc_waitAndExecute;
};
if (_reloadTime < 0 && _rounds > 1) then {
    _reloadTime = (_weapon call FUNC(getArtyReloadTime)) + random 1;
    _this set [9, _reloadTime];
};

_artillery removeWeaponTurret [_weapon, _turret];
{
  _artillery removeMagazinesTurret [_x,  _turret];
} forEach getArtilleryAmmo [_artillery];

if (_artillery currentMagazineTurret _turret != "") then {
  _artillery removeMagazineTurret [_artillery currentMagazineTurret _turret, _turret];
};
_artillery addMagazineTurret [_magazine, _turret, 1];

[
  {
    params ["_artillery", "_weapon", "_gunner", "_targetPosAGL", "_radius", "_magazine", "_rotMat", "_avoidList", "_turret"];
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
  [_artillery, _weapon, _gunner, _targetPosAGL, _radius, _magazine, _rotMat, _avoidList, _turret],
  1
] call CBA_fnc_waitAndExecute;

if (_rounds <= 1) then {
    [{ // free gun
        params ["_artillery", "_magazine", "_turret"];
        _artillery setVariable [QGVAR(artyMission), nil];
        _artillery removeMagazinesTurret [_magazine, _turret];
    }, [_artillery, _magazine, _turret], 7 max _reloadTime] call CBA_fnc_waitAndExecute;
} else {
  _this set [6, _rounds - 1];
  [{call FUNC(fireOnPos)}, _this, 7 max _reloadTime] call CBA_fnc_waitAndExecute;
}
