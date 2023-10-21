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

params ["", "_button"];
TRACE_1("handleMouseDoubleClick",_this);

/* function had never worked, probably not needed?
// left click
if (_button == 0 && {!isNull GVAR(cursorObject)}) then {
    [GVAR(cursorObject)] call FUNC(prepareTarget);
};
*/
