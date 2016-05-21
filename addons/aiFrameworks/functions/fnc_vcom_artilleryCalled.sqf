#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _groupSide = (side (group _unit));

private _support = [];
{
    if (_groupSide == side _x) then {
        {
            if (alive _x && {_x getVariable [VQGVAR(isArtillery),false]}) then {
                _support pushBackUnique (vehicle _x);
            };
            nil
        } count units _x;
    };

    nil
} count allGroups;

TRACE_1("",_support);

if ((count _support) <= 0) exitWith {};

private _returnedSupport = [_support, _unit] call VFUNC(closestObject);
TRACE_1("",_returnedSupport);
if (isNull _returnedSupport) exitWith {};

private _artilleryUnits = [];
{
    _artilleryUnits pushBackUnique (vehicle _x);
    nil
} count (units (group _returnedSupport));

TRACE_1("",_artilleryUnits);

private _ammoArray = getArtilleryAmmo _artilleryUnits;
TRACE_1("",_ammoArray);

if (count _ammoArray < 1) exitWith {};
_randomAmmo = selectRandom _ammoArray;

TRACE_1("",_randomAmmo);

private _enemyPos  = getPos ([_unit] call VFUNC(closestEnemy));

if !(_enemyPos inRangeOfArtillery [_artilleryUnits,_randomAmmo]) exitWith {};

_unit setVariable [VQGVAR(calledArtillery),diag_tickTime];

{
    _x doArtilleryFire [_enemyPos, _randomAmmo, 1 + floor(random 3)];
    nil
} count _artilleryUnits;
