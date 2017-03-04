/*
 * Author: AACO
 * Resets the current respawn configuration
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_resetGroupInfo;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(resetGroupInfo), SERVER_CLIENT_ID];
};

GVAR(activeGroups) = [];
_this remoteExecCall [QFUNC(resetGroupInfoClient), GVAR(registeredClients)];
