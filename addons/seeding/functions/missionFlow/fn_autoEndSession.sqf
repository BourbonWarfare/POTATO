#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion will check if the mission is started on the same day as a
* session, and then if it is, add a CBA waitAndExecute call to end the
* mission at the desired time.
*
* Arguments:
* _minutesBeforeSession - The number of minutes before session the seeding
*                   mission should end
*
* Return:
* none
*
* Example:
* [15] call bw_fnc_autoEndSession; // end 15 minutes before session time
* [] call bw_fnc_autoEndSession; // end 20 minutes before session time
*//***************************************************************************/
params [["_minutesBeforeSession", 20, [123]]];
systemTime params ["_year", "_month", "_day", "_hour", "_minute", "_second"];
private _days = 0;
for "_i" from 1970 to _year - 1 do
{
	_days = _days + round linearConversion [0, 1, dateToNumber [_i, 12, 32, 0, 0], 0, 365, false];
};
_days = _days + linearConversion [0, 1, dateToNumber [_year, _month, _day, 0, 0], 0, 365, false];

private _isSessionDay = (_days mod 7) in [3, 6];
if (_isSessionDay && _hour < 19) then {
    _hour = 19 - _hour - 1;
    _minute = 60 - _minute - _minutesBeforeSession - 1;
    _second = 60 - _second - 5;
    private _secondsToEnd = 0 max (_hour * 3600 + _minute * 60 + _second);
    [{
        params ["_extraMinutesBeforeSession", "_sessionEndTime"];
        private _deltaMinutes = round ((_sessionEndTime - CBA_missionTime) / 60);
        [parseText format ["%1 minutes until session.<br/>Ending in %2 minutes", _extraMinutesBeforeSession + _deltaMinutes, _deltaMinutes]] remoteExecCall ["hint"];
        remoteExecCall [QFUNC(autoEndSessionAI)];
        }, [_minutesBeforeSession, _secondsToEnd + CBA_missionTime], 0 max (_secondsToEnd - 600)] call CBA_fnc_waitAndExecute;
    [{remoteExecCall [QFUNC(endMission)]}, [], _secondsToEnd] call CBA_fnc_waitAndExecute;
    diag_log formatText ["[SEED] End mission %1 minutes before session (in %2).", _minutesBeforeSession, [_secondsToEnd] call CBA_fnc_formatElapsedTime];
};
