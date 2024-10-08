#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Initializes force safe start end.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * call potato_safeStart_fnc_forceEndSafeStart;
 *
 * Public: No
 */

params [["_minTime", 0.001, [0]]];

if (!(isServer && GVAR(enabled) && GVAR(safeStartEnabled)) ||
   {!(getMissionConfigValue [QEGVAR(missionTesting,SSForceEnd), false])}) exitWith {
    TRACE_2("Did not initialize force end safe start",isServer,GVAR(enabled));
};
private _serverStartTimePV = missionNamespace getVariable [QGVAR(startTime_PV), CBA_missionTime];
private _safeStartLength = (getMissionConfigValue [QEGVAR(missionTesting,SSTimeGiven), 15]) * 60 + _serverStartTimePV;
[
    {
        params ["_safeStartLength"];
        TRACE_3("Attempting to end safe start:",CBA_missionTime,_safeStartLength,GVAR(safeStartSafetyOn));
        if (GVAR(safeStartSafetyOn) || CBA_missionTime < _safeStartLength) then {
            5 call FUNC(initForceEndSafeStart);
        } else {
            [false] call potato_safeStart_fnc_toggleSafeStart;
        };
    },
    [_safeStartLength],
     _minTime max (_safeStartLength - CBA_missionTime)
] call CBA_fnc_waitAndExecute;
