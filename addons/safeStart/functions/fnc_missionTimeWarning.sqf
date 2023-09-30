/*
 * Author: BadWolf
 * Function used to start/stop mission length timer
 * Sould only be called on the server
 *
 * Arguments:
 * 0: Start mission length warnings <BOOL>
 *
 * Examples:
 * [] call potato_safeStart_fnc_missionTimeWarning;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if !(isServer) exitWith {};

params [];

private _missionLength = getMissionConfigValue [QEGVAR(missionTesting,missionTimeLength),0];
if (_missionLength isEqualType "") then { _missionLength = parseNumber _missionLength; }; // BWC with old attribute that was string
private _missionLengthSec = _missionLength * 60;

if (_missionLength == 0) then {
    private _missionType = getMissionConfigValue QEGVAR(missionTesting,missionType);
    switch (_missionType) do {
        case 1: {_missionLength = 65};
        case 2: {_missionLength = 35};
        default {if(true) exitWith {TRACE_1("Something is seriously wrong, exiting timer",_missionType)}};
    };
};

missionNamespace setVariable [QGVAR(missionstartTime), CBA_missionTime, true];
TRACE_1("Mission start time",QGVAR(missionstartTime));

// 15 min Warning
[
    {
        params ["_missionLengthSec"];
        private _missionStartTime = missionNamespace getVariable QGVAR(missionstartTime);
        (CBA_missionTime >= (_missionStartTime + _missionLengthSec - 900))  || !(isNil QGVAR(timerID))
    },
    {
        if (isNil QGVAR(timerID)) then {
            [
                "potato_adminMsg",
                [
                    "15 mins to mission end",
                    "Time Keeper"
                ]
            ] call CBA_fnc_globalEvent;
            {
                [QGVAR(curatorHint_TimeKeeper_15min),[],getAssignedCuratorUnit _x] call CBA_fnc_targetEvent;
            } forEach allcurators;
            //End Warning
            [
                {
                    [
                        "potato_adminMsg",
                        [
                            "Mission Time has expired",
                            "Time Keeper"
                        ]
                    ] call CBA_fnc_globalEvent;
                    {
                        [QGVAR(curatorHint_TimeKeeper_end),[],getAssignedCuratorUnit _x] call CBA_fnc_targetEvent;
                    } forEach allcurators;
                },
                [],
                900
            ] call CBA_fnc_waitAndExecute;
        };
    },
    [_missionLengthSec]
] call CBA_fnc_waitUntilAndExecute;

// Add Map Marker at 0,0 position with mission end time.

// Check if mission end map marker already exists.

private _startTime = daytime;
private _endTimeDec = _startTime + (_missionLength / 60);
private _endTime = [_endTimeDec] call BIS_fnc_timeToString;

private _string = format ["|_USER_DEFINED missionEndMarker_0|[0,0,0.0000]|mil_warning|ICON|[1,1]|0|Solid|colorCivilian|1|Mission End Time - %1",_endTime];
[QGVAR(addMissionEndMarkerLocal),[_string]] call CBA_fnc_globalEventJIP;
