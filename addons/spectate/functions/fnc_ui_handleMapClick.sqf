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

params ["", "_button", "_x", "_y"];

if (isNull GVAR(mapHighlighted)) then {
    if !(isNull GVAR(camTarget)) then {
        playsound "ReadoutHideClick1";
    };

    private _pos = MAP_DISPLAY ctrlMapScreenToWorld [_x - 0.1, _y - 0.04];
    _pos set [2, (getPosASLVisual GVAR(cam)) select 2];

    GVAR(cam) setPosASL _pos;
} else {
    playsound "ReadoutClick";
};

[GVAR(mapHighlighted)] call FUNC(setFocus);
