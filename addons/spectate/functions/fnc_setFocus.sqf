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

params [["_newFocus", objNull, [objNull]]];

if (_newFocus != GVAR(camTarget) && { !isNull _newFocus || { !isNull GVAR(camTarget) } }) then {
    GVAR(camTarget) = _newFocus;

    if (isNull GVAR(camTarget)) then {
        if (GVAR(currentCamIndex) == FREE_CAMERA) then {
            [] call FUNC(resetTarget);
        } else {
            [FREE_CAMERA] call FUNC(ui_changeCamera);
        };
    } else {
        [GVAR(currentCamIndex)] call FUNC(ui_changeCamera);
    };

    GVAR(lastKillFeed) = [-999];
    [] call FUNC(updateListFocus);
    [] call FUNC(updateInfo);
    // ["UpdateControlsHelp"] call DISPLAY;
};
