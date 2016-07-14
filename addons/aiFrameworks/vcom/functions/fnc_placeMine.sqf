#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

private _mineArray = _unit getVariable [VQGVAR(mineArray),[]];
private _selectedArray = (_mineArray select 0);
_selectedArray params ["_mineClassname","_mineMagazine"];
TRACE_1("selected munition",_selectedArray);

_unit setVariable [VQGVAR(mineArray),_mineArray - [_selectedArray]];

_unit removeMagazine _mineMagazine;
_unit setVariable [VQGVAR(plantedMineRecently),diag_tickTime];

[_unit,_nearestEnemy,_mineClassname] spawn {
    params ["_unit","_nearestEnemy","_mineClassname"];

    private _mine = objNull;


    private _nearRoads = _unit nearRoads 50;
    if (count _nearRoads > 0) then {
        private _closestRoad = [_nearRoads,_unit] call VFUNC(closestObject);
        _unit doMove (getpos _closestRoad);

        waitUntil {sleep 1; !(alive _unit) || _unit distance _closestRoad < 3};

        _mine = createMine [_mineClassname, getposATL _closestRoad, [], 3];
    } else {
        _mine = createMine [_mineClassname, getposATL _unit, [], 3];
    };

    TRACE_1("Mine planted",_mine);
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
