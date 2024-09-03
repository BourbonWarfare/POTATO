/*
 * Author: AACO
 * Function used to toggle the UI
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_toggleUI;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

GVAR(uiVisible) = !GVAR(uiVisible);

if (GVAR(uiVisible)) then {
    FOCUS_GROUP ctrlSetFade 0;
    CAM_GROUP ctrlSetFade 0;
    LIST_CTR ctrlSetFade 0.8;
    [GVAR(respawnOpen)] call FUNC(setRespawn);

    showChat true;
    playSound "HintCollapse";
} else {
    FOCUS_GROUP ctrlSetFade 1;
    CAM_GROUP ctrlSetFade 1;
    LIST_CTR ctrlSetFade 1;
    [false] call FUNC(setRespawn);

    showChat false;
    playSound "HintExpand";
};

FOCUS_GROUP ctrlCommit 0.25;
CAM_GROUP ctrlCommit 0.25;
LIST_CTR ctrlCommit 0.25;
