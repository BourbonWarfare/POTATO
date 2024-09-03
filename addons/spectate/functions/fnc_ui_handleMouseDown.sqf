/*
 * Author: AACO
 * Function used to handle mouse down events
 * Should only be called from events
 *
 * Arguments:
 * 1: Button index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,0] call potato_spectate_fnc_ui_handleMouseDown;
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
            playSound "ReadoutHideClick1";
        };
    } else {
        playSound "ReadoutClick";
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
