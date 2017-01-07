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
#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#define MIN_VIEW_DISTANCE 500
#define MAX_VIEW_DISTANCE 3000

TRACE_1("Params",_this);

// handle map toggle
if (inputAction "ShowMap" > 0 || inputAction "HideMap" > 0) exitWith {
    [] call FUNC(toggleMap);
    true
};

// handle interrupt
if (inputAction "ingamePause" > 0) exitWith {
    if (GVAR(mapOpen)) then {
        [] call FUNC(toggleMap);
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
    removeMissionEventHandler ["Draw3D", GVAR(draw3DEH)];
    GVAR(draw3DEH) = nil;

    OVERLAY closeDisplay 1;
    openCuratorInterface;
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
    GVAR(lastKillFeed) = [-999];
    [] call FUNC(updateInfo);
    true
};

params ["", "_key"];

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

false // default to unhandled
