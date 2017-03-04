/*
 * Author: AACO
 * Function used to handle double clicks
 * Should only be called from events
 *
 * Arguments:
 * 1: Button index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,0] call potato_spectate_fnc_ui_handleMouseDoubleClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["", "_button"];

// left click
if (_key == 0 && {!(isNull _cursorObject)}) then {
    [GVAR(cursorObject)] call FUNC(prepareTarget);
};
