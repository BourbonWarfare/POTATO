#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _groupSide = (side (group _unit));

private _support = [];
{
    if (_groupSide == side _x) then {
        {
            if (alive _x && {_unit getVariable [VQGVAR(isArtillery),false]}) then {
                _support pushBackUnique (vehicle _x);
            };
            nil
        } count units _x;
    };

    nil
} count allGroups;

if ((count _support) <= 0) exitWith {};

private _returnedSupport = [_support, _unit] call VFUNC(closestObject);
if (isNull _returnedSupport) exitWith {};

private _artilleryUnits = [];
{
    _artilleryUnits pushBackUnique (vehicle _x);
    nil
} count (units (group _returnedSupport));

private _ammoArray = getArtilleryAmmo _artilleryUnits;
if (count _ammoArray < 1) exitWith {};
_randomAmmo = selectRandom _ammoArray;

private _enemyPos  = getPos ([_unit] call VFUNC(closestEnemy));

if !(_enemyPos inRangeOfArtillery [_artilleryUnits,_randomAmmo]) exitWith {};

_unit setVariable [VQGVAR(calledArtillery),diag_tickTime];

{
    _x doArtilleryFire [_enemyPos, _randomAmmo, 1 + floor(random 3)];
    nil
} count _artilleryUnits;
