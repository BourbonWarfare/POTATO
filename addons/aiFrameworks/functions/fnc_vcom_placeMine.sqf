#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (VGVAR(chanceToUseMine) <= random 100) exitWith {};

private _nearestEnemy = [_unit] call VFUNC(closestEnemy);
if (isNull _nearestEnemy) exitWith {};

private _mineArray = _unit getVariable [VQGVAR(mineArray),[]];
if (count (_mineArray) < 1) exitWith {};

private _selectedArray = (_mineArray select 0);
_selectedArray params ["_mineClassname","_mineMagazine"];

_unit setVariable [VQGVAR(mineArray),_mineArray - [_selectedArray]];

_unit removeMagazine _mineMagazine;
_unit setVariable [VQGVAR(plantedMineRecently),diag_tickTime];

private _mine = objNull;

[_unit,_nearestEnemy,_mineClassname] spawn {
    params ["_unit","_nearestEnemy","_mineClassname"];

    if (_nearestEnemy distance _unit < 200) then {
        _mine = createMine [_mineClassname, getposATL _unit, [], 3];
    } else {
        private _nearRoads = _unit nearRoads 50;
        if (count _nearRoads > 0) then {
            private _closestRoad = [_nearRoads,_unit] call VFUNC(closestObject);
            _unit doMove (getpos _closestRoad);

            waitUntil {sleep 1; !(alive _unit) || _unit distance _closestRoad < 3};

            _mine = createMine [_mineClassname, getposATL _closestRoad, [], 3];
        } else {
            _mine = createMine [_mineClassname, getposATL _unit, [], 3];
        };
    };

    if (isNull _mine) exitWith {};

    private _notSafe = true;
    private _unitSide = (side (group _unit));

    while {alive _mine && _notSafe} do {
        private _units = [];
        {
            if ((alive _x) && {side _x != _unitSide}) then { _units pushback _x; };
            nil
        } count allUnits;

        private _closestEnemy = [_units,_mine] call VFUNC(closestObject);
        if (_closestEnemy distance _mine < 2.5) then { _notSafe = false; };
        sleep 0.5;
    };
    _mine setdamage 1;
};
