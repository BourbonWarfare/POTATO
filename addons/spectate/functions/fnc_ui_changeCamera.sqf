/*
 * Author: AACO
 * Function used to select the camera mode
 *
 * Arguments:
 * 0: Index of the camera selection <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [0] call potato_spectate_fnc_ui_changeCamera;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_index"];

TRACE_2("",GVAR(currentCamIndex),_index);

if (!isNull GVAR(camTarget) || _index == FREE_CAMERA) then {
    if (_index == FIRST_PERSON) exitWith {
        GVAR(cam) cameraEffect ["Terminate", "BACK"];
        GVAR(camTarget) switchCamera "INTERNAL";

        // Reset vision mode
        camUseNVG false;
        false setCamUseTI 0;
        GVAR(visionModeIndex) = 0;

        [] call FUNC(resetTarget);

        // Disable camera input
        GVAR(cam) camCommand "manual off";

        // Update UI
        CAM_FIRST ctrlSetText CAM_ICON_FIRST_SELECTED;
        CAM_THIRD ctrlSetText CAM_ICON_THIRD;
        CAM_FREE ctrlSetText CAM_ICON_FREE;

        // Update HUD
        showHUD [true, false, false, false, false, false, false, true];
        cameraEffectEnableHUD true;
        GVAR(currentCamIndex) = _index;
    };

    if (_index == THIRD_PERSON) exitWith {
        GVAR(cam) cameraEffect ["Internal", "BACK"];
        GVAR(camTarget) switchCamera "EXTERNAL";

        [] call FUNC(resetTarget);

        // Disable camera input
        GVAR(cam) camCommand "manual off";

        // Update UI
        CAM_FIRST ctrlSetText CAM_ICON_FIRST;
        CAM_THIRD ctrlSetText CAM_ICON_THIRD_SELECTED;
        CAM_FREE ctrlSetText CAM_ICON_FREE;

        // Update HUD
        showHUD [true, true, true, true, true, true, true, true];
        cameraEffectEnableHUD true;
        GVAR(currentCamIndex) = _index;
    };

    if (_index == FREE_CAMERA) exitWith {
        GVAR(cam) cameraEffect ["Internal", "BACK"];
        player switchCamera "INTERNAL";
        GVAR(cam) setDir getDirVisual GVAR(cam);

        if (!isNull GVAR(camTarget)) then {
            if (GVAR(currentCamIndex) == FIRST_PERSON) then {
                [GVAR(camTarget)] call FUNC(prepareTarget);
            };
            [GVAR(camTarget)] call FUNC(setTarget);
        };

        // Enable camera input
        if !(GVAR(mapOpen) || GVAR(fullMapOpen)) then {
            GVAR(cam) camCommand "manual on";
        };

        // Update UI
        CAM_FIRST ctrlSetText CAM_ICON_FIRST;
        CAM_THIRD ctrlSetText CAM_ICON_THIRD;
        CAM_FREE ctrlSetText CAM_ICON_FREE_SELECTED;

        // Update HUD
        showHUD [true, true, true, true, true, true, true, true];
        cameraEffectEnableHUD true;
        GVAR(currentCamIndex) = _index;
    };
};
