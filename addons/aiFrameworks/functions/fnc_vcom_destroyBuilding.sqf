#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _unitGroup = group _unit;
private _isLeader = (leader _unit) == _unit;

private _enemy = [_unit] call VFUNC(closestEnemy);

TRACE_4("",_unit,_unitGroup,_isLeader,[_enemy] call VFUNC(inBuilding));

if (isNull _enemy || {_enemy != (vehicle _enemy)}
        || {(_unit distance _enemy) > VGVAR(maxDistanceToBombBuilding)}
        || {!([_enemy] call VFUNC(inBuilding))}) exitWith {};

private _bombArray = _unit getVariable [VQGVAR(bombArray),[]];
if (count (_bombArray) < 1) exitWith {};

private _selectedArray = _bombArray select 0;
_selectedArray params ["_bombClassname","_bombMagazine"];

_unit setVariable [VQGVAR(bombArray),_bombArray - [_selectedArray]];

private _previousPosition = position _unit;
private _building = nearestBuilding _enemy;

[_unit] joinSilent (createGroup (side _unitGroup));
doStop _unit;
_unit doMove (position _building);

_unit setVariable [VQGVAR(flanking),diag_tickTime];
_unit setVariable [VQGVAR(plantedBombRecently),diag_tickTime];

[_unit,_building,_bombClassname,_bombMagazine,_previousPosition,_unitGroup,_isLeader] spawn {
    params ["_unit","_building","_bombClassname","_bombMagazine","_previousPosition","_unitGroup","_isLeader"];
    waitUntil { sleep 0.5; _unit distance _building <= 10 };

    _unit removeMagazine _bombMagazine;
    private _bomb = createMine [_bombClassname, getposATL _unit, [], 0];
    private _bombPos = (position _unit);

    doStop _unit;
    _unit doMove _previousPosition;

    private _friends = [_unit] call VFUNC(friendlyUnits);

    private _notSafe = true;
    while {_notSafe} do {
        private _closestFriendly = [_friends,_bombPos] call VFUNC(closestObject);
        if (isNull _closestFriendly || {_closestFriendly distance _bombPos > 20}) then {
            _notSafe = false;
        };

        sleep 1;
    };

    [_unit] joinSilent _unitGroup;
    if (_isLeader) then { _unitGroup selectLeader _unit; };

    _bomb setdamage 1;
    _unit setVariable [VQGVAR(flanking),0];
};
