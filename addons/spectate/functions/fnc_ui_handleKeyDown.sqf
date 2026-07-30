#define CHECK_CBA_KEYBIND(var) [_key, [_shift, _ctrl, _alt]] in ((["POTATO", QGVAR(var)] call CBA_fnc_getKeybind) select 8)
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
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#define MIN_VIEW_DISTANCE 500
#define MAX_VIEW_DISTANCE 3000

TRACE_1("Params",_this);
params ["_display", "_key", "_shift", "_ctrl", "_alt"];
private _cbaBind = [_key, [_shift, _ctrl, _alt]];

// handle map toggle
if (CHECK_CBA_KEYBIND(miniMap)) exitWith {
    [!GVAR(mapOpen), false] call FUNC(toggleMap);
    false
};

// handle full map toggle
if (CHECK_CBA_KEYBIND(mainMap)) exitWith {
    [false, !GVAR(fullMapOpen)] call FUNC(toggleMap);
    false
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
if (CHECK_CBA_KEYBIND(incViewDist)) exitWith {
    setViewDistance ((viewDistance + 250.0) min MAX_VIEW_DISTANCE);
    false
};

// handle negative change in draw
if (CHECK_CBA_KEYBIND(decViewDist)) exitWith {
    setViewDistance ((viewDistance - 250.0) max MIN_VIEW_DISTANCE);
    false
};

// handle vision modes
if (CHECK_CBA_KEYBIND(cycleVisionMode)) exitWith {
    [] call FUNC(toggleVisionMode);
    false
};

// if the zeus key is pressed and unit is curator, open zeus interface
if ((inputAction "CuratorInterface") > 0 && {!isNull (getAssignedCuratorLogic player)}) exitWith {
    GVAR(uiVisible) = false;
    GVAR(tagsVisible) = TAGS_VISIBLE_MODE_NONE;
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

    false
};

// handle spectate lights
if (CHECK_CBA_KEYBIND(toggleLight)) exitWith {
    if (GVAR(camLightsOn)) then {
        { deleteVehicle _x; } forEach GVAR(camLights);
        GVAR(camLights) = [];
    } else {
        private _cameraLight = "#lightpoint" createVehicleLocal getPosASL GVAR(cam);
        _cameraLight setLightBrightness 2;
        _cameraLight setLightAmbient [1,1,1];
        _cameraLight setLightColor [0,0,0];
        _cameraLight lightAttachObject [GVAR(cam), [0,0,0]];

        private _pointerLight = "#lightpoint" createVehicleLocal ASLToAGL getPosASL GVAR(cam);
        _pointerLight setLightBrightness 1;
        _pointerLight setLightAmbient [1,1,1];
        _pointerLight setLightColor [0,0,0];

        GVAR(camLights) = [_cameraLight, _pointerLight];
    };

    GVAR(camLightsOn) = !GVAR(camLightsOn);

    false
};

// handle toggle projectiles
if (CHECK_CBA_KEYBIND(toggleTraces)) exitWith {
    GVAR(drawProjectiles) = !GVAR(drawProjectiles);
    false
};

// handle showing kill tracker
if (CHECK_CBA_KEYBIND(toggleStats)) exitWith {
    GVAR(showInfo) = !GVAR(showInfo);
    [] call FUNC(updateInfo);
    false
};

// handle toggling cam ground speed
if (CHECK_CBA_KEYBIND(toggleGroundSpeed)) exitWith {
    GVAR(surfaceSpeed) = !GVAR(surfaceSpeed);
    GVAR(cam) camCommand (["surfaceSpeed off", "surfaceSpeed on"] select GVAR(surfaceSpeed));
    false
};

// handle showing the compass
if (inputAction "compass" > 0) exitWith {
    COMPASS ctrlShow !(ctrlShown COMPASS);
    false
};

// handle showing the briefing
if (CHECK_CBA_KEYBIND(toggleBrief)) exitWith {
    [] call FUNC(toggleBriefing);
    false
};

// handle perspective changes
if (_key == DIK_SPACE) exitWith {
    [(GVAR(currentCamIndex) + 1) % 3] call FUNC(ui_changeCamera);
    false
};

// handle getting next focus target
if (_key == DIK_RIGHT) exitWith {
    [true] call FUNC(switchFocus);
    false
};

// handle getting previous focus target
if (_key == DIK_LEFT) exitWith {
    [false] call FUNC(switchFocus);
    false
};

// handle toggling the UI
if (_key == DIK_BACKSPACE) exitWith {
    [] call FUNC(toggleUI);
    false
};

// handle displaying help
if (_key == DIK_F1) exitWith {
    HELP ctrlShow !(ctrlShown HELP);
    private _ctrlText = _display displayCtrl HELP_IDC;
    private _args = [];
    {
        private _entry = ["Potato", _x] call CBA_fnc_getKeybind;
        _args pushBack ((_entry#8#0 ) call CBA_fnc_localizeKey);
    } forEach [
        QGVAR(mainMap),
        QGVAR(miniMap),
        QGVAR(incViewDist),
        QGVAR(decViewDist),
        QGVAR(cycleVisionMode),
        QGVAR(toggleLight),
        QGVAR(toggleTraces),
        QGVAR(toggleStats),
        QGVAR(toggleGroundSpeed),
        QGVAR(toggleBrief),
        QGVAR(cycleGravestones),
        QGVAR(cycleMarks)
    ];
    lmd_tst_var = +_args;
    _ctrlText ctrlSetStructuredText parseText format ([QUOTE(HELP_TEXT_INSERT)] + _args);
    false
};

// handle toggling the Tags
if (CHECK_CBA_KEYBIND(cycleMarks)) exitWith {
    GVAR(tagsVisible) = (GVAR(tagsVisible) + 1) mod TAGS_VISIBLE_MODE_COUNT;
    false
};

// handle displaying help
if ((_key == DIK_F4) && _shift && _ctrl) exitWith {
    diag_log text format ["[POTATO] - Warning opening old cam sepctator"];
    call FUNC(exit);
    player call bis_fnc_cameraOld;
    [true] call acre_api_fnc_setSpectator;
    false
};

if ((_key == DIK_F5) && _shift && _ctrl) exitWith {
    diag_log text format ["[POTATO] - Opening Testing Menu"];
    call EFUNC(missionTesting,displayMenu);
    false
};

if (CHECK_CBA_KEYBIND(cycleGravestones)) exitWith {
    GVAR(drawDeaths) = (GVAR(drawDeaths) + 1) mod DEATH_VISIBLE_MODE_COUNT;
    false
};

false // default to unhandled
