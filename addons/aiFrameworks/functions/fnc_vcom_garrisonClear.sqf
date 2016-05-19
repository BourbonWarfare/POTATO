#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (_unit getVariable [VQGVAR(startedInside),false]
    || {_unit getVariable [VQGVAR(garrisoned),false]}
    || {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}
    || {[_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)}) exitWith {};

//Find the closest enemy (This should be the one that is in a building
private _enemy = _unit call VFUNC(closestEnemy);
if (isNull _enemy) exitWith {};

//Find nearest building to the enemy
private _building = nearestBuilding _enemy;

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
