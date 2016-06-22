#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy","_group","_isLeader"];

private _bombArray = _unit getVariable [VQGVAR(bombArray),[]];
private _selectedArray = _bombArray select 0;
_selectedArray params ["_bombClassname","_bombMagazine"];

_unit setVariable [VQGVAR(bombArray),_bombArray - [_selectedArray]];

private _previousPosition = position _unit;

private _plantRange = 10;
private _plantObject = if (_nearestEnemy == vehicle _nearestEnemy) then {
    _plantRange = 5;
    vehicle _nearestEnemy
} else {
    nearestBuilding _nearestEnemy
};

[_unit] joinSilent (createGroup (side _group));
doStop _unit;

_unit setVariable [VQGVAR(flanking),diag_tickTime];
_unit setVariable [VQGVAR(plantedBombRecently),diag_tickTime];

private _oldUnitPosition = position _unit;
private _oldPlantPos = position _plantObject;
private _moveAlongTimer = diag_tickTime;
_unit doMove _oldPlantPos;

while {_unit distance _oldPlantPos > _plantRange && {!(isNil "_unit") && !(isNull _unit) && alive _unit}} do {
    TRACE_2("In loop",_unit distance _oldUnitPosition,_oldUnitPosition distance _unit);
    if ((_oldPlantPos distance _plantObject) > _plantRange) then {
        _oldPlantPos = position _plantObject;
        _unit doMove _oldPlantPos;
    };

    if (_moveAlongTimer + 5 < diag_tickTime) then {
        if (_oldUnitPosition distance _unit < 5) then {
            _unit doMove _oldPlantPos;
        };
        _oldUnitPosition = position _unit;
        _moveAlongTimer = diag_tickTime;
    };

    sleep 1;
};

_unit removeMagazine _bombMagazine;
private _bomb = createMine [_bombClassname, getposATL _unit, [], 0];
private _bombPos = (position _unit);

doStop _unit;
_unit doMove _previousPosition;

[_unit] joinSilent _group;
if (_isLeader) then { _group selectLeader _unit; };

private _friends = [_unit] call VFUNC(friendlyUnits);

private _notSafe = true;
while {_notSafe} do {
    private _closestFriendly = [_friends,_bombPos] call VFUNC(closestObject);
    if (isNull _closestFriendly || {!(alive _closestFriendly)} || {_closestFriendly distance _bombPos > 25}) then {
        _notSafe = false;
    };

    sleep 1;
};

_bomb setdamage 1;
_unit setVariable [VQGVAR(flanking),0];
