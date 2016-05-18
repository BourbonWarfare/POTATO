#include "script_component.hpp"
TRACE_1("params",_this);

//Helps the AI recognize people firing from a better distance
_unit = (_this select 0) select 0;

if !(side _unit in VCOM_SideBasedMovement) exitWith {};

_bullet = (_this select 0) select 6;


_TimeShot = _unit getVariable "VCOM_FiredTimeHearing";

if ((diag_tickTime - _TimeShot) > 10) then
{
	_Array1 = _unit call VCOMAI_EnemyArray;

	{
		if ((_x distance _unit) < VCOM_HEARINGDISTANCE && !(_x getVariable "VCOMAI_ShotsFired")) then
		{
			_x setVariable ["VCOMAI_ShotsFired",true,true];
		};
	} foreach _Array1;

	_Unit setVariable ["VCOM_FiredTimeHearing",diag_tickTime,false];
};
