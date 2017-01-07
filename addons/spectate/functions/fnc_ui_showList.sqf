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

params ["_showList"];

if (GVAR(uiVisible)) then {
    if (_showList) then {
        LIST ctrlSetBackgroundColor [0,0,0,0.75];
        LIST ctrlSetFade 0.0;
        ctrlSetFocus LIST;
        GVAR(cam) camCommand "manual off";
        showChat false;
    } else {
        LIST ctrlSetBackgroundColor [0,0,0,0];
        LIST ctrlSetFade 0.8;
        ctrlSetFocus MOUSE;
        if (GVAR(currentCamIndex) == FREE_CAMERA) then {
            GVAR(cam) camCommand "manual on";
        };
        showChat true;
    };

    LIST ctrlCommit 0.2;
};
