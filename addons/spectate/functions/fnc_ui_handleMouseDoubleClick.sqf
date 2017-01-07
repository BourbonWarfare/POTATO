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

params ["", "_button"];

// left click
if (_key == 0 && {!(isNull _cursorObject)}) then {
    [GVAR(cursorObject)] call FUNC(prepareTarget);
};
