#include "..\script_component.hpp"
/**************************************************************//*
* Author: Lambda.Tiger
* Description:
* This function finds all available artillery pieces and
*
* Arguments:
* _missionName - Name of the mission in
* _magazine - Magazine desired to be fired
*
* Example:
* ["mission0", "8Rnd_82mm_Mo_Smoke_white", [getPosATL player, getPosATL car], 5] call lmd_fnc_quereyArtilleryHandler;
*//**************************************************************/
params [
    ["_missionName", "", [""]],
    ["_magazine", "", [""]],
    ["_targPosesATL", [], [[]]],
    ["_gunCount", 1, [1]],
    ["_holdTime", 30, [30]]
];

if (_missionName == "" || _magazine == "" || _gunCount < 1 ||
    _targPosesATL isEqualTo [] || {isNil QGVAR(artilleryGunArray)}) exitWith {};
// Clean-up for expired guns
{
    (_x getVariable [QGVAR(artyMission), ["", -1, -1]]) params [
        "_missionName", "_status", "_holdTime"
    ];
    if (_missionName == "" || (_status in [ARTILLERY_MISSION_STATUS_WAIT, ARTILLERY_MISSION_STATUS_ASSIGN] &&
     _holdTime < CBA_missionTime)) then {
        _x setVariable [QGVAR(artyMission), nil];
    }
} forEach GVAR(artilleryGunArray);

private _artilleryPieces = [_targPosesATL, _magazine] call FUNC(selectCanFireRound);
_artilleryPieces = _artilleryPieces select [0, _gunCount];

if (_artilleryPieces isNotEqualTo []) then {
    private _holdTime = CBA_missionTime + _holdTime;
    {
        (_x#1) setVariable [QGVAR(artyMission), [
            _missionName,
            ARTILLERY_MISSION_STATUS_WAIT,
            _holdTime
        ]];
    } forEach _artilleryPieces;
    [QGVAR(addPossiblePieces), [_missionName, _artilleryPieces]] call CBA_fnc_serverEvent;
};
