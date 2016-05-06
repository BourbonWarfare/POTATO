/*
 * Author: AACO
 * Function to pass a remote call to the HC (or server if no HC is available), must be executed on the server
 *
 * Arguments:
 * 0: Parameters for passed through function <ANY>
 * 1: Function to be passed to the HC (or server if no HC is available) <STRING>
 *
 * Return Value:
 * nil if there was an error, otherwise an empty string <ANY>
 *
 * Example:
 * ["test hint", "hint"] call potato_zeusHC_fnc_hcPassthroughServer;
 * [[], "potato_zeusHC_fnc_buildACache"] call potato_zeusHC_fnc_hcPassthroughServer;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_remoteParameters", "_functionToCall"];

_remoteParameters remoteExecCall [_functionToCall, [] call FUNC(getSpawnMachineId)]
