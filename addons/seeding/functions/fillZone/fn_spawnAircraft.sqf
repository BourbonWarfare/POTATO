#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawn a reinforcement squad, and put them in a given vehicle.
*
* Arguments:
* _marker - Zone to reinforce (STRING, default "").
* _squadSize - Number of units in reinforcing squads (SCALAR, default 10).
* _vic -  (SCALAR, default 2).
* _side - Side reinforcements are spawned on (SIDE, default east).
* _armedVehicles - Should the reinforcement vehicles be armed (BOOL, false).
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* The number of patroling units spawned
*
* Example:
* [ASLtoAGL getPosASL player, "helicopter", getPosATL spawnPos0, east] call bw_fnc_spawnAircraft;
*//***************************************************************************/
params [
    ["_targetPosAGL", [0,0,0], [[]]],
    ["_aircraftType", "", [""]],
    ["_spawnPos", [0,0,0], [[]]],
    ["_side", east, [east]],
    ["_responding", false, [false]]
];

if (_targetPosAGL isEqualTo [0, 0, 0] ||
    _spawnPos isEqualTo [0, 0, 0] ||
    _aircraftType == "") exitWith {};

private _vic = createVehicle [_aircraftType, _spawnPos, [], 0, "FLY"];
_vic setPosATL _spawnPos;
_vic setDir (_spawnPos getDir _targetPosAGL);

if (isNull _vic) exitWith {
    diag_log text "[SEED][SPAWN AIRCRAFT] Vehicle not created.";
};

private _group = createGroup [_side, true];
private _configRoot = configOf _vic;
private _crew = if (getNumber (_configRoot >> "hasDriver") == 1) then {
    [[-1]]
} else {
    []
};
private _fnc_getCrewedTurrets = { // based on part of BIS_fnc_getTurrets by Karel Moricky & Killzone_Kid
    params ["_config", ["_path", []]];
    {
        if (1 > getNumber (_x >> "dontCreateAI")) then {
            _crew pushBack (_path + [_forEachIndex]);
        };
        if (isClass (_x >> "Turrets")) then {
            [_x, _path + [_forEachIndex]] call _fnc_getCrewedTurrets
        };
    } forEach ("true" configClasses (_config >> "Turrets"));
};
_configRoot call _fnc_getCrewedTurrets;

{
    [{
        params ["_group", "_vic", "_turret", "_side"];
        private _sideType = switch (_side) do {
            case east: {"e"};
            case west: {"w"};
            case resistance: {"i"};
            default {"e"};
        };
        private _unit = _group createUnit [format ["potato_nolambs_%1_pilot", _sideType], BW_UNIT_SPAWN_POS, [], 0, "NONE"];
        if (_turret isEqualTo [-1]) then {
            _unit assignAsDriver _vic;
            _unit moveInDriver _vic;
            [{(_this#0) setSkill ["general", 1];}, [_unit], 2] call CBA_fnc_waitAndExecute;
        } else {
            _unit assignAsTurret [_vic, _turret];
            _unit moveInTurret [_vic, _turret];
        };
        _group addVehicle _vic;
        _group selectLeader (effectiveCommander _vic);
        _vic flyInHeight 150;
    }, [_group, _vic, _x, _side], PGVAR(zeusHC,delayBetweenUnitCreation) * _forEachIndex] call CBA_fnc_waitAndExecute;
} forEach _crew;
_group setVariable ["lambs_danger_disableGroupAI", true];
_vic flyInHeight 150;
_vic setVelocityModelSpace [0, 100, 0];

private _movePos = getPosATL _vic;
// End of mission - move to players
if (GVAR(endOfMission)) then {
    _targetPosAGL = [] call FUNC(findPlayerCentroid);
};
[{
    params ["_vic", "_endPosATL"];
    _vic setEffectiveCommander driver _vic;
    private _group = group driver _vic;
    private _wp = _group addWaypoint [getPosATL _vic, 10];
    _wp setWaypointCompletionRadius 20;
    _wp setWaypointBehaviour "SAFE";
    _wp = _group addWaypoint [_endPosATL, 0];
    _wp setWaypointCompletionRadius (1 + random 0.5) * 500;
    _wp = _group addWaypoint [_endPosATL, 500];
    _wp setWaypointType "SAD";
    _wp setWaypointBehaviour "AWARE";
}, [_vic, _targetPosAGL], 1] call CBA_fnc_waitAndExecute;
