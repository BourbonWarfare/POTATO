/*
 * Author: AACO
 * Handles a looped call to update the UI, mainly to track down spectators
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handle;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _newSpectators = [] call FUNC(getSpectators);

if (_newSpectators isEqualTo GVAR(currentSpectators)) then {
    [] call FUNC(updateSpectators);
} else {
    [_newSpectators] call FUNC(buildSpectators);
};
