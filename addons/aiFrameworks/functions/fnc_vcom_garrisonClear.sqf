#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Enemy", "_nBuilding", "_Locations"];

//Function to send AI to clear buildings
if (_this getVariable "VCOM_MovedRecentlyCover" || {_this getVariable "VCOMAI_ActivelyClearing"} || {_this getVariable "VCOMAI_StartedInside"} || {_this getVariable "VCOM_GARRISONED"}) exitWith {};

//Find the closest enemy (This should be the one that is in a building
_Enemy = _this call VCOMAI_ClosestEnemy;
if (isNil "_Enemy" || {(typeName _Enemy) isEqualTo "ARRAY"}) exitWith {};


//Find nearest building to the enemy
_nBuilding = nearestBuilding _Enemy;

//Find the locations of the buildings
_Locations = [_nBuilding] call BIS_fnc_buildingPositions;

//Stop the AI - and then tell them to move to the house
{
	//Set variable to true to prevent AI clearing buildings to often
	_x setVariable ["VCOMAI_ActivelyClearing",true,false];
	//Spawn cool-down
	_x spawn {sleep 30;_this setVariable ["VCOMAI_ActivelyClearing",false,false];};
	_x spawn VCOMAI_StanceModifier;
	[_Locations,_x] spawn VCOMAI_GarrisonClearPatrol;
} foreach units (group _this);
