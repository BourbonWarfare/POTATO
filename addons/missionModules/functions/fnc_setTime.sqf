/*
 * Author: AACO
 * Function used to set the time of day
 * should only be called from the mission parameters
 *
 * Arguments:
 * 0: Time of day 'enum' <NUMBER>
 *
 * Examples:
 * [-1] call potato_missionsModules_fnc_setTime; // no time changes
 * [0] call potato_missionsModules_fnc_setTime; // sets to 4:50am
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_timeOfDay"];

if (_timeOfDay == -1) exitWith {};

private _fnc_getTimeVars = {
    params ["_timeOfDay"];

    if (_timeOfDay == 0) exitWith { [4, 50] };
    if (_timeOfDay == 1) exitWith { [5, 20] };
    if (_timeOfDay == 2) exitWith { [9, 20] };
    if (_timeOfDay == 3) exitWith { [12, 0] };
    if (_timeOfDay == 4) exitWith { [15, 30] };
    if (_timeOfDay == 5) exitWith { [18, 40] };
    if (_timeOfDay == 6) exitWith { [19, 10] };

    [0, 0]
};

(call _fnc_getTimeVars) params ["_hour", "_minute"];

private _now = date;
[[_now select 0, _now select 1, _now select 2, _hour, _minute]] call BIS_fnc_setDate;
