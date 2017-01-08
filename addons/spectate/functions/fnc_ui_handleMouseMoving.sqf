/*
 * Author: AACO
 * Function used to handle mouse moving events
 * Should only be called from events
 *
 * Arguments:
 * 1: Delta X <NUMBER>
 * 2: Delta Y <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,0,2] call potato_spectate_fnc_ui_handleMouseMoving;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(currentCamIndex) == THIRD_PERSON && { GVAR(holdingRightMouse) }) then {
    params ["", "_deltaX", "_deltaY"];

    if (_deltaX != 0.0) then {
        GVAR(thirdPersonCamYaw) = ((GVAR(thirdPersonCamYaw) + (_deltaX * 100 * GVAR(camDeltaTime)) + 180.0) % 360.0) - 180;
    };

    if (_deltaY != 0.0) then {
        GVAR(thirdPersonCamPitch) = (((GVAR(thirdPersonCamPitch) - (_deltaY * 100 * GVAR(camDeltaTime))) max -90.0) min 90.0);
    };
};
