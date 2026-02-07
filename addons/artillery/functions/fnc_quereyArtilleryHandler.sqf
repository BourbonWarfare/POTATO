#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This functio takes a mission ID, magazine, array of taret positions, the
 * number of guns requested, and a hold time to send a list of valid guns to
 * the server. The function itself should be called on server request.
 * The mission name is used to reserve guns for specific missions and the
 * requested magazine is used to both decide if the gun is in range and can
 * fire the desired rounds. The array of target positions generally define
 * the area the mission will take place in. The list of valid guns is limited
 * to _gunCount, and the guns returned to the server are reserved for the
 * possible fire mission for _holdTime seconds.
 *
 * Arguments:
 * _missionName - The unique mission ID. STRING, default ""
 * _magazine - The magazine desired to be fired. STRING, default ""
 * _targPosesATL - An array of positions the gun will be asked to fire on in
                   ATL format. ARRAY, default []
 * _gunCount - The number of guns requested. SCALAR, default 1
 * _holdTime - Time to wait before releasing a valid gun back into the fire
               mission pool. SCALAR, default 30
 *
 * Return:
 * None
 *
 * Example:
 * ["lambda123", "8Rnd_82mm_Mo_Smoke_white", [getPosATL player, getPosATL car], 5]] call potato_artillery_fnc_quereyArtilleryHandler;
 *
 * Public: No
 */
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
