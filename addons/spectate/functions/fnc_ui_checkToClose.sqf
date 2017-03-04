/*
 * Author: AACO
 * Function used to check to see if the UI should close (ABORT selected)
 * Should only be called from events
 *
 * Arguments:
 * 2: Exit code <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,nil,104] call potato_spectate_fnc_ui_checkToClose;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["", "", "_exitCode"];

if (_exitCode == 104) exitWith {
    OVERLAY closeDisplay 2;
    MAIN_DISPLAY closeDisplay 2;
};

if (GVAR(currentCamIndex) == FREE_CAMERA) then {
    GVAR(cam) camCommand "manual on";
};
