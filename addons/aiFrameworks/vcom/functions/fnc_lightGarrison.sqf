#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

private _unitGroup = (group _unit);
private _units = units _unitGroup;

private _building = nearestBuilding _nearestEnemy;
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
