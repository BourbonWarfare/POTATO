/*
 * Author: AACO
 * Change the respawn state to either open or closed
 *
 * Arguments:
 * 0: Is respawn open <BOOL>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [true] call potato_respawn_fnc_changeRespawnState;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(changeRespawnState), SERVER_CLIENT_ID];
};

params [["_open", false, [false]]];

// Note: using non-unique JIP-id, so we only execute the latest update for JIPs
[QGVAR(respawnStateChanged), [_open], QGVAR(respawnStateChangedJIPID)] call CBA_fnc_globalEventJIP;
