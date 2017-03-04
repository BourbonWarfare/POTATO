/*
 * Author: AACO
 * Function used to start the spectate script
 * Should only be called from respawn template onPlayerRespawn
 *
 * Arguments:
 * 0: Old unit <OBJECT>
 * 1: New unit <OBJECT>
 * 2: Respawn type https://community.bistudio.com/wiki/Arma_3_Respawn#Respawn_Types <NUMBER>
 * 3: Respawn delay <NUMBER>
 *
 * Examples:
 * [] call potato_spectate_fnc_init;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL // debug left on for a raisin
#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    ["_newUnit", objNull, [objNull]],
    ["_oldUnit", objNull, [objNull]],
    ["_respawnType", 1, [0]],
    ["_respawnDelay", 3, [0]]
];

// start spectate
GVAR(running) = true;

// add event handlers to all active units
[] call FUNC(setEventsOnActiveUnits);

// check for zeus to transfer
private _zeusModule = getAssignedCuratorLogic _oldUnit;
TRACE_1("Curator", _zeusModule);

// create spectator display
MAIN_DISPLAY createDisplay QGVAR(overlay);

// hide elements
MAP_DISPLAY ctrlShow false;
MAP_GROUP ctrlShow false;
FOCUS_GROUP ctrlShow false;
HELP ctrlShow false;

// set init state for respawn
[GVAR(respawnOpen)] call FUNC(setRespawn);

// hide whatever unit player was spawned into
_newUnit setPos ZERO_POS;
[_newUnit, true] remoteExecCall ["hideObjectGlobal", SERVER_CLIENT_ID];

// create spectator unit
private _tempGroup = createGroup sideLogic;
GVAR(unit) = _tempGroup createUnit [QGVAR(spectator), ZERO_POS, [], 200, "NONE"];
GVAR(unit) setVariable [QEGVAR(radios,assignedLanguages), GVAR(availableLanguages)];
selectPlayer GVAR(unit);

if (isNil QGVAR(group) || {isNull GVAR(group)}) then {
    WARNING("The spectate group has been destroyed, recreating");
    GVAR(group) = _tempGroup;
    publicVariable QGVAR(group);
} else {
    [GVAR(unit)] joinSilent GVAR(group);
    deleteGroup _tempGroup;
};

[GVAR(unit)] remoteExecCall [QFUNC(prepareSpectator), 0, true];

// if the old unit had a curator, assign it to the new unit
if !(isNull _zeusModule) then {
    [GVAR(unit), _zeusModule] remoteExec [QFUNC(transferZeus), SERVER_CLIENT_ID];
};

// disable post process effects
BIS_fnc_feedback_allowPP = false;

// if new unit is a seagul, delete it
if (_newUnit isKindOf "seagull") then {
    deleteVehicle _newUnit;
};

// set name on old unit
if !(isNil "_oldUnit" || {isNull _oldUnit}) then {
    _oldUnit setVariable [QGVAR(deadName), profileName, true];
};

[true] call acre_api_fnc_setSpectator;

showCinemaBorder false;

// initilize camera
GVAR(camLights) = [];
GVAR(camLightsOn) = false;
GVAR(camDeltaTime) = 0.0;
GVAR(visionModeIndex) = 0;
GVAR(currentCamIndex) = FREE_CAMERA;
GVAR(camLastTickTime) = diag_tickTime;

GVAR(thirdPersonCamYaw) = 0.0;
GVAR(thirdPersonCamZoom) = 0.5;
GVAR(thirdPersonCamPitch) = 0.0;
GVAR(thirdPersonCamDirTemp) = 0.0;
GVAR(thirdPersonCamZoomTemp) = 0.0;

GVAR(hasTarget) = true;
GVAR(camTarget) = _oldUnit;
GVAR(targetInVehicle) = (vehicle GVAR(camTarget) != GVAR(camTarget));
GVAR(dummy) = "Land_HelipadEmpty_F" createVehicleLocal getPosASLVisual GVAR(camTarget);

GVAR(cam) = "camcurator" camCreate eyePos GVAR(camTarget);
GVAR(cam) cameraEffect ["internal", "back"];
GVAR(cam) setPosASL eyePos GVAR(camTarget);
GVAR(cam) setDir getDirVisual GVAR(camTarget);
GVAR(cam) camCommand "maxPitch 89.0";
GVAR(cam) camCommand "minPitch -89.0";
GVAR(cam) camCommand "speedDefault 1.25";
GVAR(cam) camCommand "speedMax 2.35";
GVAR(cam) camCommand "ceilingHeight 5000";
GVAR(cam) camCommand "atl off";
GVAR(cam) camCommand "surfaceSpeed on";
cameraEffectEnableHUD true;

// initilize projectile tracking
GVAR(grenades) = [];
GVAR(projectiles) = [];
GVAR(drawProjectiles) = false;

// Start ticking
GVAR(curList) = [];
GVAR(thingsToDraw) = [];
GVAR(showInfo) = false;
GVAR(thingsToDrawEH) = [{_this spawn FUNC(ui_updateThingsToDraw)}, 0.2] call CBA_fnc_addPerFrameHandler;
GVAR(straggleUpdateEH) = [{_this spawn FUNC(ui_straggleUpdate)}, 5] call CBA_fnc_addPerFrameHandler;
GVAR(draw3DEH) = addMissionEventHandler ["Draw3D", {call FUNC(ui_handleDraw3D)}];

// init misc GVARS
GVAR(mapOpen) = false;
GVAR(oldViewDistance) = viewDistance;
GVAR(mapHighlighted) = objNull;
GVAR(uiVisible) = true;
GVAR(cursorObject) = objNull;
GVAR(holdingRightMouse) = false;
