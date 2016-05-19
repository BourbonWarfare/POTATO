#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_enemy"];

private _support = [];
{
	if (isNull _x) then {
        VGVAR(ArtilleryArray) = VGVAR(ArtilleryArray) - [_x];
    } else {
        if (side _unit == side _x) then {
            _support pushBackUnique (vehicle _x);
        };
    };

    nil
} count VGVAR(ArtilleryArray);
if ((count _support) <= 0) exitWith {};

private _returnedSupport = [_support, (vehicle _unit)] call VFUNC(closestObject);
if (isNull _returnedSupport) exitWith {};
if !(_returnedSupport getVariable [VQGVAR(isArtillery),false]) exitWith {};

private _artilleryUnits = [];
{
    _artilleryUnits pushBackUnique (vehicle _x);
    nil
} count (units (group _returnedSupport));

private _ammoArray = getArtilleryAmmo _artilleryUnits;
if (count _ammoArray < 1) exitWith {};
_randomAmmo = selectRandom _ammoArray;

private _enemyPos  = getPos _enemy;

if !(_enemyPos inRangeOfArtillery [_artilleryUnits,_randomAmmo]) exitWith {};

{
    _x doArtilleryFire [_enemyPos, _randomAmmo, 1 + floor(random 3)];
    nil
} count _artilleryUnits;
