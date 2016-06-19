#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

//Find nearest building to the enemy
private _building = nearestBuilding _nearestEnemy;

//Find the locations of the buildings
private _locations = _building buildingPos -1;
if (count _locations < 1) exitWith {};

//Stop the AI - and then tell them to move to the house
{
    //Set variable to true to prevent AI clearing buildings to often
    _x setVariable [VQGVAR(activelyClearing),diag_tickTIme];
    [_x] spawn VFUNC(stanceModifier);
    [_x,_locations] spawn VFUNC(garrisonClearPatrol);
    nil
} count units (group _unit);
