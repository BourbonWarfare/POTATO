#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawn a number of squads to reinforce a zone under attack. The squads are
* given some kind of vehicles, either armed or unarmed, from the
*
* Arguments:
* _marker - Zone to reinforce (STRING, default "").
* _squadSize - Number of units in reinforcing squads (SCALAR, default 10).
* _numberOfSquads - Number of squads to create (SCALAR, default 2).
* _sideReinforcement - Side reinforcements are spawned on (SIDE, default east).
* _armedVehicles - Should the reinforcement vehicles be armed (BOOL, false).
*
* Return:
* The number of patroling units spawned
*
* Example:
* ["zone_0", 10, 2, east, false] call bw_fnc_spawnReinforcemetns;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_squadSize", 10, [10]],
    ["_numberOfSquads", 2, [2]],
    ["_sideReinforcement", east, [east]],
    ["_armedVehicles", false, [false]]
];

if (_marker == "" ||
    getMarkerPos _marker isEqualTo [0, 0, 0] ||
    _squadSize <= 0 ||
    _numberOfSquads <= 0) exitWith {
    diag_log formatText ["[SEED][REINFORCE] Bad sector called: %1", [_marker, getMarkerPos _marker, _squadSize, _numberOfSquads]];
};

// Find a list of zones that are close but not too close to anthing important
private _nearZones = [];
private _zonePos = getMarkerPos _marker;
// End of mission
if (GVAR(endOfMission)) then {
    _zonePos = [] call FUNC(findPlayerCentroid);
};
private _allPlayers = [] call CBA_fnc_players;
for "_i" from 0 to BW_ZONE_MAX_CHECK do {
    private _zone = BW_ZONE_BASE_STRING + str _i;
    private _reinforceZonePos = getMarkerPos _zone;
    if (_reinforceZonePos isEqualTo [0, 0, 0]) then {continue};
    private _distance = _allPlayers apply {_x distance2D _reinforceZonePos};
    private _mainDistance = _reinforceZonePos distance2D _zonePos;
    if (_mainDistance < 3000 &&
        _mainDistance > 1000 &&
        selectMin _distance > 1250) then {
        _nearZones pushBack _zone;
    };
};

private _sideConfig = switch (_sideReinforcement) do {
    case east: {"potato_e"};
    case west: {"potato_w"};
    case resistance: {"potato_i"};
    case civilian: {"CIV_F"};
    default {"potato_e"};
};
private _path = if (_armedVehicles) then {
    missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "reinforcementArmed";
} else {
    missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "reinforcementTruck";
};
private _vehicleInfo = if (isArray _path) then {
    getArray _path;
} else {
    private _vic = getText _path;
    [_vic, getNumber (configFile >> "CfgVehicles" >> _vic >> "transportSoldier")]
};
_vehicleInfo params ["_vehicleType", ["_squadSizeMax", 10]];
if (_nearZones isEqualTo [] || _vehicleType == "") exitWith {
    diag_log formatText ["[SEED][REINFORCE] Could not find any suitable reinforcement zone or vehicle (%2) near %1", _marker, str _vehicleType];
};
private _reinforcementZone = selectRandom _nearZones;

private _roadSeachRad = 100;
private _roads = (getMarkerPos _reinforcementZone) nearRoads _roadSeachRad;
_roads = _roads select {_x inArea _reinforcementZone};
while {count _roads < _numberOfSquads && _roadSeachRad < 1000} do {
    _roads = (getMarkerPos _reinforcementZone) nearRoads _roadSeachRad;
    _roads = _roads select {_x inArea _reinforcementZone};
    _roadSeachRad = _roadSeachRad + 100;
};

if (count _roads < _numberOfSquads) exitWith {
    diag_log formatText ["[SEED][REINFORCE] Could not find any suitable reinforcement spawn positions at %1 ", _marker];
};
if (random 1 < 0.4) then {
    private _pos = getMarkerPos _reinforcementZone;
    private _aircraftType =  getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >>"heliVehiclePool");
    if (_aircraftType isEqualTo []) exitWith {};
    _pos set [2, 100];
    [[getMarkerPos _marker, selectRandom _aircraftType, _pos, _sideReinforcement, true], QFUNC(spawnAircraft)] call PFUNC(zeusHC,hcPassthrough);
};

for "_i" from 1 to _numberOfSquads do {
    if (_roads isEqualTo []) exitWith {};
    private _road = selectRandom _roads;
    _roads = _roads - [_road];
    private _roadPosATL = getPosATL _road;
    (getRoadInfo _road) params ["", "", "", "", "", "", "_begPos", "_endPos"];
    private _distances = [_begPos distance _zonePos, _endPos distance _zonePos];
    private _vicDir = if (_distances#0 < _distances#1) then {
        _endPos getDir _begPos
    } else {
        _begPos getDir _endPos
    };
    [{[_this, QFUNC(spawnReinforcementSquad)] call PFUNC(zeusHC,hcPassthrough);},
        [_marker, _squadSize min _squadSizeMax, [_vehicleType, _roadPosATL, _vicDir], _sideReinforcement, _armedVehicles],
        (_i - 1) * 4] call CBA_fnc_waitAndExecute;
};
