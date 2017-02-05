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

if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(changeRespawnState), SERVER_CLIENT_ID];
};

params [["_open", false, [false]]];

// Note: using non-unique JIP-id, so we only execute the latest update for JIPs
[QGVAR(respawnStateChanged), [_open], QGVAR(respawnStateChangedJIPID)] call CBA_fnc_globalEventJIP;
