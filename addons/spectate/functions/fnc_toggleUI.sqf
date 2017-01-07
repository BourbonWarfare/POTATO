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
TRACE_1("Params",_this);

GVAR(uiVisible) = !GVAR(uiVisible);

if (GVAR(uiVisible)) then {
    //if (GVAR(showInfo)) then {
    FOCUS_GROUP ctrlSetFade 0;
    CAM_GROUP ctrlSetFade 0;
    TIMER ctrlSetFade 0;
    LIST ctrlSetFade 0.8;

    showChat true;
    playsound "HintCollapse";
} else {
    FOCUS_GROUP ctrlSetFade 1;
    CAM_GROUP ctrlSetFade 1;
    TIMER ctrlSetFade 1;
    LIST ctrlSetFade 1;

    showChat false;
    playsound "HintExpand";
};

FOCUS_GROUP ctrlCommit 0.25;
CAM_GROUP ctrlCommit 0.25;
TIMER ctrlCommit 0.25;
LIST ctrlCommit 0.25;
