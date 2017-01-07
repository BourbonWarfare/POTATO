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

params ["", "_button"];

// left click
if (_button == 0) exitWith {
    if (isNull GVAR(cursorObject)) then {
        if (!isNull GVAR(camTarget)) then {
            playsound "ReadoutHideClick1";
        };
    } else {
        playsound "ReadoutClick";
        setMousePosition [0.5, 0.5];
    };
    [GVAR(cursorObject)] call FUNC(setFocus);
};

// right click
if (_button == 1) exitWith {
    if (GVAR(currentCamIndex) == FREE_CAMERA && { !isNull GVAR(camTarget) } && { !isNull (attachedTo GVAR(dummy)) }) then {
        [] call FUNC(resetTarget);
    };
    GVAR(holdingRightMouse) = true;
};
