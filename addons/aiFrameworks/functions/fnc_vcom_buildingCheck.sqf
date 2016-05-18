#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Enemy", "_Offset", "_ToWorld1", "_ToWorld2", "_PointHeight", "_PointHeightC", "_LookVar", "_dgn_returnvariable"];
if (_this getVariable "VCOM_MovedRecentlyCover" || {_this getVariable "VCOMAI_ActivelyClearing"} || {_this getVariable "VCOMAI_StartedInside"}) exitWith {};

_Enemy = _this call VCOMAI_ClosestEnemy;
if (isNil "_Enemy") exitWith {};

if ((typeName _Enemy) isEqualTo "ARRAY") exitWith {_dgn_returnvariable = false;_dgn_returnvariable};

_dgn_returnvariable = false;

_Position = getposASL _Enemy;
_Array = lineIntersectsObjs [_Position,[_Position select 0,_Position select 1,(_Position select 2) + 10], objnull, objnull, true, 4];
{
	if (_x isKindof "Building") exitWith {_dgn_returnvariable = true;};
} foreach _Array;

_Array = lineIntersectsObjs [_Position,[_Position select 0,_Position select 1,(_Position select 2) - 10], objnull, objnull, true, 4];
{
	if (_x isKindof "Building") exitWith {_dgn_returnvariable = true;};
} foreach _Array;

_dgn_returnvariable
