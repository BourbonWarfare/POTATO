#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (_unit getVariable [VQGVAR(startedInside),false]
        || {_unit getVariable [VQGVAR(garrisoned),false]}
        || {!([_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold))}
        || {!([_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold))}) exitWith {};

private _unitGroup = (group _unit);
private _units = units _unitGroup;

private _closestEnemy = [_unit] call VFUNC(closestEnemy);
if (isNull _closestEnemy) exitWith {};

private _building = nearestBuilding _closestEnemy;
private _isEnterable = [_building] call BIS_fnc_isBuildingEnterable;
if ((_unit distance _building) > 200 || {!([_building] call BIS_fnc_isBuildingEnterable)}) exitWith {};

private _positions = _building buildingPos -1;
if (count _positions < (count _units)) exitWith {};

{
    private _position = selectRandom _positions;
    _positions = _positions - [_position];
    _x moveTo _position;
    nil
} count _units;
