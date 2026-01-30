#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Local handler to task artillery guns.
 * This function takes a mission ID, a list of artillery pieces,
 * a new status for the guns, and then extra mission parameters.
 * It uses these to assign a state to the gun, one of:
 * ARTILLERY_MISSION_STATUS_WAIT
 *   Wait for a time specified in _details to decide whether the gun is being
 *   used for a mission, or to wait for a follow-on fire mission.
 * ARTILLERY_MISSION_STATUS_ASSIGN
 *   The gun is definiteyl assigned to a mission and will wait to be provided
 *   further mission details, by default the max waiting time is five minutes.
 *   _details provides missionID and maximum hold time
 * ARTILLERY_MISSION_STATUS_FIRING
 *   This assigns the gun to the firing state and begins a fire mission.
 *   _details contains a number of mission parameters see line 83
 * ARTILLERY_MISSION_STATUS_FREE
 *   Frees the gun from other status, readying it to be selected for
 *   future missions.
 *
 * Arguments:
 * _missionID - Unique fire mission ID. STRING, default ""
 * _artyPieces - All artillery pieces assigned to the mission, including non-local.
 *               ARRAY of objects, default []
 * _newStatus - The new state the artillery pieces should enter. SCALAR, default ARTILLERY_MISSION_STATUS_FREE
 * _details - State details, see above. ARRAY, default []
 *
 * Return:
 * None
 *
 * Example:
 * ["lambda123",[arty0],ARTILLERY_MISSION_STATUS_FREE] call potato_artillery_fnc_localArtilleryHandler;
 *
 * Public: No
 */
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
            ["_dispersion", 100, [100]],
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
            private _weapon = GVAR(vehicleWeaponCache) getOrDefaultCall [typeOf _gun, {
                private _cfg = (configOf _gun) >> "Turrets";
                private _turret = 0;
                while {getNumber ((_cfg select _turret) >> "primaryGunner") == 0} do {_turret = _turret + 1;};
                (_gun weaponsTurret [_turret])#0
            }, true];
            private _reloadTime = [_weapon] call FUNC(getArtyReloadTime);
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
