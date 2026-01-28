#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function beginning a mission, it will begin by pulling the mission from
 * the local hash. If no guns are able to participate in the mission, the
 * mission fails to run and a notification is sent if clientID is valid. Guns
 * are then chosen from possible guns, as well as guns to release from the
 * mission. Depending on the mission type a call is made to the guns involved
 * and the rest of the guns are released from a temporary hold.
 *
 * Arguments:
 * _missionID - A unique string for the mission, these are not purged, STRING, default ""
 *
 * Example:
 * ["lambda123"] call potato_artillery_fnc_beginMission;
 *
 * Public: No
 */
params [["_missionID", "", [""]]];

if (_missionID == "" || !(_missionID in GVAR(artilleryMissionCache))) exitWith {};
(GVAR(artilleryMissionCache) getOrDefault [_missionID, []]) params [
    ["_clientID", 2],
    ["_possibleGuns", []],
    "_roundType",
    ["_centerPosATL", [0, 0, 0]],
    ["_gunCount", 2],
    "_missionType",
    ["_dispersion", 60],
    ["_rotation", 0],
    ["_avoidPlayers", false],
    ["_roundCount", 4],
    ["_missionLength", 180],
    ["_parentMission", ""]
];
_roundType params ["_caliber", "_magazine"];

if (_possibleGuns isEqualTo []) exitWith {
    if (_clientID > 2 || is3DENPreview) then {
        ["artyNoGunsNotif"] remoteExecCall ["BIS_fnc_showNotification", _clientID];
    };
};

// pick guns
_possibleGuns sort true; // sort by descending TOF;
private _gunsToUse = _possibleGuns select [0, _gunCount];
private _gunsToRelease = _possibleGuns - _gunsToUse;
_gunsToRelease = _gunsToRelease apply {_x#1};
_gunCount = count _gunsToUse;
private _maxTof = selectMax (_gunsToUse apply {_x#0});

// start fire mission
switch (_missionType) do {
    case ARTILLERY_MISSIONTYPE_LAZY_BARRAGE;
    case ARTILLERY_MISSIONTYPE_BRACKET_BARRAGE;
    case ARTILLERY_MISSIONTYPE_POINT: {
        _gunsToUse = _gunsToUse apply {[_x#1, _x#0]};

        [QGVAR(issueArty), [
            _missionID,
            _gunsToUse,
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_POINT,
                _magazine,
                _centerPosATL,
                _roundCount,
                _avoidPlayers,
                _dispersion,
                _rotation
            ]
        ], _gunsToUse apply {_x#0}] call CBA_fnc_targetEvent;
    };
    case ARTILLERY_MISSIONTYPE_SLOW: {
        _gunsToUse = _gunsToUse apply {[_x#1, _x#0]};

        [QGVAR(issueArty), [
            _missionID,
            _gunsToUse,
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_SLOW,
                _magazine,
                _centerPosATL,
                _roundCount,
                _avoidPlayers,
                _dispersion,
                _rotation,
                -1,
                _missionLength
            ]
        ], _gunsToUse apply {_x#0}] call CBA_fnc_targetEvent;
    };
    case ARTILLERY_MISSIONTYPE_LINEAR_WITH_WALK;
    case ARTILLERY_MISSIONTYPE_LINEAR: {
        private _halfStep = _dispersion / _gunCount;
        private _stepLength = 2 * _halfStep;
        private _beginPos = _centerPosATL getPos [_dispersion - _halfStep, _rotation - 180];
        for "_i" from 0 to count _gunsToUse - 1 do {
            _gunsToUse set [_i, [_gunsToUse#_i#1, _gunsToUse#_i#0, _beginPos]];
            _beginPos = _beginPos getPos [_stepLength, _rotation];
        };
        [QGVAR(issueArty), [
            _missionID,
            _gunsToUse,
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_LINEAR,
                _magazine,
                _beginPos,
                _roundCount,
                _avoidPlayers,
                _halfStep,
                _rotation,
                _maxTof
            ]
        ], _gunsToUse apply {_x#0}] call CBA_fnc_targetEvent;
    };
    case ARTILLERY_MISSIONTYPE_BRACKET_SHOTS: {
        private _holdGuns = (_gunsToUse select [1]) apply {_x#1}; // selects all but first element
        private _bracketGun = _gunsToUse#0#1;
        private _tof = _gunsToUse#0#0;
        [QGVAR(issueArty), [
            _missionID,
           [[_bracketGun, _tof + 5]],
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_BRACKET_SHOTS,
                _magazine,
                _centerPosATL,
                _roundCount,
                _avoidPlayers,
                _dispersion,
                _rotation
            ]
        ], _bracketGun] call CBA_fnc_targetEvent;

        [QGVAR(issueArty), [
            _missionID,
            _holdGuns,
            ARTILLERY_MISSION_STATUS_ASSIGN, [
                ARTILLERY_MISSIONTYPE_BRACKET_BARRAGE,
                4 * (_tof + 10) + 30
            ]
        ], _holdGuns] call CBA_fnc_targetEvent;
    };
    case ARTILLERY_MISSIONTYPE_CREEPING: {
        private _step = switch (true) do {
            case (_caliber < 100): {30};
            case (_caliber < 120): {40};
            case (_caliber < 150): {50};
            case (_caliber < 200): {60};
            default {40};
        };
        private _halfWidth = (_gunCount - 1) * _step;
        private _beginPos = _centerPosATL getPos [_halfWidth, _rotation - 90];
        _step = [0, 0, 0] getPos [_step, _rotation + 90];
        if ((_gunCount mod 2) == 0) then {
            private _halfStep = _step vectorMultiply 0.5;
            _beginPos = _beginPos vectorAdd _halfStep;
        };
        for "_i" from 0 to count _gunsToUse - 1 do {
            _gunsToUse set [_i, [_gunsToUse#_i#1, _gunsToUse#_i#0, _beginPos]];
            _beginPos = _beginPos vectorAdd _step;
        };
        [QGVAR(issueArty), [
            _missionID,
            _gunsToUse,
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_CREEPING,
                _magazine,
                _beginPos,
                _roundCount,
                _avoidPlayers,
                _dispersion,
                _rotation,
                _maxTof
            ]
        ], _gunsToUse apply {_x#0}] call CBA_fnc_targetEvent;
    };
    case ARTILLERY_MISSIONTYPE_LAZY_WALK: {
        private _holdGuns = (_gunsToUse select [1]) apply {_x#1}; // selects all but first element
        private _bracketGun = _gunsToUse#0#1;
        private _tof = _gunsToUse#0#0;
        [QGVAR(issueArty), [
            _missionID,
           [[_bracketGun, _tof]],
            ARTILLERY_MISSION_STATUS_FIRING, [
                ARTILLERY_MISSIONTYPE_LAZY_WALK,
                _magazine,
                _centerPosATL,
                _roundCount,
                _avoidPlayers,
                _dispersion,
                _rotation
            ]
        ], _bracketGun] call CBA_fnc_targetEvent;

        [QGVAR(issueArty), [
            _missionID,
            _holdGuns,
            ARTILLERY_MISSION_STATUS_ASSIGN, [
                ARTILLERY_MISSIONTYPE_LAZY_BARRAGE,
                8 * (_tof + 10)
            ]
        ], _holdGuns] call CBA_fnc_targetEvent;
    };
    default {};
};

if (_clientID > 2 || is3DENPreview) then {
    private _missionTypeStr = switch (_missionType) do {
        case ARTILLERY_MISSIONTYPE_LAZY_BARRAGE;
        case ARTILLERY_MISSIONTYPE_BRACKET_BARRAGE;
        case ARTILLERY_MISSIONTYPE_POINT: {"Area Barrage"};
        case ARTILLERY_MISSIONTYPE_LAZY_WALK: {"Lazy Walk onto target"};
        case ARTILLERY_MISSIONTYPE_LINEAR_WALK;
        case ARTILLERY_MISSIONTYPE_BRACKET_SHOTS: {"Bracketing Rounds"};
        case ARTILLERY_MISSIONTYPE_LINEAR: {"Linear Barrage"};
        case ARTILLERY_MISSIONTYPE_CREEPING: {"Creeping Barrage"};
        case ARTILLERY_MISSIONTYPE_SLOW: {"Slow Barrage"};
        default {"Err"};
    };
    ["artyNotif", [format ["Beginning %1 using %2 rounds [%3x %4mm]",
        _missionTypeStr,
        getText (configFile >> "CfgMagazines" >> _magazine >> "displayNameShort"),
        _gunCount,
        _caliber
    ]]] remoteExecCall ["BIS_fnc_showNotification", _clientID];
};
// tell guns they're reserved for follow on missions or released into the pool
[QGVAR(issueArty), [
    _missionID,
    _gunsToRelease,
    ARTILLERY_MISSION_STATUS_FREE
], _gunsToRelease] call CBA_fnc_targetEvent;
