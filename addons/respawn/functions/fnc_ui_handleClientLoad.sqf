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

// wait until the dialog is created
waitUntil {dialog};

// register client for updates
[clientOwner] call FUNC(registerClientForUpdates);
