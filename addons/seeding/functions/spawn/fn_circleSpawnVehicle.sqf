#include "..\..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* Spawn a number of squads to QRF a zone under attack. The squads are
* given some kind of vehicles, either a truck or UAZ, from nearby spawn
* locations
*
* Arguments:
* _posGoalASL - Position to head to (ARRAY, default [0, 0, 0]).
* _vehicleType - Type of vehicle to make (STRING, default "").
* _side - The side of the crew spawned (SIDE, default east)
*
* Return:
* None
*
* Example:
* [] call bw_fnc_circleSpawnVehicle;
******************************************************************************/
params [
    ["_posGoalASL", [0, 0, 0], [[]]],
    ["_vehicleType", "", [""]],
    ["_side", east, [east]],
    ["_firstAngle", 0, [0]],
    ["_secondAngle", 360, [360]]
];

if (_posGoalASL isEqualTo [0, 0, 0] ||
    _vehicleType == "") exitWith {};
private _posGoalATL = ASLToATL _posGoalASL;

([ASLToATL _posGoalASL, west, 2500, [_firstAngle, _secondAngle]] call FUNC(findArcSpawnPosVehicle)) params ["_roadPosATL", "_road"];
if (_roadPosATL isEqualTo [0, 0, 0]) exitWith {
    diag_log formatText ["[BW][SEED]][VICSPAWN] Could not find any suitable reinforcement zone or vehicle (%2) near %1", _posGoalATL, str _vehicleType];
};
private _vic = createVehicle [_vehicleType, _roadPosATL, [], 0, "NONE"];
(getRoadInfo _road) params ["", "", "", "", "", "", "_begPos", "_endPos"];
private _distances = [_begPos distance _posGoalATL, _endPos distance _posGoalATL];
if (_distances#0 < _distances#1) then {
    _vic setDir (_endPos getDir _begPos);
} else {
    _vic setDir  (_begPos getDir _endPos);
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
        private _sideStr = switch (_side) do {
            case east: {"potato_nolambs_e"};
            case resistance: {"potato_nolambs_i"};
            case west: {"potato_nolambs_w"};
            default {"potato_nolambs_e"};
        };
        private _unitType = if ("bmp" in toLowerANSI typeOf _vic || "t72" in toLowerANSI typeOf _vic) then {
           _sideStr + "_vicc"
        } else {
            _sideStr + "_rifleman"
        };
        private _unit = _group createUnit [_unitType, BW_UNIT_SPAWN_POS, [], 0, "NONE"];


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
    }, [_group, _vic, _x, _side], PGVAR(zeusHC,delayBetweenUnitCreation) * _forEachIndex] call CBA_fnc_waitAndExecute;
} forEach _crew;
_group setVariable ["lambs_danger_disableGroupAI", true];

[{
    params ["_vic", "_group", "_posGoalATL"];
    private _movePos = getPosATL _vic;
    private _wp = _group addWaypoint [_posGoalATL, 10];
    _wp setWaypointCompletionRadius 300;
    _wp = _group addWaypoint [_posGoalATL, 10];
    _wp setWaypointType "SAD";
    _wp setWaypointCompletionRadius 100;
    _vic setConvoySeparation 50;
    _group setSpeedMode "FULL";
    _vic setVelocityModelSpace [0, 5, 0];
}, [_vic, _group, _posGoalATL], PGVAR(zeusHC,delayBetweenUnitCreation) * count _crew] call CBA_fnc_waitAndExecute;
