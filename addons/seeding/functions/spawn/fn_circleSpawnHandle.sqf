#include "..\..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This function handles the circle spawner every 10-20 seconds to upkeep units
* moving towards a central point. Units are spawned on a given side used to
* attack
*
*
* Arguments:
* None
*
* Return:
* None
*
* Example:
* [] call lmd_fnc_circleSpawnHandle;
******************************************************************************/
if (isNil QGVAR(circleSpawners)) exitWith {};

private _spawnerArr = GVAR(circleSpawners);
private _deleteArr = [];
{
    _x params ["_endTime", "_areaParams", "_sideAttackers", "_sideDefenders", "_minUnitCount", "_goalUnitCount", ["_minRad", 400], ["_angleParams", [0, 360, 20]], ["_randChance", CIRCLESPAWN_VIC_STARTING], ["_artyRoundTypes", [], [[]]], ["_unitAngleCount", []]];
    if (_endTime < CBA_missionTime) then {
        _deleteArr pushBack _forEachIndex;
        continue;
    };
    if (_goalUnitCount isEqualType {}) then {
        _goalUnitCount = 200 min round call _goalUnitCount;
    };
    if (_minUnitCount isEqualType {}) then {
        _minUnitCount = round _goalUnitCount call _minUnitCount;
    };
    if (GVAR(endOfMission)) then {
        _goalUnitCount = 200 / (count _spawnerArr);
        _minUnitCount = 0.9 * _goalUnitCount;
        _randChance = CIRCLESPAWN_VIC_END_RATE;
    };
    if (random 1 > _randChance) then {
        private _sideConfig = switch (_sideAttackers) do {
            case east: {"potato_e"};
            case west: {"potato_w"};
            case resistance: {"potato_i"};
            case civilian: {"CIV_F"};
            default {"potato_e"};
        };
        private _vicArr = ["armedSoftVehiclePool", "armoredVehiclePool", "tankVehiclePool"] selectRandomWeighted [0.7, 0.2, 0.1];
        private _vicType = selectRandom getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> _vicArr);
        [[_areaParams#0, _vicType, _sideAttackers, _angleParams#0, _angleParams#1], QFUNC(circleSpawnVehicle)] call PFUNC(zeusHC,hcPassthrough);
        if (random 1 < 0.1) then {
            private _angle = (_angleParams#0) + random ((_angleParams#1) - (_angleParams#0));
            private _pos = (_areaParams#0) getPos [4500, _angle];
            private _aircraftType = getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> (selectRandomWeighted ["heliVehiclePool",0.9,"planeVehiclePool",0.1]));
            if (_aircraftType isEqualTo []) exitWith {};
            _pos set [2, 100];
            [[_areaParams#0, selectRandom _aircraftType, _pos, _sideAttackers, true], QFUNC(spawnAircraft)] call PFUNC(zeusHC,hcPassthrough);
        };
        _x set [8, CIRCLESPAWN_VIC_STARTING];
    } else {
        _x set [8, _randChance * CIRCLESPAWN_VIC_DECAY];
    };
    private _unitsToCount = units _sideAttackers;
    private _closeCount = _unitsToCount inAreaArray [_areaParams#0, 50, 50, 0];
    if (count _closeCount > 10) then {
        private _flags = (_areaParams#0) nearObjects [BW_TP_FLAG_TYPE, 100];
        if (_flags isEqualTo []) exitWith {};
        ["Notif_Overrun"]  remoteExecCall ["BIS_fnc_showNotification", -2];
        _deleteArr pushBack _forEachIndex;
        {
            private _flag = _x;
            private _flagMarker = _flag getVariable [QGVAR(attachedMarker), ""];
            private _flagIndex = _flag getVariable [QGVAR(respawnIndex), []];
            if (_flagIndex isNotEqualTo []) then {
                _flagIndex call BIS_fnc_removeRespawnPosition;
            };
            deleteMarker _flagMarker;
            deleteVehicle _flag;
        } forEach _flags;
    };
    private _unitCount = count (_unitsToCount inAreaArray _areaParams);
    if (_unitCount >= _minUnitCount) then {continue};
    private _unitsToAdd = _goalUnitCount - _unitCount;
    while {_unitsToAdd > 0} do {
        private _groupSize = floor random [4, 5, 9];
        private _spawnPos = [_areaParams#0, _sideDefenders, _areaParams#1, _unitAngleCount, _minRad, _angleParams] call FUNC(findArcSpawnPos);
        if (_spawnPos isNotEqualTo [0, 0, 0]) then {
            _unitsToAdd = _unitsToAdd - _groupSize;
            [
                {[_this, QFUNC(spawnUnitsWP)] call PFUNC(zeusHC,hcPassthrough);},
                [_areaParams#0, _spawnPos, _groupSize, _sideAttackers],
                random 8
            ] call CBA_fnc_waitAndExecute;
        };
    };
} forEach _spawnerArr;

{
    _spawnerArr deleteAt _x;
} forEachReversed _deleteArr;

if (_spawnerArr isNotEqualTo []) then {
    [{call FUNC(circleSpawnHandle)}, 0, 10 + random 10] call CBA_fnc_waitAndExecute;
};
