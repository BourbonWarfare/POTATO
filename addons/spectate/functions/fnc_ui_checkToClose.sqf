/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
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
