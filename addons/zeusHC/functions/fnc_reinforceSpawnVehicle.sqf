#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawns a vehicle to follow a set of waypoints. Called recursively, waypoints'
* added on final iteration.
*
* Arguments:
* _waypoints - Set of (Array, default []).
* _vic - Either a vehicle object, or the first pass, an array to initialize
*        the vehicle (default, objNull)
* _dismountCount - Number of units in squad (SCALAR, default 8).
* _lambsDismounts - whether the dismounts should use LAMBS AI (BOOL, default false)
* _side - Sie of the units (SIDE, default east)
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* The number of patroling units spawned
*
* Example:
* ["zone_0", 3, 10, east] call potato_zeusHC_fnc_spawnReinforementSquad;
*//***************************************************************************/
params [
    ["_waypoints", [], [[]]],
    ["_vic", objNull, [objNull, []]],
    ["_dismountCount", 8, [8]],
    ["_lambsDismounts", false, [false]],
    ["_side", east, [east]],
    ["_group", grpNull, [grpNull]]
];

if (_vic isEqualType objNull && {isNull _vic}) exitWith {};
if (_vic isEqualType []) exitWith {
    _vic params ["_vehicleType", "_posATL", "_vicDir"];
    _vic = createVehicle [_vehicleType, _posATL, [], 0, "NONE"];
    _vic setPosATL _posATL;
    _vic setDir _vicDir;
    [{_this call FUNC(reinforceSpawnVehicle)},
        [_waypoints, _vic, _dismountCount, _lambsDismounts, _side, _group],
        GVAR(delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
};
private _sideStr = switch (_side) do {
    case east: {["noLambs_e", "e"] select _lambsDismounts};
    case resistance: {["noLambs_i", "i"] select _lambsDismounts};
    default {["noLambs_w", "w"] select _lambsDismounts};
};
if (isNull _group) exitWith {
    _sideStr = switch (_side) do {
        case east: {"noLambs_e"};
        case resistance: {"noLambs_i"};
        default {"noLambs_w"};
    };
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
            params ["_group", "_vic", "_sideStr", "_turret"];
            private _unit = _group createUnit [format ["potato_%1_vicc", _sideStr], getPosATL _vic, [], 0, "NONE"];

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
        }, [_group, _vic, _sideStr, _x], GVAR(delayBetweenUnitCreation) * (0.5 + _forEachIndex)] call CBA_fnc_waitAndExecute;
    } forEach _crew;
    _group setVariable ["lambs_danger_disableGroupAI", true];
    if (_dismountCount > 0) then {
        _group = createGroup [_side, true];
    };
    [{_this call FUNC(reinforceSpawnVehicle)},
        [_waypoints, _vic, _dismountCount, _lambsDismounts, _side, _group],
        5] call CBA_fnc_waitAndExecute;
};
if !(isNull leader _group || {local leader _group}) exitWith {
    [_this] remoteExecCall [QFUNC(reinforceSpawnVehicle), leader _group];
};
// Skip for just vic spawning
if (_dismountCount > 0) then {
    // Choose the unit type
    private _type = switch (_dismountCount mod 4) do {
        case 3: {"ftl"};
        case 2: {"ar"};
        case 1: {selectRandom ["lat", "rifleman"]};
        default {selectRandom ["rifleman", "rifleman_02", "rifleman_03", "rifleman_04", "sm"]};
    };
    if (units _group isEqualTo []) then {_type = "sl"};

    private _unit = _group createUnit ["potato_" + _sideStr + "_" + _type, _waypoints#0, [], 0, "CAN_COLLIDE"];

    _dismountCount = _dismountCount - 1;
    if (_type == "sl") then {
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
};
if (_dismountCount > 0) then { // recurse
    [{call FUNC(reinforceSpawnVehicle)},
        [_waypoints, _vic, _dismountCount, _lambsDismounts, _side, _group],
        GVAR(delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
} else { // it's waypoint time
    _waypoints params ["_posAGLSpawn", "_posAGLDismount", "_endWaypoint"];
    _endWaypoint params ["_posAGLEnd", "_wpType", "_index"];
    private _delay = 1;
    if (group driver _vic != _group) then {
        private _wp = _group addWaypoint [_posAGLDismount, 0];
        _wp setWaypointCompletionRadius 20;
        _wp = _group addWaypoint [_posAGLDismount, 0];
        _wp setWaypointType "GETOUT";
        _wp setWaypointCompletionRadius 20;
        _wp = _group addWaypoint [_posAGLEnd, 50];
        _wp setWaypointCompletionRadius 100;
        switch (_wpType) do {
            case CONVOY_WPTYPE_SAD: {
                _wp setWaypointType "SAD";
            };
            case CONVOY_WPTYPE_GARRISON: {
                _wp = _group addWaypoint [_posAGLEnd, 50];
                _wp setWaypointCompletionRadius 100;
                _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf []";
                _wp setWaypointType "SCRIPTED";
            };
            case CONVOY_WPTYPE_LAMBSQCB: {
                _wp setWaypointScript "\z\lambs\addons\wp\scripts\fnc_wpCQB.sqf";
                _wp setWaypointType "SCRIPTED";
            };
            default {_wp setWaypointCompletionRadius 20;}
        };
    } else {
        _delay = 8;
    };
    if (_index > 0) then {
        _delay = _delay + 1;
    };
    _group setVariable ["lambs_danger_disableGroupAI", !_lambsDismounts];
    [{
        params ["_vic",  "_dsmntPosAGL", "_endPosAGL", "_index"];
        //_vic limitSpeed 70;
        _vic setEffectiveCommander driver _vic;
        private _group = group driver _vic;
        private _wp = _group addWaypoint [getPosATL _vic, 0];
        _wp setWaypointCompletionRadius 20;
        _wp = _group addWaypoint [_dsmntPosAGL, 0];
        _wp setWaypointType "TR UNLOAD";
        _wp setWaypointBehaviour "COMBAT";
        _wp setWaypointSpeed "FULL";
        _wp setWaypointStatements ["true",
            QUOTE(if (local this) then {[vehicle this] call FUNC(reinforceUnloadCargo)};)
        ];
        _wp setWaypointCompletionRadius (1 + _index) * 20;
        _group addEventHandler ["CombatModeChanged", {
            [_this#0, true] call FUNC(reinforceContactHandler);
        }];
        if (count units _group > 1) then {
            _wp = _group addWaypoint [_dsmntPosAGL, 100];
            _wp setWaypointTimeout [30, 35, 50];
            _wp setWaypointCompletionRadius 100;
            _wp setWaypointStatements ["true", "if (local this) then {vehicle this limitSpeed 10;};"];
            _wp = _group addWaypoint [_endPosAGL, 50];
            _wp setWaypointBehaviour "COMBAT";
            _wp setWaypointSpeed "LIMITED";
        } else {
            // Let infantry clear the vehicles
            _wp = _group addWaypoint [_dsmntPosAGL, 0];
            _wp setWaypointCompletionRadius 100;
            _wp setWaypointTimeout [15, 15, 15];
            _wp setWaypointBehaviour "CARELESS";
            _wp setWaypointSpeed "FULL";
            _wp setWaypointCombatMode "BLUE";
            // drive back to spawn to be deleted
            _wp = _group addWaypoint [getPosATL _vic, 0];
            _wp setWaypointStatements ["true", "if (local this) then {private _vic = vehicle this; deleteVehicleCrew _vic; deleteVehicle _vic;};"];
            _wp setWaypointCompletionRadius 20;
        };
        _vic setUnloadInCombat [false, false];
        // give the vehicle a kickstart
        _vic setVelocityModelSpace [0, 5, 0];
    }, [_vic, _posAGLDismount, _posAGLEnd, _index], _delay] call CBA_fnc_waitAndExecute;
    _vic setConvoySeparation 50;
    _group setSpeedMode "FULL";
};
