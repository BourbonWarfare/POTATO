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
#define FOLLOW_CAMERA_MAX_DISTANCE 5.0
TRACE_1("Params",_this);

if (GVAR(currentCamIndex) == THIRD_PERSON) then {
    if ((_this select 1) > 0) then {
        GVAR(thirdPersonCamZoom) = (GVAR(thirdPersonCamZoom) - 1.0) max 0.0;
    } else {
        GVAR(thirdPersonCamZoom) = (GVAR(thirdPersonCamZoom) + 1.0) min FOLLOW_CAMERA_MAX_DISTANCE;
    };
};
