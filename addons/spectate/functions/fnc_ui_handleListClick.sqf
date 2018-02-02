/*
 * Author: AACO
 * Function used to handle list clicks
 * Should only be called from events
 *
 * Arguments:
 * 1: List index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,42] call potato_spectate_fnc_ui_handleListClick;
 *
 * Public: No
 */
#define DEBUG_MODE_TRUE
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_isSingleClick"];

private _handled = false;
private _object	= missionNamespace getVariable [LIST tvData (tvCurSel LIST), objNull];


if !(isNull _object) then {
    _object = _object getVariable [QGVAR(oldUnit), _object];

    if (_isSingleClick) then {
        if (_object != GVAR(camTarget)) then {
            [_object] call FUNC(setFocus);
            playsound "ReadoutClick";

            _handled = true;
        };
    } else {
        private _pos = getPosASLVisual _object;
        {
            _pos set [_forEachIndex, _x + 1 + random 10];
        } forEach _pos;
        GVAR(cam) setPosASL _pos;

        [_object] call FUNC(setFocus);
        playsound "ReadoutClick";

        _handled = true;
    };
};

_handled
