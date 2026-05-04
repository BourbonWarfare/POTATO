#include "..\script_component.hpp"
#define VEHICLE_SPACING 25
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawn a number of squads in vehicles to move to a zone under attack.
* The squads are given some kind of vehicles and then waypointed along with
* vehicles. This function find positions for the vehicles, decides how many
* dismounts are in each vehicle and assigns each to a HC, run on client, called
* by the
*
* Arguments:
* _waypoints - Position to head to (ARRAY, default [0, 0, 0]).
* _vehicleArray - Number of units in reinforcing squads (SCALAR, default 5).
* _numberOfSquads - Number of squads to create (SCALAR, default 2).
* _vicType - Should the reinforcement vehicles be a BRM-1 (BOOL, default false).
*
* Return:
* The number of patroling units spawned
*
* Example:
* called by map function
*//***************************************************************************/
params [
    ["_waypoints", [], [[]]],
    ["_vehicleArray", [], [[]]],
    ["_maxDismountCount", 8, [8]],
    ["_findRoads", false, [false]],
    ["_finalWPType", CONVOY_WPTYPE_MOVE, [CONVOY_WPTYPE_MOVE]],
    ["_lambsDismounts", false, [false]],
    ["_side", east, [east]]
];

if (_waypoints isEqualTo [] ||
    _vehicleArray isEqualTo []) exitWith {
    ["No vehicles selected", player] call FUNC(sendCuratorHint);
};
// Apply vehicle crew counts
if (isNil QGVAR(vehicleInfoCache)) then {GVAR(vehicleInfoCache) = createHashMap};
private _sumUnits = 0;
{
    _x params ["_vicType", "_addDismounts"];
    private _vicInfo = GVAR(vehicleInfoCache) getOrDefaultCall [_vicType, {
        private _configRoot = configFile >> "CfgVehicles" >> _vicType;
        private _ffvCargoSeats = 0;
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
                } else {
                    if (_configRoot == _config &&
                        {"true" configClasses (_x >> "Turrets") isEqualTo []}) then {
                        _ffvCargoSeats = _ffvCargoSeats + 1;
                    };
                };
                if (isClass (_x >> "Turrets")) then {
                    [_x, _path + [_forEachIndex]] call _fnc_getCrewedTurrets
                };
            } forEach ("true" configClasses (_config >> "Turrets"));
        };

        _configRoot call _fnc_getCrewedTurrets;
        [_crew, count _crew, _ffvCargoSeats + getNumber (_configRoot >> "transportSoldier")]
    }, true];
    _sumUnits = _sumUnits + _vicInfo#1;
    if (_addDismounts) then {
        _x set [1, (_vicInfo#2) min _maxDismountCount];
        _sumUnits = _sumUnits + (_x#1);
    } else {
        _x set [1, 0];
    };
} forEach _vehicleArray;
if !([_side, _sumUnits] call FUNC(canCreateGroup)) exitWith {
    ["Cannot create more units at this time", player] call FUNC(sendCuratorHint);
};
// Find spawn positions
_waypoints params ["_posAGLSpawn", "_posAGLDismount"];
private _posArray = [];
if (_findRoads) then {
    private _vicCount = count _vehicleArray;
    private _roads = _posAGLSpawn nearRoads (15 * _vicCount);
    for "_i" from 1 to _vicCount do {
        if (_roads isEqualTo []) exitWith {};
        private _road = selectRandom _roads;
        _roads = _roads - [_road];
        private _roadPosATL = getPosATL _road;
        (getRoadInfo _road) params ["", "", "", "", "", "", "_begPos", "_endPos"];
        private _distances = [_begPos distance _posAGLDismount, _endPos distance _posAGLDismount];
        private _vicDir = if (_distances#0 < _distances#1) then {
            _endPos getDir _begPos
        } else {
            _begPos getDir _endPos
        };
        _posArray pushBack [_roadPosATL distance2D _posAGLDismount, _roadPosATL, _vicDir];
    };
    _posArray sort true;
    _posArray = _posArray apply {[_x#1, _x#2]};
    if (count _posArray < _vicCount) then {
        private _dir = _posAGLDismount getDir _posAGLSpawn;
        private _spawnPos = +_posAGLSpawn;
        private _offset = [VEHICLE_SPACING * sin _dir, VEHICLE_SPACING * cos _dir, 0];
        while {count _posArray < _vicCount} do {
            _posArray pushBack [+_spawnPos, 180 + _dir];
            _spawnPos = _spawnPos vectorAdd _offset;
        };
    };
} else {
    private _dir = _posAGLDismount getDir _posAGLSpawn;
    private _spawnPos = +_posAGLSpawn;
    private _offset = [VEHICLE_SPACING * sin _dir, VEHICLE_SPACING * cos _dir, 0];
    for "_i" from 1 to count _vehicleArray do {
        _posArray pushBack [_spawnPos, 180 + _dir];
        _spawnPos = _spawnPos vectorAdd _offset;
    };
};
// Pass it off to the HCs
{
    (_vehicleArray#_forEachIndex) params ["_vicType", "_dismountCount"];
    _x params ["_roadPosATL", "_vicDir"];
    private _wps = +_waypoints;
    (_wps#2) set [2, _forEachIndex];
    [{[_this, QFUNC(reinforceSpawnVehicle)] call FUNC(hcPassthrough);},
        [_wps, [_vicType, _roadPosATL, _vicDir], _dismountCount, _lambsDismounts, _side],
        _forEachIndex * 4] call CBA_fnc_waitAndExecute;
} forEach _posArray;
