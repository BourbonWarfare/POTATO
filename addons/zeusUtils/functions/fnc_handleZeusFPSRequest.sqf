#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handle the "ZeusFPSMonitorUpdate" event sent by zeuses
 * requesting to be provided player frame rates for monitoring.
 *
 * Arguments:
 * 0: The Zeus's machine network ID (SCALAR)
 * 1: Whether a client wants to recieve FPS data (BOOL)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [clientOwner, true] call potato_zeusUtils_fnc_handleZeusFPSRequest;
 *
 * Public: No
 */

 if !(isServer) exitWith {};
 params [
    ["_clientOwner", -1, [123]],
    ["_shouldRecieveData", false, [false]]];

if (_clientOwner < 0) exitWith {};

if (_shouldRecieveData) then {
    GVAR(clientsTrackingFPS) pushBackUnique _clientOwner;
} else {
   GVAR(clientsTrackingFPS) = GVAR(clientsTrackingFPS) - [_clientOwner];
};
