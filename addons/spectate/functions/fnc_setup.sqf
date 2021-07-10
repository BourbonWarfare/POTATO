#define DEBUG_MODE_FULL
#include "script_component.hpp"
/*
 * Author: AACO
 * Function used to start the spectate script
 * Should only be called from respawn init
 *
 * Arguments:
 * 0: Old unit <OBJECT>
 * 1: New unit <OBJECT>
 * 2: Respawn type https://community.bistudio.com/wiki/Arma_3_Respawn#Respawn_Types <NUMBER>
 * 3: Respawn delay <NUMBER>
 *
 * Examples:
 * [] call potato_spectate_fnc_setup;
 *
 * Public: No
 */

params [
    ["_newUnit", objNull, [objNull]],
    ["_oldUnit", objNull, [objNull]],
    ["_respawnType", 1, [0]],
    ["_respawnDelay", 0, [0]]
];
TRACE_4("setup",_newUnit,_oldUnit,_respawnType,_respawnDelay);

// start spectate
GVAR(running) = true;

// create spectator display
MAIN_DISPLAY createDisplay QGVAR(overlay);

// add ACRE passthrough to display
[OVERLAY] call FUNC(acreSpectateCompat);

// hide elements
COMPASS ctrlShow false;
MAP_DISPLAY ctrlShow false;
MAP_GROUP ctrlShow false;
FOCUS_GROUP ctrlShow false;
FULL_MAP ctrlShow false;
BRIEFING_GROUP ctrlShow false;
HELP ctrlShow false;

// set init state for respawn
[GVAR(respawnOpen)] call FUNC(setRespawn);

// create spectator unit
private _tempGroup = createGroup [sideLogic, true]; // explicitly mark for cleanup (even though we delete below)
GVAR(unit) = _tempGroup createUnit [QGVAR(spectator), ZERO_POS, [], 100, "NONE"];
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

[GVAR(unit), _oldUnit] remoteExecCall [QFUNC(prepareSpectator), 0, true];

// set name on old unit / check for zeus to transfer
if !(isNull _oldUnit) then {
    GVAR(unit) setPos (getPos _oldUnit);
    _oldUnit setVariable [QGVAR(deadName), profileName, true];

    // if the old unit had a curator, assign it to the new unit
    private _zeusModule = getAssignedCuratorLogic _oldUnit;
    if !(isNull _zeusModule) then {
        [GVAR(unit), _zeusModule] remoteExec [QFUNC(transferZeus), SERVER_CLIENT_ID];
        if(EGVAR(missionTesting,missionTestingActive)) then {[] call EFUNC(missionTesting,displayMenu);};
    };
};

// disable post process effects
BIS_fnc_feedback_allowPP = false;

// if new unit is a seagul, delete it
if (_newUnit isKindOf "seagull" || _newUnit isKindOf QGVAR(spectator) || _newUnit isKindOf QGVAR(playableSpectator)) then {
    deleteVehicle _newUnit;
};

// reset spectator unit name
GVAR(unit) setVariable [QGVAR(cachedName), "", true];

// set ACRE spectator
[true] call acre_api_fnc_setSpectator;

// add and set spectate chat channel
private _spectateChannel = missionNamespace getVariable QGVAR(channel);
_spectateChannel radioChannelAdd [GVAR(unit)];
setCurrentChannel (DIRECT_CHANNEL_INDEX + _spectateChannel);

// disable other chats
[false] call FUNC(setChannels);

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
GVAR(surfaceSpeed) = false;
GVAR(camTarget) = _oldUnit;
GVAR(targetInVehicle) = (vehicle GVAR(camTarget) != GVAR(camTarget));
GVAR(dummy) = "Logic" createVehicleLocal getPosASLVisual GVAR(camTarget);

GVAR(cam) = "camcurator" camCreate eyePos GVAR(camTarget);
GVAR(cam) cameraEffect ["internal", "back"];
GVAR(cam) setPosASL eyePos GVAR(camTarget);
GVAR(cam) setDir getDirVisual GVAR(camTarget);
GVAR(cam) camCommand "maxPitch 89.0";
GVAR(cam) camCommand "minPitch -89.0";
GVAR(cam) camCommand "speedDefault 1.1";
GVAR(cam) camCommand "speedMax 2.4";
GVAR(cam) camCommand "ceilingHeight 5000";
GVAR(cam) camCommand "atl off";
GVAR(cam) camCommand "surfaceSpeed off";
cameraEffectEnableHUD true;

// initilize projectile tracking
GVAR(grenades) = [];
GVAR(projectiles) = [];
GVAR(drawProjectiles) = false;

// init misc GVARS
GVAR(curList) = [];
GVAR(mapOpen) = false;
GVAR(fullMapOpen) = false;
GVAR(needToAddBriefings) = true;
GVAR(uiVisible) = true;
GVAR(oldViewDistance) = viewDistance;
GVAR(mapHighlighted) = objNull;
GVAR(tagsVisible) = true;
GVAR(cursorObject) = objNull;
GVAR(holdingRightMouse) = false;

// Start ticking
GVAR(thingsToDraw) = [];
GVAR(showInfo) = false;
GVAR(thingsToDrawEH) = [LINKFUNC(ui_updateThingsToDraw), 0.2] call CBA_fnc_addPerFrameHandler;
GVAR(straggleUpdateEH) = [LINKFUNC(ui_straggleUpdate), 5] call CBA_fnc_addPerFrameHandler;
GVAR(camTick) = addMissionEventHandler ["EachFrame", {call FUNC(camTick)}];
GVAR(draw3DEH) = addMissionEventHandler ["Draw3D", {call FUNC(ui_handleDraw3D)}];

// add event handlers to all active units
[] call FUNC(setEventsOnActiveUnits);

// register advanced throwing EH
GVAR(advancedThrowingEH) = [QACEGVAR(advanced_throwing,throwFiredXEH), FUNC(handleFired)] call CBA_fnc_addEventHandler;
