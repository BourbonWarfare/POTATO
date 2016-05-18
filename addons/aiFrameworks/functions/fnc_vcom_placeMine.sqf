#include "script_component.hpp"
TRACE_1("params",_this);

_Unit = _this;

if (VCOM_MineLayChance < (random 100)) exitWith {};

_Unit setVariable ["VCOM_HasMine",false,false];
_Unit setVariable ["VCOM_SATCHELRECENTLY",false,false];

_MineType = _Unit getVariable "Vcom_MineObject";
_MagazineName = _Unit getVariable "Vcom_MineObjectMagazine";
_Unit removeMagazine _MagazineName;
_Unit setVariable ["Vcom_MineObject",[],false];
_Unit setVariable ["Vcom_MineObjectMagazine",[],false];
_Unit setVariable ["VCOM_PlantedMineRecently",true,false];
_Unit spawn {sleep (30 + (random 120));_this setVariable ["VCOM_PlantedMineRecently",false,false];};

if (_MineType isEqualTo []) exitWith {};

_NearestEnemy = _Unit call VCOMAI_ClosestEnemy;
if (_NearestEnemy isEqualTo [] || {isNil "_NearestEnemy"}) exitWith {};

_mine = [];

if (_NearestEnemy distance _Unit < 200) then
{
	_mine = createMine [_MineType,getposATL _Unit, [], 3];
}
else
{
	_NearRoads = _Unit nearRoads 50;
	if (count _NearRoads > 0) then
	{
		_ClosestRoad = [_NearRoads,_Unit] call VCOMAI_ClosestObject;
		_Unit doMove (getpos _ClosestRoad);
		waitUntil {!(alive _Unit) || _Unit distance _ClosestRoad < 3};
		_mine = createMine [_MineType,getposATL _ClosestRoad, [], 3];
	}
	else
	{
		_mine = createMine [_MineType,getposATL _Unit, [], 3];
	};
};

_UnitSide = (side _Unit);


if (_mine isEqualTo []) exitWith {};

[_mine,_UnitSide] spawn
{
	_Mine = _this select 0;
	_UnitSide = _this select 1;
	_NotSafe = true;

	while {alive _mine && _NotSafe} do
	{
		_Array1 = [];
		{
			if !((side _x) isEqualTo _UnitSide) then {_Array1 pushback _x;};
		} foreach allUnits;

		_ClosestEnemy = [_Array1,_Mine] call VCOMAI_ClosestObject;
		if (_ClosestEnemy distance _Mine < 2.5) then {_NotSafe = false;};
		sleep 0.2;
	};
	_Mine setdamage 1;
};

/*
_mine = createMine ["SatchelCharge_F",position player, [], 0];
_mine setdamage 1;

_mine = createMine ["Democharge_F",position player, [], 0];
_mine setdamage 1;
