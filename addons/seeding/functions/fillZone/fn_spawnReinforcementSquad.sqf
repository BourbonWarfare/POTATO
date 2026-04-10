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
* ["zone_0", 3, 10, east] call bw_fnc_spawnReinforcementSquad;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_squadSize", 10, [10]],
    ["_vic", objNull, [objNull, []]],
    ["_side", east, [east]],
    ["_armedVehicles", false, [false]],
    ["_group", grpNull, [grpNull]]
];

if (_marker == "" ||
    getMarkerPos _marker isEqualTo [0, 0, 0] ||
    _squadSize <= 0) exitWith {};
if (_vic isEqualType []) exitWith {
    _vic params ["_vehicleType", "_posATL", "_vicDir"];
    _vic = createVehicle [_vehicleType, _posATL, [], 0, "NONE"];
    _vic setPosATL _posATL;
    _vic setDir _vicDir;
    [{call FUNC(spawnReinforcementSquad)},
        [_marker, _squadSize, _vic, _side, _armedVehicles],
        PGVAR(zeusHC,delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
};
if (isNull _vic) exitWith {
    diag_log text "[SEED][REINFORCE SQUAD] Vehicle not created.";
};
if (isNull _group) exitWith {
    private _hasTurret = allTurrets [_vic, false] isNotEqualTo [];

    if (_hasTurret) then {
        _group = createGroup [_side, true];
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
                private _unit = _group createUnit [format ["potato_nolambs_%1_vicc", _sideType], BW_UNIT_SPAWN_POS, [], 0, "NONE"];

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
            }, [_group, _vic, _x, _side], PGVAR(zeusHC,delayBetweenUnitCreation) * (0.5 + _forEachIndex)] call CBA_fnc_waitAndExecute;
        } forEach _crew;
        _group setVariable ["lambs_danger_disableGroupAI", true];
    };
    _group = createGroup [_side, true];
    [{call FUNC(spawnReinforcementSquad)}, [_marker, _squadSize, _vic, _side, _armedVehicles, _group], [0, 5] select _hasTurret] call CBA_fnc_waitAndExecute;
};
if !(local _group) exitWith {
    [_this] remoteExecCall [QFUNC(spawnReinforcementSquad), _group];
};
// Choose the unit type
private _type = switch (_squadSize mod 6) do {
    case 0: {selectRandom ["_ftl", "_ftl", "_sl"]};
    case 2: {selectRandom ["_rifleman", "_rifleman", "_lat"]};
    case 3: {selectRandom ["_ar", "_ar", "_ar",  "_ar", "_mmgg"]};
    case 4: {selectRandom ["_sm", "_rifleman_02"]};
    default {selectRandom ["_rifleman", "_rifleman_03", "_rifleman_04"]};
};
private _sideType = switch (_side) do {
    case east: {"e"};
    case west: {"w"};
    case resistance: {"i"};
    default {"e"};
};
private _unit = _group createUnit ["potato_nolambs_" + _sideType + _type, BW_UNIT_SPAWN_POS, [], 0, "NONE"];

_squadSize = _squadSize - 1;
if (_squadSize == 0) then {
    _group selectLeader _unit;
    if (isNull driver _vic) then {
        _unit moveInDriver _vic;
        _vic setEffectiveCommander _unit;
    } else {
        _unit moveInCargo _vic;
    };
} else {
    _unit moveInCargo _vic;
};

if (_squadSize > 0) then { // recurse
    [{_this call FUNC(spawnReinforcementSquad)},
        [_marker, _squadSize, _vic, _side, _armedVehicles, _group],
        PGVAR(zeusHC,delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
} else { // it's waypoint time
    private _movePos = getPosATL _vic;
    private _markerPos = getMarkerPos _marker;
    // End of mission - move to players
    if (GVAR(endOfMission)) then {
        _markerPos = [] call FUNC(findPlayerCentroid);
    };
    private _wpRadius = (random 20) + vectorMagnitude getMarkerSize _marker;
    _vic setUnloadInCombat [false, false];
    _group setVariable ["lambs_danger_disableGroupAI", true];
    [{
        params ["_vic", "_lastPos", "_group", "_goalPos"];
        if (isNull objectParent leader _group &&
            _goalPos distance leader _group > 1500) exitWith {
            {deleteVehicle _x} forEach units _group;
            deleteVehicle _vic;
        };
        if (_vic distance2D _lastPos < 50) exitWith {
            {deleteVehicle _x} forEach units _group;
            deleteVehicleCrew _vic;
            deleteVehicle _vic;
        };
        _vic setDamage 0;
    }, [_vic, _movePos, _group, _markerPos], 120] call CBA_fnc_waitAndExecute;
    [{
        params ["_vic", "_endPosATL", "_group", "_wpRadius"];
        _vic setEffectiveCommander driver _vic;
        private _groupDriver = group driver _vic;
        private _wp = _groupDriver addWaypoint [getPosATL _vic, 10];
        _wp setWaypointCompletionRadius 20;
        _wp setWaypointBehaviour "SAFE";
        _wp = _groupDriver addWaypoint [_endPosATL, 0];
        _wp setWaypointBehaviour "AWARE";
        if (_groupDriver == _group) then {
            _wp setWaypointType "GETOUT";
            _wp setWaypointStatements ["true",
                QUOTE(if (local _this) then {[ARR_2(vehicle _this,[objNull])] call FUNC(unloadCargo)};)
            ];
        } else {
            _wp setWaypointType "TR UNLOAD";
            _wp setWaypointStatements ["true",
                QUOTE(if (local _this) then {[vehicle _this] call FUNC(unloadCargo)};)
            ];
            _wp setWaypointCompletionRadius (1 + random 0.2) * _wpRadius;
            _wp = _groupDriver addWaypoint [_endPosATL, 150];
            _wp setWaypointType "SAD";
            _wp setWaypointBehaviour "AWARE";
            _wp setWaypointSpeed "LIMITED";
        };
        _wp setWaypointCompletionRadius (1 + random 0.2) * _wpRadius;
        _wp = _group addWaypoint [_endPosATL, 150];
        _wp setWaypointCompletionRadius 200;
        _wp setWaypointBehaviour "AWARE";
        _vic setUnloadInCombat [false, false];
        _vic setVelocityModelSpace [0, 5, 0];
    }, [_vic, _markerPos, _group, _wpRadius], 1] call CBA_fnc_waitAndExecute;
};
