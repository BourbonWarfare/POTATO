/*
 * Author: AACO
 * Function to pass a remote call to a HC (or server if no HC is available)
 *
 * Arguments:
 * 0: Parameters for passed through function <ANY>
 * 1: Function to be passed to the HC (or server if no HC is available) <STRING>
 * 2: Should this function exit if not called on server? (optional, default false) <BOOL>
 *
 * Return Value:
 * nil if there was an error, otherwise an empty string <ANY>
 *
 * Examples:
 * ["test hint", "hint"] call potato_zeusHC_fnc_hcPassthrough;
 * [[], "potato_zeusHC_fnc_buildACache"] call potato_zeusHC_fnc_hcPassthrough;
 * [[], "potato_zeusHC_fnc_buildACache",true] call potato_zeusHC_fnc_hcPassthrough;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_remoteParameters", "_functionToCall", ["_exitIfNotServer", false, [false]]];

if (isServer) exitWith {
    _remoteParameters remoteExec [_functionToCall, [] call FUNC(getSpawnMachineId)]
};

if (_exitIfNotServer) exitWith {
    ERROR("_exitIfNotServer is true, but not executed on the server");
    nil
};

[_remoteParameters, _functionToCall, true] remoteExecCall [QFUNC(hcPassthroughSpawn), SERVER_CLIENT_ID]
