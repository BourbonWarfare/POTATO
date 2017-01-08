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

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(running)) then {
    GVAR(uiVisible) = true;
    // create spectator display
    MAIN_DISPLAY createDisplay QGVAR(overlay);

    // hide elements
    MAP_GROUP ctrlShow false;
    FOCUS_GROUP ctrlShow GVAR(showInfo);

    // force element refresh
    GVAR(curList) = [];
    GVAR(lastKillFeed) = [-999];
    [] call FUNC(updateInfo);
    [] call FUNC(updateList);
    [GVAR(currentCamIndex)] call FUNC(ui_changeCamera);
};
