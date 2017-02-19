/*
 * Author: AACO
 * Function used to show the displays to clients
 *
 * Arguments:
 * 0: Display the timer? <BOOL>
 *
 * Examples:
 * [true] call potato_safeStart_fnc_createDisplay;
 * [false] call potato_safeStart_fnc_createDisplay;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_layer", "_display", ["_showOnMap", false, [false]]];

if (isNull (uiNamespace getVariable [_display, displayNull])) then {
    LOG("Creating display");
    _layer cutRsc [_display, "PLAIN", 1, _showOnMap];
};
