/*
 * Author: AACO
 * Function used to handle key presses
 * Should only be called from events
 *
 * Arguments:
 * 1: Key press <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,54] call potato_spectate_fnc_ui_handleKeyDown;
 *
 * Public: No
 */

#include "script_component.hpp"
#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#define MIN_VIEW_DISTANCE 500
#define MAX_VIEW_DISTANCE 3000

TRACE_1("Params",_this);

// handle map toggle
if (inputAction "minimap" > 0 || {inputAction "minimapToggle" > 0}) exitWith {
    [!GVAR(mapOpen), false] call FUNC(toggleMap);
    true
};

// handle full map toggle
if (inputAction "ShowMap" > 0 || {inputAction "HideMap" > 0}) exitWith {
    [false, !GVAR(fullMapOpen)] call FUNC(toggleMap);
    true
};

// handle interrupt
if (inputAction "ingamePause" > 0) exitWith {
    if (GVAR(mapOpen) || GVAR(fullMapOpen)) then {
        [false, false] call FUNC(toggleMap);
    } else {
        GVAR(cam) camCommand "manual off";
        if (isMultiplayer) then {
            OVERLAY createDisplay MP_PAUSE_CLASS;
        } else {
            OVERLAY createDisplay SP_PAUSE_CLASS;
        };
    };
    true
};

// handle postive change in draw
if (inputAction "zeroingUp" > 0) exitWith {
    setViewDistance ((viewDistance + 250.0) min MAX_VIEW_DISTANCE);
    true
};

// handle negative change in draw
if (inputAction "zeroingDown" > 0) exitWith {
    setViewDistance ((viewDistance - 250.0) max MIN_VIEW_DISTANCE);
    true
};

// handle vision modes
if (inputAction "nightVision" > 0) exitWith {
    [] call FUNC(toggleVisionMode);
    true
};

// if the zeus key is pressed and unit is curator, open zeus interface
if ((inputAction "CuratorInterface") > 0 && {!isNull (getAssignedCuratorLogic player)}) exitWith {
    GVAR(uiVisible) = false;
    GVAR(tagsVisible) = false;
    GVAR(drawProjectiles) = false;
    OVERLAY closeDisplay 1;
    GVAR(cam) camCommand "manual off";
    openCuratorInterface;

    [
        {!isNull curatorCamera},
        {
            curatorCamera setPosASL positionCameraToWorld [0,0,0];
            curatorCamera setDir (getDirVisual GVAR(cam));
        }
    ] call CBA_fnc_waitUntilAndExecute;

    true
};

// handle spectate lights
if (inputAction "headlights" > 0) exitWith {
    if (GVAR(camLightsOn)) then {
        { deleteVehicle _x; } forEach GVAR(camLights);
        GVAR(camLights) = [];
    } else {
        private _cameraLight = "#lightpoint" createvehicleLocal getPosASL GVAR(cam);
        _cameraLight setLightBrightness 2;
        _cameraLight setLightAmbient [1,1,1];
        _cameraLight setLightColor [0,0,0];
        _cameraLight lightAttachObject [GVAR(cam), [0,0,0]];

        private _pointerLight = "#lightpoint" createvehicleLocal getPosASL GVAR(cam);
        _pointerLight setLightBrightness 1;
        _pointerLight setLightAmbient [1,1,1];
        _pointerLight setLightColor [0,0,0];

        GVAR(camLights) = [_cameraLight, _pointerLight];
    };

    GVAR(camLightsOn) = !GVAR(camLightsOn);

    true
};

// handle toggle projectiles
if (inputAction "lockTarget" > 0) exitWith {
    GVAR(drawProjectiles) = !GVAR(drawProjectiles);
    true
};

// handle showing kill tracker
if (inputAction "networkStats" > 0) exitWith {
    GVAR(showInfo) = !GVAR(showInfo);
    [] call FUNC(updateInfo);
    true
};

// handle toggling cam ground speed
if (inputAction "getOver" > 0) exitWith {
    GVAR(surfaceSpeed) = !GVAR(surfaceSpeed);
    GVAR(cam) camCommand (["surfaceSpeed off", "surfaceSpeed on"] select GVAR(surfaceSpeed));
    true
};

// handle showing the compass
if (inputAction "compass" > 0) exitWith {
    COMPASS ctrlShow !(ctrlShown COMPASS);
    true
};

// handle showing the briefing
if (inputAction "tasks" > 0 || {inputAction "diary" > 0}) exitWith {
    [] call FUNC(toggleBriefing);
    true
};

private _key = _this select 1;

// handle perspective changes
if (_key == DIK_SPACE) exitWith {
    [(GVAR(currentCamIndex) + 1) % 3] call FUNC(ui_changeCamera);
    true
};

// handle getting next focus target
if (_key == DIK_RIGHT) exitWith {
    [true] call FUNC(switchFocus);
    true
};

// handle getting previous focus target
if (_key == DIK_LEFT) exitWith {
    [false] call FUNC(switchFocus);
    true
};

// handle toggling the UI
if (_key == DIK_BACKSPACE) exitWith {
    [] call FUNC(toggleUI);
    true
};

// handle toggling the Tags
if (_key == DIK_BACKSLASH) exitWith {
    GVAR(tagsVisible) = !GVAR(tagsVisible);
    true
};

// handle displaying help
if (_key == DIK_F1) exitWith {
    HELP ctrlShow !(ctrlShown HELP);
    true
};

// handle displaying help
if ((_key == DIK_F4) && {_this select 2} && {_this select 3}) exitWith {
    diag_log text format ["[POTATO] - Warning opening old cam sepctator"];
    call FUNC(exit);
    player call bis_fnc_cameraOld;
};

false // default to unhandled
