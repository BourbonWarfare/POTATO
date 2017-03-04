/*
 * Author: AACO
 * Function used to handle mouse up events
 * Should only be called from events
 *
 * Arguments:
 * 1: Button index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,0] call potato_spectate_fnc_ui_handleMouseUp;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["", "_button"];

// right click
if (_button == 1) then {
    GVAR(holdingRightMouse) = false;
};
