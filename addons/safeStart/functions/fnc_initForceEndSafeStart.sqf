#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will create a delayed event to turn of safe start at the
 * expected end time, or at least _minTime seconds later. If Safe Start
 * is already off, or disabled for the mission, this function exits.
 *
 * Arguments:
 * 0: The minimum amount of time to delay before adding a Safe Start
 *    event (NUMBER).
 *
 * Return Value:
 * None
 *
 * Examples:
 * 5 call potato_safeStart_fnc_initForceEndSafeStart;
 *
 * Public: No
 */

params [["_minTime", 0.001, [0]]];

// We don't need to run this function if we're not on the server,
// or safe star is not enabled for the mission, or safe start is not on,
// or if the mission hasn't been configured to force safe start to end
if (!(isServer && GVAR(enabled) && GVAR(safeStartEnabled)) ||
   {!(getMissionConfigValue [QEGVAR(missionTesting,SSForceEnd), false])}) exitWith {
    TRACE_2("Did not initialize force end safe start",isServer,GVAR(enabled));
    // Send message to admins
    private _missionType = getMissionConfigValue[QEGVAR(missionTesting,missionType), 0];
    if (isServer && isMultiplayer && !(is3DEN || is3DENPreview) && _missionType == 2) then {
        [
            "potato_adminMsg",
            [
                "Safe start will not automatically end.",
                "Server", "Admins"
            ]
        ] call CBA_fnc_globalEvent;
    };
};

// Check safe start "0" time or use CBA_missionTime
private _serverStartTimePV = missionNamespace getVariable [QGVAR(startTime_PV), CBA_missionTime];
private _safeStartLength = (getMissionConfigValue [QEGVAR(missionTesting,SSTimeGiven), 15]) * 60 + _serverStartTimePV;

[
    {
        params ["_safeStartLength"];
        if !(GVAR(safeStartEnabled)) exitWith {
            TRACE_3("Aborting auto end safe start:",CBA_missionTime,_safeStartLength,GVAR(safeStartSafetyOn));
        };
        TRACE_3("Attempting to end safe start:",CBA_missionTime,_safeStartLength,GVAR(safeStartSafetyOn));
        // Only exit safe start if the safety is off and it's passed the end of safe start
        if (GVAR(safeStartSafetyOn) || CBA_missionTime < _safeStartLength) then {
            [{CBA_missionTime >= _this && !GVAR(safeStartSafetyOn)},{
                [false] call FUNC(toggleSafeStart);
            }, _safeStartLength, 30, {
                if !(GVAR(safeStartEnabled)) then {
                    call FUNC(initForceEndSafeStart);
                };
            }] call CBA_fnc_waitUntilAndExecute;
        } else {
            [false] call FUNC(toggleSafeStart);
        };
    },
    [_safeStartLength],
    _minTime max (_safeStartLength - CBA_missionTime - 1)
] call CBA_fnc_waitAndExecute;
