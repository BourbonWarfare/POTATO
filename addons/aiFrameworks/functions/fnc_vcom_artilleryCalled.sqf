#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_enemy"];

private _support = [];
{
	if (isNull _x) then {
        VGVAR(ArtilleryArray) = VGVAR(ArtilleryArray) - [_x];
    } else {
        if (side _unit == side _x && {!((vehicle _x) in _support)}) then {
            _support pushBack (vehicle _x);
        };
    };

    nil
} count VGVAR(ArtilleryArray);
if ((count _support) <= 0) exitWith {};

_artilleryUnits = [];



private _returnedSupport = [_support, (vehicle _Unit)] call VFUNC(closestObject);
if (isNil "_ReturnedSupport") exitWith {};

if !(_returnedSupport getVariable [VQGVAR(isArtillery),false]) exitWith {};

_ArtilleryGroup = group _ReturnedSupport;

_ArtilleryGroupUnits = units _ArtilleryGroup;

{
	_ArtilleryUnits = _ArtilleryUnits + [(vehicle _x)];
} foreach _ArtilleryGroupUnits;

_AmmoArray = getArtilleryAmmo _ArtilleryUnits;
//player sidechat format ["ARTY _AmmoArray: %1",_AmmoArray];
if (isNil "_AmmoArray") exitWith {};

_RandomAmmoArray = _AmmoArray call BIS_fnc_selectRandom;
if (isNil "_RandomAmmoArray") exitWith {};
//player sidechat format ["ARTY _RandomAmmoArray: %1",_RandomAmmoArray];
_ContinueFiring = (getPos _Enemy) inRangeOfArtillery [_ArtilleryUnits,_RandomAmmoArray];
if !(_ContinueFiring) exitWith {};
//Hint format ["_ArtilleryUnits : %1",_ArtilleryUnits];
{
	_x doArtilleryFire [(getPos _Enemy),_RandomAmmoArray,(floor(random 4))];
	//_x commandArtilleryFire [(getPos _Enemy),_RandomAmmoArray,(floor(random 4))];

} foreach _ArtilleryUnits;
