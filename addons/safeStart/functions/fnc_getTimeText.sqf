/*
 * Author: AACO
 * Function used to convert a number into a HH:MM:SS formatted string
 *
 * Arguments:
 * 0: Seconds since timer started <NUMBER>
 *
 * Return Value:
 * A HH:MM:SS formatted string of time number of seconds since the provided started time <STRING>
 *
 * Examples:
 * [5] call potato_safeStart_fnc_getTimeText; // returns "00:00:05"
 * [61] call potato_safeStart_fnc_getTimeText; // return "00:01:01"
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

private _elapsedTime = CBA_missionTime - (_this select 0);

format [
    "<t align='center'>Safe Start Enabled<br/>%1 %2:%3:%4</t>",
    "<img image='\A3\UI_F\data\IGUI\Cfg\Actions\settimer_ca.paa'/>",
    [floor (((_elapsedTime / 60) / 60) % 24)] call FUNC(getTimeStrFromNum),
    [floor ((_elapsedTime / 60) % 60)] call FUNC(getTimeStrFromNum),
    [floor (_elapsedTime % 60)] call FUNC(getTimeStrFromNum)
]
