/*
 * Author: AACO
 * Updates the current spectators with their current death timers
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_updateSpectators;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// assume the array is properly ordered
{
    // belts/suspenders
    if (!isNil "_x" && {!isNull _x} && {alive _x}) then {
        private _elapsedTime = CBA_missionTime - (_x getVariable [QEGVAR(spectate,timeOfDeath), CBA_missionTime]);
        lbSetTooltip [ADMIN_SPEC_LIST_IDC, _forEachIndex, format ["Dead for: %1m %2s", floor (_elapsedTime / 60), floor (_elapsedTime % 60)]];
        lbSetValue [ADMIN_SPEC_LIST_IDC, _forEachIndex, _elapsedTime];
    };
} forEach GVAR(currentSpectators);
