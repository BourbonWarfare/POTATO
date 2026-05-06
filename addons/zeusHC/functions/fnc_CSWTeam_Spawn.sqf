#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 *
 *
 * Arguments:
 * 0: An array of poses (AGL) for spawn, move, and aim points
 * 1: The side units should be on
 * 2: The type of weapons team
 * 3: The number of rounds the static weapon should have
 *
 * TODO:
 * Implement custom, non LAMBS CSW setup so we can modify ammo and not have it
 * pop in so fast (maybe switch to ACE CSW)
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
TRACE_1("CSW Team Spawn",_this);
params [
    ["_waypoints", [], [[]]],
    "_side",
    "_type",
    "_ammo"
];

if (_waypoints isEqualTo []) exitWith {};
private _group = createGroup [_side, true];
private _sideString = switch (_side) do {
    case east: {"noLambs_e"};
    case resistance: {"noLambs_i"};
    default {"noLambs_w"};
};
private _teamComp = [
    ["potato_%1_hmgl","potato_%1_hmgg"],
    ["potato_%1_hatl","potato_%1_hatg"],
    ["potato_%1_mmgl","potato_%1_mmgg"],
    ["potato_%1_matl","potato_%1_matg"]
] select _type;

{
    [{
        params ["_posAGL", "_group", "_type"];
        private _unit = _group createUnit [_type, _posAGL, [], 0, "NONE"];
        _unit setVariable ["lambs_eventhandlers_explosionReactionTime", time + 7200];
    },
    [_waypoints#0, _group, format [_x, _sideString]],
    potato_zeusHC_delayBetweenUnitCreation * _forEachIndex] call CBA_fnc_waitAndExecute;
} forEach _teamComp;

[{
    params ["_group", "_waypoints"];
    private _wp = _group addWaypoint [_waypoints#1, 0];
    _wp setWaypointSpeed "FULL";
    _wp setWaypointBehaviour "CARELESS";
    _wp setWaypointCombatMode "BLUE";
    _wp setWaypointCompletionRadius 5;
    _wp = _group addWaypoint [_waypoints#1, 0];
    _wp setWaypointCompletionRadius 5;
    _wp setWaypointTimeout [10,10,10];
    _wp setWaypointStatements ["true", format ["[group this, %1, %2] call lambs_main_fnc_dogroupstaticdeploy", _waypoints#2, _waypoints#1]];
    _wp = _group addWaypoint [_waypoints#1, 0];
    _wp setWaypointCompletionRadius 25;
    _wp setWaypointTimeout [5,5,5];
    _wp setWaypointBehaviour "AWARE";
    _wp setWaypointCombatMode "RED";
}, [_group, _waypoints]] call CBA_fnc_execNextFrame;
