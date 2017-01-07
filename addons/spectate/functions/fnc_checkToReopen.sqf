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

if (GVAR(running)) then {
    MAIN_DISPLAY createDisplay QGVAR(overlay);

    if (isNil QGVAR(draw3DEH)) then {
        GVAR(draw3DEH) = addMissionEventHandler ["Draw3D", FUNC(ui_handleDraw3D)];
    };

    // hide elements
    MAP_GROUP ctrlShow false;
    FOCUS_GROUP ctrlShow GVAR(showInfo);

    GVAR(curList) = []; // force list update

    [GVAR(currentCamIndex)] call FUNC(ui_changeCamera);
};
