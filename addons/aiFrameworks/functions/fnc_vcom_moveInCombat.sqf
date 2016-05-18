#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_index", "_wPos", "_NearestEnemy", "_unit","_GuessLocation"];

_Unit = _this;

if (_Unit getVariable "VCOM_MovedRecentlyCover" || {_Unit getVariable ["VCOM_VisuallyCanSee",false]} || {_Unit getVariable "VCOMAI_ActivelyClearing"} || {_Unit getVariable "VCOMAI_StartedInside"} || {_Unit getVariable "VCOM_GARRISONED"} || {_Unit getVariable ["VCOM_MovedRecently",false]}) exitWith {};

_Unit setVariable ["VCOM_MovedRecently",true,false];
_Unit spawn
{
	sleep 30;
	_this setVariable ["VCOM_MovedRecently",false,false];
};

//_myNearestEnemy = _Unit findNearestEnemy _Unit;
//if (isNull _myNearestEnemy) exitWith {};

_Squadlead = leader _this;

if (_Squadlead distance _this > 150) then
{
	_this doFollow (leader _this);
}
else
{
	_Group = (group _this);
	//Pull the waypoint information
	_index = currentWaypoint _Group;
	_WPPosition = getWPPos [_Group,_index];

	if !(_WPPosition isEqualTo [0,0,0]) then
	{
		if (_this isEqualTo (leader _this)) then
		{
			_GroupDudes = units (group _this);

			{
				[_x,_WPPosition] spawn
				{
					sleep (random 10);
					_Unit = _this select 0;
					_Pos = _this select 1;

					_MoveToPos = [_Unit,_Pos] call VCOMAI_FragmentMove;
					if !((vehicle _Unit) isEqualTo _Unit) exitWith
					{
						_Unit forceSpeed -1;
						_Unit doMove _Pos;
					};

					_CoverPos = [_Unit,_MoveToPos] call VCOMAI_FindCoverPos;
					if !(isNil "_CoverPos") then
					{

						/*
						_arrow = "Sign_Sphere200cm_F" createVehicle [0,0,0];
						_arrow setpos _CoverPos;

						_arrow spawn
						{
							sleep 30;
							deletevehicle _this;
						};
						*/

						_WaitTime = diag_ticktime + 15;
						_Unit setVariable ["VCOM_InCover",false,false];
						While {alive _Unit && diag_ticktime < _WaitTime && (_Unit distance _CoverPos) > 2} do
						{

							//if !(_x getVariable "VCOM_VisuallyCanSee") then
							//	{
									_Unit forceSpeed -1;
									_Unit domove _CoverPos;
									//systemchat format ["MOVING: %1",_x];
							//	};
							sleep 1.5;
						};
						//systemchat format ["MADE IT: %1",_x];
						_Unit forcespeed 0;
						_Unit setVariable ["VCOM_InCover",true,false];
					}
					else
					{
						_Unit doMove _MoveToPos;
					};
				};
			} foreach _GroupDudes;
		};

		//_Unit setVariable ["VCOM_InCover",true,false];
	};





};
