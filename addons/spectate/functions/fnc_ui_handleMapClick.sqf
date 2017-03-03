/*
 * Author: AACO
 * Function used to handle map clicks
 * Should only be called from events
 *
 * Arguments:
 * 1: Button index <NUMBER>
 * 2: X screen coordinate <NUMBER>
 * 3: Y screen coordinate <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,1,2,3] call potato_spectate_fnc_ui_handleMapClick;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("Params",_this);

params ["", "", "_x", "_y"];

if (isNull GVAR(mapHighlighted)) then {
    if !(isNull GVAR(camTarget)) then {
        playsound "ReadoutHideClick1";
    };

    private _pos = MAP_DISPLAY ctrlMapScreenToWorld [_x, _y];
    _pos set [2, (getPosASLVisual GVAR(cam)) select 2];

    GVAR(cam) setPosASL _pos;
} else {
    playsound "ReadoutClick";
};

[GVAR(mapHighlighted)] call FUNC(setFocus);
