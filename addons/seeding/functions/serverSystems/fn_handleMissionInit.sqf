#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This takes a menuOptions hashmap from a player and initializes all a mission
* based on the settings
*
* Arguments:
* _marker - The marker zone (STRING).
* _settingHash - The menu options hashmap from the client (HASHMAP, default empty).
*
* Return:
* none
*
* Example:
* ["zone_14", GVAR(menuOptions)] spawn bw_fnc_handleMissionInit;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_settingHash", GVAR(menuOptions)]
];

if !(isServer) exitWith {
    [_this] remoteExecCall [QFUNC(handleMissionInit), 2];
};

// make sure we have a valid zone and it's not in use
if (_marker == "" || GVAR(missionActiveZones) getOrDefault [_marker, false]) exitWith {
    diag_log formatText ["[SEED][Mission Event] Invalid or used zone (%1)", _marker];
};
GVAR(missionActiveZones) set [_marker, true];

// Choosing enemy faction, maybe make it select from multiple factions per side in the future
private _enemySide = switch (_settingHash getOrDefault ["enemyType", BW_TRAINING_ENEMY_OPFOR]) do {
    case BW_TRAINING_ENEMY_OPFOR: {east};
    case BW_TRAINING_ENEMY_INDY: {resistance};
    default {east};
};
private _minAISkill = _settingHash getOrDefault ["AIskillMin", 0.2];
private _maxAISkill = _settingHash getOrDefault ["AIskillMax", 0.8];
[_minAISkill, _maxAISkill] call FUNC(updateAISkill);

private _minBuildingGarrison = _settingHash getOrDefault ["option0", 0.33];
private _maxBuildingGarrison = _settingHash getOrDefault ["option1", 0.75];
private _chanceMove = _settingHash getOrDefault ["option2", 0.5];
private _initArray = [0, 0];
private _markerPos = getMarkerPos _marker;
private _operationType = _settingHash getOrDefault ["operationType", BW_TRAINING_OPERATION_MOUT];
private _zoneDims = markerSize _marker;
switch (_operationType) do {
    case BW_TRAINING_OPERATION_MOUT: {
        _marker setMarkerColorLocal "ColorBlue";
        _marker setMarkerAlphaLocal 1;
        _marker setMarkerBrush "Border";
        _minBuildingGarrison = round (_minBuildingGarrison * 8);
        _maxBuildingGarrison = round (_maxBuildingGarrison * BW_AI_MAX_SPAWN);
        _chanceMove = linearConversion [0, 1, _chanceMove, 0, 0.25];
        _initArray = [
            getMarkerPos _marker,
            vectorMagnitude _zoneDims,
            _marker,
            2,
            [_minBuildingGarrison, _maxBuildingGarrison],
            _chanceMove,
            false,
            _enemySide,
            true
        ] call FUNC(garrisonBuildings);
    };
    case BW_TRAINING_OPERATION_ZONE_DRAW;
    case BW_TRAINING_OPERATION_ZONE: {
        _marker setMarkerColorLocal "ColorBlue";
        _marker setMarkerAlphaLocal 1;
        _marker setMarkerBrush "Border";
        _minBuildingGarrison = _minBuildingGarrison * 10;
        _maxBuildingGarrison = _maxBuildingGarrison * 7;
        _chanceMove = linearConversion [0, 1, _chanceMove, 0, 0.6];
        private _markerSize = vectorMagnitude _zoneDims;
        private _densityMode = _settingHash getOrDefault ["density", BW_TRAINING_DENSITY_UNIFORM];
        if (_densityMode == BW_TRAINING_DENSITY_RANDOM) then {
            _densityMode = selectRandom [BW_TRAINING_DENSITY_UNIFORM, BW_TRAINING_DENSITY_SINGLE, BW_TRAINING_DENSITY_MULTI];
        };
        switch (_densityMode) do {
            case BW_TRAINING_DENSITY_SINGLEMARKED;
            case BW_TRAINING_DENSITY_SINGLE: {
                private _tempPos = [_marker] call FUNC(posInMarker);
                _initArray = [
                    _tempPos,
                    0.6 * _markerSize,
                    _marker,
                    7,
                    [_minBuildingGarrison, _maxBuildingGarrison],
                    _chanceMove,
                    true,
                    _enemySide
                ] call FUNC(garrisonBuildingsCentered);
                while {_initArray#1 < 5} do {
                    _tempPos = [_marker] call FUNC(posInMarker);
                    private _params = [
                        [_marker] call FUNC(posInMarker),
                        0.6 * _markerSize,
                        _marker,
                        7,
                        [_minBuildingGarrison, _maxBuildingGarrison],
                        _chanceMove,
                        true,
                        _enemySide
                    ] call FUNC(garrisonBuildingsCentered);
                    _initArray = [_params#0 max _initArray#0, _params#1 + _initArray#1];
                };
                if (_densityMode == BW_TRAINING_DENSITY_SINGLEMARKED && _initArray#1 > 0) then {
                    private _termRadius = 0.233511 * _markerSize; // calculating when the radius exponential will be 1
                    private _mk = createMarker [format ["%1Helper_%2", _marker, _tempPos#0], _tempPos];
                    _mk setMarkerShapeLocal "ELLIPSE";
                    _mk setMarkerBrushLocal "Border";
                    _mk setMarkerColorLocal "ColorBlue";
                    _mk setMarkerSize [_termRadius, _termRadius];
                };
            };
            case BW_TRAINING_DENSITY_MULTIMARKED;
            case BW_TRAINING_DENSITY_MULTI: {
                private _radius = 0.6 * _markerSize;
                private _pastCenters = [];
                for "_i" from 0 to 2 do {
                    private _tempPos = [_marker] call FUNC(posInMarker);
                    private _distances = _pastCenters apply {_tempPos distance2D _x};
                    private _maxCount = 10;
                    while {_maxCount = _maxCount - 1; selectMin _distances < _radius*3/5 && _maxCount > 0} do {
                        _tempPos = [_marker] call FUNC(posInMarker);
                        _distances = _pastCenters apply {_tempPos distance2D _x};
                    };
                    _pastCenters pushBack _tempPos;
                    private _params = [
                        _tempPos,
                        _radius,
                        _marker,
                        [_minBuildingGarrison, _maxBuildingGarrison],
                        _chanceMove,
                        true,
                        _enemySide,
                        true
                    ] call FUNC(garrisonBuildingsCentered);
                    _initArray = [_params#0 max _initArray#0, _params#1 + _initArray#1];
                    if (_densityMode == BW_TRAINING_DENSITY_MULTIMARKED && _params#1 != 0) then {
                        private _termRadius = 0.389185 * _radius; // calculating when the radius exponential will be 1
                        private _mk = createMarker [format ["%1Helper_%2%3", _marker, _i, _tempPos#0], _tempPos];
                        _mk setMarkerShapeLocal "ELLIPSE";
                        _mk setMarkerBrushLocal "Border";
                        _mk setMarkerColorLocal "ColorBlue";
                        _mk setMarkerSize [_termRadius, _termRadius];
                    };
                };
            };
            default { // uniform is default
                _minBuildingGarrison = round (_minBuildingGarrison * 0.6);
                _maxBuildingGarrison = round (_maxBuildingGarrison * BW_AI_MAX_SPAWN / 7);

                _initArray = [
                    _markerPos,
                    _markerSize,
                    _marker,
                    _minBuildingGarrison,
                    [_minBuildingGarrison, _maxBuildingGarrison],
                    _chanceMove,
                    true,
                    _enemySide
                ] call FUNC(garrisonBuildings);
            };
        };
        private _zoneArea = 4 * (_zoneDims#0) * (_zoneDims#1);
        private _zonePerimeter = 4 * _zoneDims#0 + 4 * _zoneDims#1;
        private _patrolCount = _settingHash getOrDefault ["option3", 0];
        if (_patrolCount > 0) then {
            private _patrolSize = _settingHash getOrDefault ["option4", 1];
            private _unitSum = [
                _marker,
                round (2 * _patrolCount),
                round linearConversion [0, 1, _patrolSize, 2, 10, true],
                _enemySide,
                false
            ] call FUNC(spawnPatrols);
            private _perimiterPatrolCount = if (_zonePerimeter > 2800) then {
                round (_zonePerimeter / 800)
            } else {
                2 + round (1 * _patrolCount)
            };
            _unitSum = _unitSum + ([
                _marker,
                _perimiterPatrolCount,
                round linearConversion [0.5, 1, _patrolSize, 2, 4, true],
                _enemySide,
                true
            ] call FUNC(spawnPatrols));
            _initArray set [1, _unitSum + _initArray#1];
        };
        private _vehicleIntensity = _settingHash getOrDefault ["option5", 0];
        if (_vehicleIntensity > 0) then {
            private _zoneSize = round (_zoneArea / 60000);
            if (_zoneSize > 4) then {
                _zoneSize = linearConversion [5, 20, _zoneSize, 5, 7];
            };
            [
                _markerPos,
                _markerSize,
                _marker,
                _zoneSize,
                _vehicleIntensity,
                _enemySide
            ] call FUNC(spawnZoneVehicles);
        };
        private _reinforcementSize = _settingHash getOrDefault ["option6", 0];
        if (_reinforcementSize > 0) then {
            [_marker, 1 + round (3 * _reinforcementSize), _vehicleIntensity > 0.6, _enemySide, _initArray#1, _initArray#0] call FUNC(addSectorReinforce);
        };
    };
    case BW_TRAINING_OPERATION_DEFEND: {
        deleteMarker _marker;
        [
            [_markerPos, 300 min (0.35 * _minBuildingGarrison), _minBuildingGarrison, _settingHash getOrDefault ["option3", -180], _settingHash getOrDefault ["option4", 180]],
            {_this*0.75},
            compile format ["16+%1*(count (allPlayers select {alive _x && side _x == west}))*(0.5+0.5*sin(360*CBA_missionTime/450))", _maxBuildingGarrison],
            true,
            CBA_missionTime + (_settingHash getOrDefault ["option2", 900]),
            _enemySide,
            west,
            selectRandom (getArray (missionConfigFile >> "CfgLoadouts" >> (["potato_i", "potato_e"] select (_enemySide == east)) >> "artilleryArray"))
        ] call FUNC(addCircleSpawner);
    };
};

_initArray params ["_timeToWait", "_unitsSpawned"];
diag_log formatText ["[SEED][Mission Event] Spawning %1 units on side %2 over the next %3 seconds.", _unitsSpawned, _enemySide, _timeToWait];
private _seconds = floor (_timeToWait mod 60);
if (_seconds < 10) then {
    _seconds = "0" + str _seconds;
};

private _zoneName = switch (_operationType) do {
    case BW_TRAINING_OPERATION_MOUT: {"MOUT"};
    case BW_TRAINING_OPERATION_ZONE: {text nearestLocation [_markerPos, ["NameCity","NameCityCapital","NameVillage"]]};
    case BW_TRAINING_OPERATION_ZONE_DRAW: {
        private _text = text nearestLocation [_markerPos, ["NameCity","NameCityCapital","NameVillage"], 300];
        if (_text == "") then {
            _text = "Custom";
        };
        _text
    };
    case BW_TRAINING_OPERATION_DEFEND: {"Defense"};
    default {"Unknown"};
};

if (_zoneName == "") then {
    _zoneName = str _zoneName;
};
["Info", ["Zone Init", format ["The next zone (%3) will be ready in %1:%2", floor (_timeToWait/60), _seconds, _zoneName]]] remoteExecCall ["BIS_fnc_showNotification"];

[{
    ["Info", ["Zone Init", format ["Zone (%1) initialization completed!", _this]]] remoteExecCall ["BIS_fnc_showNotification"];
}, _zoneName, _timeToWait] call CBA_fnc_waitAndExecute;
