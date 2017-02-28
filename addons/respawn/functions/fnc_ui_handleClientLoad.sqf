/*
 * Author: AACO
 * Handles when the client respawn dialog loads
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleClientLoad;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// wait until the dialog is created
waitUntil {dialog};

// register client for updates
[clientOwner] call FUNC(registerClientForUpdates);
