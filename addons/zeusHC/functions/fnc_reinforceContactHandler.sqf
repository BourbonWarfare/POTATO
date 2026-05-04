#include "..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This function handles vehicle contact
*
* Arguments:
*  BIS CombatModeChanged group EH params
*
* Return:
* none
*
* Example:
* (BIS CombatModeChanged + [false]) call potato_zeusHC_fnc_initializeVehicle;
******************************************************************************/
params [
    ["_group", grpNull, [grpNull]],
    ["_removeEH", false, [false]]
];
if (isNull _group) exitWith {};
if (_removeEH) then {
    _group removeEventHandler ["CombatModeChanged", _thisEventHandler];
};

private _leader = leader _group;
private _vic = vehicle _leader;
if (_vic == _leader) exitWith {};
private _nearestEnemy = _leader findNearestEnemy _leader;
private _contactDistance = _leader distance _nearestEnemy;
if (_contactDistance > 300 && alive _leader &&
    {side _nearestEnemy != side _leader && _side in [east, west, resistance]}) exitWith {
    [{call FUNC(convoyContactHandler)},
    [_group, false],
    5] call CBA_fnc_waitAndExecute;
};

private _hasTurret = allTurrets [_vic, false] isNotEqualTo [];
private _crew = fullCrew _vic;
private _groups = _crew apply {group (_x#0)};
if (_hasTurret) then {
    [_vic, units _group] call FUNC(unloadCargo);
} else {
    [_vic, [objNull]] call FUNC(unloadCargo);
};

_groups = _groups arrayIntersect _groups;
{
    private _wp = _x addWaypoint [_nearestEnemy, 0];
    _wp setWaypointCompletionRadius 250;
    _wp setWaypointType "SAD";
    _x setCurrentWaypoint _wp;
} forEach _groups;
