#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_MovePosition", "_NearestEnemy", "_TypeListFinal", "_TypeList", "_Type", "_type", "_BoundingArray", "_p1", "_p2", "_maxWidth", "_maxLength", "_maxHeight", "_ClosestCover", "_GuessLocation", "_coverObjectspos","_WeakListFinal"];

_Unit = _this select 0;
_MovePosition = _this select 1;

if (_Unit getVariable "VCOM_MovedRecentlyCover" || {_Unit getVariable "VCOMAI_ActivelyClearing"} || {_Unit getVariable "VCOMAI_StartedInside"} || {_Unit getVariable "VCOM_GARRISONED"}) exitWith {};
_Unit setVariable ["VCOM_MovedRecentlyCover",true,false];

_Unit spawn
{
	sleep 10;
	_this setVariable ["VCOM_MovedRecentlyCover",false,false];
};



_NearestEnemy = _Unit call VCOMAI_ClosestEnemy;
if (isNil "_NearestEnemy" || {_NearestEnemy isEqualTo [0,0,0]}) exitWith {};








_WeakListFinal = [];
_ClosestCover = [];
_TypeListFinal = [];
_TypeList = nearestObjects [_MovePosition, [], 50];
{
	_Type = typeOf _x;
	if !(_type in ["#crater","#crateronvehicle","#soundonvehicle","#particlesource","#lightpoint","#slop","#mark","HoneyBee","Mosquito","HouseFly","FxWindPollen1","ButterFly_random","Snake_random_F","Rabbit_F","FxWindGrass2","FxWindLeaf1","FxWindGrass1","FxWindLeaf3","FxWindLeaf2"]) then
	{
		if (!(_x isKindOf "Man") && {!(_x isKindOf "Bird")} && {!(_x isKindOf "BulletCore")} && {!(_x isKindOf "Grenade")} && {!(_x isKindOf "WeaponHolder")}) then
		{
			_BoundingArray = boundingBoxReal _x;
			_p1 = _BoundingArray select 0;
			_p2 = _BoundingArray select 1;
			_maxWidth = abs ((_p2 select 0) - (_p1 select 0));
			_maxLength = abs ((_p2 select 1) - (_p1 select 1));
			_maxHeight = abs ((_p2 select 2) - (_p1 select 2));
			if (_maxWidth > 2 && _maxLength > 2 && _maxHeight > 2) then
			{
				if (_type isEqualTo "") then
				{
					_WeakListFinal pushback _x
				}
				else
				{
					_TypeListFinal pushback _x;
				};
			};
		};
	};
} foreach _TypeList;


if (_TypeListFinal isEqualTo [] && _WeakListFinal isEqualTo []) exitWith {};
//_ClosestCover = [_TypeListFinal,_this] call VCOMAI_ClosestObject;
if !(_TypeListFinal isEqualTo []) then {_ClosestCover = _TypeListFinal call BIS_fnc_selectRandom;} else {_ClosestCover = _WeakListFinal call BIS_fnc_selectRandom;};


if (isNil "_ClosestCover") exitWith {};

_GuessLocation = [];
if (_NearestEnemy isEqualTo [0,0,0]) then {_GuessLocation = getpos _Unit} else {_GuessLocation = getpos _NearestEnemy;};

_coverObjectspos = [_GuessLocation, (_ClosestCover distance _NearestEnemy) + 2, ([_GuessLocation, _ClosestCover] call BIS_fnc_dirTo)] call BIS_fnc_relPos;
_coverObjectspos
