/*
 * Author: AACO
 * Function used to update camera variables
 * Should only be called from events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_camTick;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("Params",_this);

BEGIN_COUNTER(camTick);
// Calculate delta time
private _currentTime = diag_tickTime;
GVAR(camDeltaTime) = _currentTime - GVAR(camLastTickTime);
GVAR(camLastTickTime) = _currentTime;

// Follow camera update
if (GVAR(currentCamIndex) == THIRD_PERSON || {GVAR(currentCamIndex) == FIRST_PERSON}) then {
    private _focus = if (isNull GVAR(camTarget)) then {
        private _testFocus = allUnits select 0;
        if (isNil "_testFocus") then {
            objNull
        } else {
            _testFocus
        }
    } else {
        GVAR(camTarget)
    };

    if (!isNull _focus && {_focus != GVAR(camTarget)}) then {
        [_focus] call FUNC(setFocus);
    };

    if (!isNull _focus && {GVAR(currentCamIndex) == THIRD_PERSON}) then {
        [_focus] call FUNC(prepareTarget);
    };
};

// Focus get in / out of vehicle state
if (isNull GVAR(camTarget)) then {
    GVAR(targetInVehicle) = false;
} else {
    if (GVAR(hasTarget)) then {
        if (!GVAR(targetInVehicle) && { !isNull objectParent GVAR(camTarget) }) then {
            [GVAR(camTarget)] call FUNC(setTarget);
            GVAR(targetInVehicle) = true;
        };

        if (GVAR(targetInVehicle) && { isNull objectParent GVAR(camTarget) }) then {
            [GVAR(camTarget)] call FUNC(setTarget);
            GVAR(targetInVehicle) = false;
        };
    };
};

// Camera lights
if (count GVAR(camLights) > 1) then {
    (GVAR(camLights) select 1) setPosASL (AGLToASL (screenToWorld getMousePosition));
};
END_COUNTER(camTick);
