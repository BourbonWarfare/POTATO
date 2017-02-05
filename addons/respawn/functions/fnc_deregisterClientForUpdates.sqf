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
    WARNING_2("Trying to deregister an unregistered clientID", _clientId, GVAR(registeredClients));
};
