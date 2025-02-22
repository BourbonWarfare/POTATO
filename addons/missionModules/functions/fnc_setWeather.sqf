/*
 * Author: AACO
 * Function used to set the weather
 * should only be called from the mission parameters
 *
 * Arguments:
 * 0: Weather 'enum' <NUMBER>
 *
 * Examples:
 * [-1] call potato_missionsModules_fnc_setWeather; // no weather changes
 * [0] call potato_missionsModules_fnc_setWeather; // sets to clear
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_weather"];

if (_weather == -1) exitWith {};

// return order: overcast, rain, lightning, wind strength, wind gusts, waves
private _fnc_getWeatherVars = {
    params ["_weather"];

    if (_weather == 0) exitWith { [0.15, 0, 0, 0,    0,    0] };
    if (_weather == 1) exitWith { [0.35, 0, 0, 0.25, 0.5,  0.25] };
    if (_weather == 2) exitWith { [0.35, 0, 0, 0.75, 1,    0.75] };
    if (_weather == 3) exitWith { [0.49, 0, 0, 0,    0,    0] };
    if (_weather == 4) exitWith { [0.49, 0, 0, 0.75, 0.25, 0.5] };
    if (_weather == 5) exitWith { [0.49, 0, 0, 0.75, 1,    0.75] };
    if (_weather == 6) exitWith { [1,    1, 0, 0.25, 0.5,  0.75] };
    if (_weather == 7) exitWith { [1,    1, 0, 0.75, 1,    0.75] };

    [1, 1, 1, 1, 1, 1]
};

(call _fnc_getWeatherVars) params [
    "_overcast",
    "_rain",
    "_lightnings",
    "_windStr",
    "_windGusts",
    "_waves"
];

0 setOvercast _overcast;
0 setRain _rain;
0 setLightnings _lightnings;
0 setWindStr _windStr;
0 setWindForce _windGusts;
0 setWaves _waves;

forceWeatherChange;
