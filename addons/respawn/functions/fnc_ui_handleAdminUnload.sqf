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
TRACE_1("params",_this);

[clientOwner] call FUNC(deregisterClientForUpdates);

[GVAR(adminUpdateEH)] call CBA_fnc_removePerFrameHandler;
GVAR(adminUpdateEH) = nil;

// reset spectate state
if !(GVAR(currentSpecChat) isEqualTo GVAR(oldSpecChat)) then {
    [GVAR(oldSpecChat)] call acre_api_fnc_setSpectator;
};
