/*
 * Author: AACO
 * Function used to update the timer
 * Should only be called from an event handler
 *
 * Examples:
 * [] call potato_safeStart_fnc_updateTimer;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

private _serverStartTimePV = missionNamespace getVariable [QGVAR(startTime_PV), -1];

if (_serverStartTimePV == -1 || isNull (uiNamespace getVariable [QGVAR(timerRscTitle), displayNull])) exitWith {
    TRACE_2("Bad values",_serverStartTimePV,uiNamespace getVariable QGVAR(timerRscTitle));
};

((uiNamespace getVariable [QGVAR(timerRscTitle), displayNull]) displayCtrl HINT_IDC) ctrlSetStructuredText parseText ([_serverStartTimePV] call FUNC(getFormattedTimeText));
