#include "..\script_component.hpp"
/**************************************************************//*
* Selects and returns artillery pieces that can fire given
* magazine at a given point ordered by TOF
*
* Arguments:
* _targetAGL - Position (AGL) of the target
* _magazine - Magazine desired to be fired
*
* Example:
* [[12,42,0], "8Rnd_82mm_Mo_Smoke_white"] call lmd_fnc;
*//**************************************************************/
params [
    ["_missionID", "", [""]],
    ["_artyPieces", [], [[]]],
    ["_newStatus", ARTILLERY_MISSION_STATUS_FREE, [ARTILLERY_MISSION_STATUS_FREE]],
    ["_details", [], [[]]]
];
_artyPieces = _artyPieces select {
    if (_x isEqualType []) then {
        local (_x#0)
    } else {
        local _x
    }
};
if (_missionID == "" || _artyPieces isEqualTo []) exitWith {};

switch (_newStatus) do {
    case ARTILLERY_MISSION_STATUS_WAIT: {
        _details params [
            ["_holdTime", 30, [30]]
        ];
        _holdTime = _holdTime + CBA_missionTime;
        {
            _x setVariable  [QGVAR(artyMission), [
                _missionID,
                ARTILLERY_MISSION_STATUS_WAIT,
                _holdTime
            ]];
        } forEach _artyPieces;
    };
    case ARTILLERY_MISSION_STATUS_ASSIGN: {
        _details params [
            ["_missionType", ARTILLERY_MISSIONTYPE_POINT, [ARTILLERY_MISSIONTYPE_POINT]],
            ["_holdTime", 300, [300]]
        ];
        _holdTime = _holdTime + CBA_missionTime;
        {
            _x setVariable  [QGVAR(artyMission), [
                _missionID,
                ARTILLERY_MISSION_STATUS_ASSIGN,
                _holdTime,
                _missionType
            ]];
        } forEach _artyPieces;
    };
    case ARTILLERY_MISSION_STATUS_FIRING: {
        _details params [
            ["_missionType", ARTILLERY_MISSIONTYPE_POINT, [ARTILLERY_MISSIONTYPE_POINT]],
            ["_magazine", "", [""]],
            ["_posATL", [0, 0, 0], [[]]],
            ["_rounds", 4, [4]],
            ["_avoidPlayers", true, [true]],
            ["_dispersion", 60, [60]],
            ["_rotation", 0, [0]],
            ["_tofMax", -1, [-1]],
            ["_length", 180, [180]]
        ];
        if (_magazine == "" && _posATL isEqualTo [0, 0, 0]) exitWith {};
        {
            _x params [
                "_gun",
                ["_tof", -1, [-1]],
                ["_offset", [0, 0, 0], [[]]]
            ];
            private _reloadTime = [(weapons _gun)#0] call FUNC(getArtyReloadTime);
            private _holdTime = CBA_missionTime + 2 * (_reloadTime + 5) * _rounds;
            _gun setVariable  [QGVAR(artyMission), [
                _missionID,
                ARTILLERY_MISSION_STATUS_FIRING,
                _holdTime,
                _missionType
            ]];
            if (_tofMax > 0 && _tof > 0 && _tofMax - _tof > 0) then {
                [{call FUNC(localMissionInit)}, [
                    _gun, _offset, _missionType, _magazine, _posATL, _dispersion,
                    _rotation, _avoidPlayers, _rounds, _tof,
                    _artyPieces find _x, count _artyPieces, _length],
                    _tofMax - _tof] call CBA_fnc_waitAndExecute;
            } else {
                [_gun, _offset, _missionType, _magazine, _posATL, _dispersion,
                    _rotation, _avoidPlayers, _rounds, _tof,
                    _artyPieces find _x, count _artyPieces, _length] call FUNC(localMissionInit);
            };
        } forEach _artyPieces;
    };
    default {
        {
            (_x getVariable [QGVAR(artyMission), ["", -1, -1]]) params [
                "_missionName", "_status", "_holdTime"
            ];
            if (_missionName == _missionID) then {
                _x setVariable  [QGVAR(artyMission), nil];
            };
        } forEach _artyPieces;
    };
};
