/*
 * Author: AACO
 * Function used to cycle through the vision modes
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_toggleVisionMode;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// We do not allow switching vision mode when in first person camera
if (GVAR(currentCamIndex) != FIRST_PERSON) then {
    GVAR(visionModeIndex) = (GVAR(visionModeIndex) + 1) % 5;

    if (GVAR(visionModeIndex) == 0) exitWith { // normal vision
         camUseNVG false;
         false setCamUseTi 0;
         playSound "RscDisplayCurator_visionMode";
    };
    if (GVAR(visionModeIndex) == 1) exitWith { // night vision
         camUseNVG true;
         false setCamUseTi 0;
         playSound "RscDisplayCurator_visionMode";
    };
    if (GVAR(visionModeIndex) == 2) exitWith { // white hot
         camUseNVG false;
         true setCamUseTi 0;
         playSound "RscDisplayCurator_visionMode";
    };
    if (GVAR(visionModeIndex) == 3) exitWith { // black hot
         camUseNVG false;
         true setCamUseTi 1;
         playSound "RscDisplayCurator_visionMode";
    };
    if (GVAR(visionModeIndex) == 4) exitWith { // super thermals
         camUseNVG false;
         true setCamUseTi 7;
         playSound "RscDisplayCurator_visionMode";
    };
};
