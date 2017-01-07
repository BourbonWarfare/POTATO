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

if (GVAR(uiVisible)) then {
    LIST tvSetCurSel ([[GVAR(camTarget)] call BIS_fnc_objectVar] call FUNC(findPathInList));
};
