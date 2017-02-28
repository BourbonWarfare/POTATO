/*
 * Author: AACO
 * Deletes a group from the master active group array, will trigger client deletions
 *
 * Arguments:
 * 0: Index of the group to delete <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [1] call potato_respawn_fnc_deleteGroup;
 *
 * Public: No
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
