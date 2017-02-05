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
    _this remoteExecCall [QFUNC(deleteGroup), SERVER_CLIENT_ID];
};

params ["_groupIndex"];

GVAR(activeGroups) deleteAt _groupIndex;
_groupIndex remoteExecCall [QFUNC(deleteGroupClient), GVAR(registeredClients)];
