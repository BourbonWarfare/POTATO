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
// or it's not enabled, or
if (!(isServer && GVAR(enabled) && GVAR(safeStartEnabled)) ||
   {!(getMissionConfigValue [QEGVAR(missionTesting,SSForceEnd), false])}) exitWith {
    TRACE_2("Did not initialize force end safe start",isServer,GVAR(enabled));
};

// Check safe start "0" time or use CBA_missionTime
private _serverStartTimePV = missionNamespace getVariable [QGVAR(startTime_PV), CBA_missionTime];
private _safeStartLength = (getMissionConfigValue [QEGVAR(missionTesting,SSTimeGiven), 15]) * 60 + _serverStartTimePV;

[
    {
        params ["_safeStartLength"];
        TRACE_3("Attempting to end safe start:",CBA_missionTime,_safeStartLength,GVAR(safeStartSafetyOn));
        // Only exit safe start if the safety is off and it's passed het end of safe start
        if (GVAR(safeStartSafetyOn) || CBA_missionTime < _safeStartLength) then {
            5 call FUNC(initForceEndSafeStart);
        } else {
            [false] call potato_safeStart_fnc_toggleSafeStart;
        };
    },
    [_safeStartLength],
     _minTime max (_safeStartLength - CBA_missionTime)
] call CBA_fnc_waitAndExecute;
