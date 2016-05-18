#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_RandomChance", "_myNearestEnemy", "_CheckIfThrow", "_CheckDistance", "_DirectionSet", "_Directionset"];

_Unit = _this;

_RandomChance = (round (random 100));

if (_RandomChance < VCOM_GRENADECHANCE) then
{

if (isNil "_Unit" || {isNull _Unit}) exitWith {};


_myNearestEnemy = _Unit call VCOMAI_ClosestEnemy;
if (isNil "_myNearestEnemy") exitWith {};
if (typeName _myNearestEnemy isEqualTo "ARRAY") exitWith {};

_CheckIfThrow = _Unit getVariable "VCOM_GRENADETHROWN";


if !(_CheckIfThrow) then
{

_Unit setVariable ["VCOM_GRENADETHROWN",true,false];

_Unit spawn {sleep 10;_this setVariable ["VCOM_GRENADETHROWN",false,false];};

_CheckDistance = (_Unit distance _myNearestEnemy);

if (!(lineintersects [eyepos _Unit,eyepos _myNearestEnemy,_Unit,_myNearestEnemy])) then
{



	if (_CheckDistance < 60 && {_CheckDistance > 6}) then
	{

		_DirectionSet = [_Unit,_myNearestEnemy] call BIS_fnc_dirTo;
		_Unit setDir _Directionset;

		_Unit forceWeaponFire ["HandGrenadeMuzzle","HandGrenadeMuzzle"];
		_Unit forceWeaponFire ["MiniGrenadeMuzzle","MiniGrenadeMuzzle"];

	};
};


if (_CheckDistance < 5000) then
{
		if (VCOM_USESMOKE) then
		{


			_DirectionSet = [_Unit, _myNearestEnemy] call BIS_fnc_dirTo;

			_Unit setDir _Directionset;

			_Unit forceWeaponFire ["SmokeShellMuzzle","SmokeShellMuzzle"];
		};

};

};

};
