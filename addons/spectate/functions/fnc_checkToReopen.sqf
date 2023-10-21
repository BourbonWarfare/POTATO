#include "script_component.hpp"
/*
 * Author: AACO
 * Function used to reopen the spectate UI after another UI closes
 * Should only be called by events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_checkToReopen;
 *
 * Public: No
 */

TRACE_1("checkToReopen",_this);

if (GVAR(running) && {isNull (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", objNull])}) then {
    GVAR(uiVisible) = true;
    GVAR(tagsVisible) = true;
    GVAR(needToAddBriefings) = true;

    // create spectator display
    MAIN_DISPLAY createDisplay QGVAR(overlay);

    // hide elements
    COMPASS ctrlShow false;
    MAP_DISPLAY ctrlShow false;
    MAP_GROUP ctrlShow false;
    FULL_MAP ctrlShow false;
    BRIEFING_GROUP ctrlShow false;
    FOCUS_GROUP ctrlShow GVAR(showInfo);
    HELP ctrlShow false;

    // set init state for respawn
    [GVAR(respawnOpen)] call FUNC(setRespawn);

    // force element refresh
    GVAR(curList) = [];
    [] call FUNC(updateInfo);
    [] call FUNC(updateList);
    [GVAR(currentCamIndex)] call FUNC(ui_changeCamera);

    // add ACRE passthrough to display
    [OVERLAY] call FUNC(acreSpectateCompat);
};
