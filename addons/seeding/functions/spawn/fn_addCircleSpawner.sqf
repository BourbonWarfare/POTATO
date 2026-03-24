#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Add an arc spawner to the spawner handler and initialize the handler if
* needed.
*
* Arguments:
* _endPosATL - End position to aim for (Array, default [0, 0, 0]).
* _startPosATL - Starting position of the group (Array, default [0, 0, 0]).
* _squadSize - Number of units in reinforcing squads (SCALAR, default 10).
* _side - The side of the attacking forces (SIDE, default LMD_ENMY_SIDE).
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* None
*
* Example:
* [getPosATL player, [2,1,0], 4, resistance] call lmd_fnc_addCircleSpawner;
*//***************************************************************************/
params [
    ["_areaParams", [], [[]]],
    ["_minUnits", 40, [0, {}]],
    ["_goalUnits", 60, [0, {}]],
    ["_forceDistribute",  true, [true]],
    ["_endTime", CBA_missionTime + 1800, [0]],
    ["_attackerSide", resistance, [resistance]],
    ["_defenderSide", west, [west]],
    ["_artilleryArray", [], [[]]]
];

if (_areaParams isEqualTo []) exitWith {};
_areaParams params [
    ["_centerPosATL", [0, 0, 0], [[]]],
    ["_minRad", 300, [0]],
    ["_maxRad", 800, [0]],
    ["_minAngle", 0, [0]],
    ["_maxAngle", 360, [0]],
    ["_angleStep", 20, [20]]
];

if (_minAngle > _maxAngle) then {
    private _temp = _minAngle;
    _minAngle = _maxAngle;
    _maxAngle = _temp;
};
while {_maxAngle - _minAngle > 360} do {
    _minAngle = _minAngle + 360;
};
_minRad = _minRad min 400;
deleteMarker QGVAR(circleSpawn);
private _mk = createMarkerLocal [QGVAR(circleSpawn), _centerPosATL];
_mk setMarkerSizeLocal [_minRad, _minRad];
_mk setMarkerColorLocal "ColorBlue";
_mk setMarkerBrushLocal "Border";
_mk setMarkerShape "Ellipse";

private _zoneArray = [_centerPosATL, _maxRad, _maxRad];
/// Check if handler is running and initialize if needed
if (isNil QGVAR(circleSpawners)) then {
    GVAR(circleSpawners) = [];
};
if (GVAR(circleSpawners) isEqualTo []) then {
    [{call FUNC(circleSpawnHandle)}, 0, 15] call CBA_fnc_waitAndExecute;
};

if (_artilleryArray isNotEqualTo []) then {
    _artilleryArray params ["_artyType", "", "_artyCount"];
    //// Create vehicles
    // Find Zone
    private _validZones = [];
    for "_i" from 0 to BW_ZONE_MAX_CHECK do {
        private _zone = BW_ZONE_BASE_STRING + str _i;
        private _reinforceZonePos = getMarkerPos _zone;
        if (_reinforceZonePos isEqualTo [0, 0, 0]) then {continue};
        private _mainDistance = _reinforceZonePos distance2D _centerPosATL;
        if (_mainDistance < 3600 &&
            _mainDistance > 2000) then {
            _validZones pushBack _reinforceZonePos;
        };
    };
    if (_validZones isEqualTo []) exitWith {};
    _validZones = selectRandom _validZones;
    // Find gun location
    private _gunPos = [_validZones, 0, 150, 7.5, 0, 1, 0] call BIS_fnc_findSafePos;
    // Create guns
    for "_i" from 1 to _artyCount do {
        [[_validZones, _artyType, _attackerSide], QFUNC(createArtyGun)] call PFUNC(zeusHC,hcPassthrough);
    };
};

/// Whether positions are supposed to be evenly distributed
if (_forceDistribute) then {
    GVAR(circleSpawners) pushBack [
        _endTime,
        [_centerPosATL, _maxRad, _maxRad],
        _attackerSide,
        _defenderSide,
        _minUnits,
        _goalUnits,
        _minRad,
        [_minAngle, _maxAngle, _angleStep],
        CIRCLESPAWN_VIC_STARTING,
        [CBA_missionTime + 120, _artilleryArray#1] ,
        []
    ];
} else {
    GVAR(circleSpawners) pushBack [
        _endTime,
        [_centerPosATL, _maxRad, _maxRad],
        _attackerSide,
        _defenderSide,
        _minUnits,
        _goalUnits,
        _minRad,
        [_minAngle, _maxAngle, _angleStep],
        CIRCLESPAWN_VIC_STARTING,
        +(_artilleryArray#1)
    ];
};

/// Spawn 1/3-1/2 of the units immediately
private _unitCount = count ((units _attackerSide) inAreaArray _zoneArray);
if (_goalUnits isEqualType {}) then {
    _goalUnits = round call _goalUnits;
};
private _unitsToAdd = round (_goalUnits/2);
while {_unitsToAdd > 0} do {
    private _groupSize = floor random [4, 5, 9];
    private _spawnPos = [_centerPosATL, _defenderSide, _maxRad, [], _minRad, [_minAngle, _maxAngle, _angleStep]] call FUNC(findArcSpawnPos);
    if (_spawnPos isNotEqualTo [0, 0, 0]) then {
        _unitsToAdd = _unitsToAdd - _groupSize;
        [
            {_this call FUNC(spawnUnitsWP)},
            [_centerPosATL, _spawnPos, _groupSize, _attackerSide],
            random 8
        ] call CBA_fnc_waitAndExecute;
    };
};
