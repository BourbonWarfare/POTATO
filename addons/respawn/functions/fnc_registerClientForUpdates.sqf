/*
 * Author: AACO
 * Registers clients for updates, and sends them the current group state
 *
 * Arguments:
 * 0: Client ID to add to registry <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [2] call potato_respawn_fnc_registerClientForUpdates;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(registerClientForUpdates), SERVER_CLIENT_ID];
};

params [["_clientId", 0, [0]]];

// we don't want to do global commands
if (_clientId < 1) exitWith { WARNING_1("Invalid client ID provided",_clientId); };

// register client
GVAR(registeredClients) pushBack _clientId;

// send the current group config to the client
[GVAR(activeGroups)] remoteExecCall [QFUNC(initGroups), _clientId];
