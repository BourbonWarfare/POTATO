#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemyInput"];

private _gunner = objNull;
private _weapon = objNull;

private _currentBackPack = backpack _unit;

if (_currentBackPack != "") then {
    private _class = [_currentBackPack] call VFUNC(classVehicle);
    if !(isNil "_class") then {
        private _parents = [_class, true] call BIS_fnc_returnParents;
        if !(isNil "_parents") then {
            if (("StaticWeapon" in _parents) || {("Weapon_Bag_Base" in _parents)}) then {
                _unit setVariable [VQGVAR(usedStatic),_CurrentBackPack];
                _gunner = _unit;
            };
        };
    };
};

if (isNull _gunner) exitWith {};

private _currentPosition = position _unit;

private _distance = (random 1) + 2;
private _direction = random 360;
private _position = [(_currentPosition select 0) + (sin _direction) * _distance, (_currentPosition select 1) + (cos _direction) * _distance, (_currentPosition select 2)];

_unit doMove _position;

private _nearestEnemy = _unit findNearestEnemy _unit;
if (isNull _nearestEnemy) then {
  _nearestEnemy = _nearestEnemyInput;
};
if (isNull _nearestEnemy) exitWith {};

private _staticClassname = _unit getVariable VQGVAR(staticClassname);
private _weaponClassname = [_staticClassname,0,-9] call BIS_fnc_trimString;

_weaponClassname = if !(["mortar",_staticClassname] call BIS_fnc_inString) then { _weaponClassname + "_high_F" } else { _weaponClassname + "_F" };

_unit setVariable [VQGVAR(hasDeployed),true];
_unit setVariable [VQGVAR(hasStatic),false];

private _staticCreated = _weaponClassname createvehicle [0,0,0];
_staticCreated setPosATL (getPosATL _unit);
_unit setVariable [VQGVAR(staticWeapon),_staticCreated];

_unit assignAsGunner _staticCreated;
[_unit] orderGetIn true;
_unit moveInGunner _staticCreated;
removeBackpack _unit;

private _dirTo = (position _weapon) getDir (position _nearestEnemy);
_staticCreated setDir _dirTo;
(vehicle _unit) setDir _dirTo;

[_unit] spawn {
    params ["_unit"];

    sleep (180 + (random 180));
    if (!(alive _unit) || {_unit == (vehicle _unit)}) exitWith {};
    [_unit] call VFUNC(packStatic);
};
