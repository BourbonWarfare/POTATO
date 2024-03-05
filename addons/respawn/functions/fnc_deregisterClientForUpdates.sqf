/*
 * Author: AACO
 * Removes client from the client registry, so they no longer receive updates
 *
 * Arguments:
 * 0: Client ID to remove from registry <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [2] call potato_respawn_fnc_deregisterClientForUpdates;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(deregisterClientForUpdates), SERVER_CLIENT_ID];
};

params [["_clientId", -999999, [0]]];

// if the client exists in the registry, remove it, otherwise log the error
private _index = GVAR(registeredClients) find _clientId;
if (_index > -1) then {
    GVAR(registeredClients) deleteAt _clientId;
} else {
    WARNING_2("Trying to deregister an unregistered clientID",_clientId,GVAR(registeredClients));
};
