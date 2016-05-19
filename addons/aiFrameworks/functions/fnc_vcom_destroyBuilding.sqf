#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _unitGroup = group _unit;
private _isLeader = (leader _unit) == _unit;

private _enemy = [_unit] call VFUNC(closestEnemy);
if (isNull _enemy || {_enemy != (vehicle _enemy)}
    || {(_unit distance _enemy) > VGVAR(maxDistanceToSatchel)}
    || {!([_enemy] call VFUNC(inBuilding))}) exitWith {};

private _satchelCount = _unit getVariable [VQGVAR(satchelCount),0];
private _satchel = _unit getVariable [VQGVAR(satchelObject),""];
private _satchelMagazine = _unit getVariable [VQGVAR(satchelObjectMagazine),""];
if (_satchelCount < 1 || {_satchel == ""} || {_satchelMagazine == ""}) exitWith {};

_unit setVariable [VQGVAR(satchelCount),_satchelCount - 1];
private _previousPosition = (position _unit);

private _building = nearestBuilding _enemy;

[_unit] joinSilent (createGroup (side _unit));
doStop _unit;
_unit doMove (position _building);

waitUntil { sleep 0.5; _unit distance _building) <= 10 };

_unit removeMagazine _satchelMagazine;
private _bomb = createMine [_satchel, getposATL _unit, [], 0];
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
