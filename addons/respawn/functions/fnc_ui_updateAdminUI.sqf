/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
//TRACE_1("params",_this);

private _newSpectators = [] call FUNC(getSpectators);

if (_newSpectators isEqualTo GVAR(currentSpectators)) then {
    [] call FUNC(updateSpectators);
} else {
    [_newSpectators] call FUNC(buildSpectators);
};
