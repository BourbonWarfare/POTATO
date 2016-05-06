/*
 * Author: AACO
 * Function to pass a remote call to the server, to later be passed to a HC
 * (or server if no HC is available)
 *
 * Arguments:
 * 0: Parameters for passed through function <ANY>
 * 1: Function to be passed to the HC (or server if no HC is available) <STRING>
 *
 * Return Value:
 * nil if there was an error, otherwise an empty string <ANY>
 *
 * Example:
 * ["test hint", "hint"] call potato_zeusHC_fnc_hcPassthrough;
 * [[], "potato_zeusHC_fnc_buildACache"] call potato_zeusHC_fnc_hcPassthrough;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_remoteParameters", "_functionToCall"];

[_remoteParameters, _functionToCall] remoteExecCall [QFUNC(hcPassthroughServer), SERVER_CLIENT_ID]
