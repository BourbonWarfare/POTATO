/*
 * Author: AACO
 * Function used to set the level of fog
 * should only be called from the mission parameters
 *
 * Arguments:
 * 0: Fog level 'enum' <NUMBER>
 *
 * Examples:
 * [-1] call potato_missionsModules_fnc_setFog; // no fog changes
 * [0] call potato_missionsModules_fnc_setFog; // no fog
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_fog"];

// ensure fog level remains untouched, if the parameter is unset
if (_fog == -1) exitWith {};

// set fog level
0 setFog [_fog, 0, 0];
