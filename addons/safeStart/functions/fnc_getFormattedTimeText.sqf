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

format [
    "<t align='center'>Safe Start Enabled<br/><img image='\A3\UI_F\data\IGUI\Cfg\Actions\settimer_ca.paa'/> %1</t>",
    [CBA_missionTime - (_this select 0)] call CFUNC(getTimeText)
]
