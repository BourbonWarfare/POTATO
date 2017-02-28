/*
 * Author: AACO
 * Function called on the server when the respawn menu module is placed
 * Should only be called from the zeus module workflow
 *
 * Arguments:
 * 0: Logic placed <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [logicObj] call potato_respawn_fnc_openRespawnMenuModule;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if !(isServer) exitWith { ERROR("function not executed on server"); };
if !(EGVAR(spectate,enabled)) exitWith { WARNING("Open respawn menu called, without potato spectator being enabled"); };

params [["_logic", objNull, [objNull]]];

if (isNull _logic) exitWith { ERROR("Null object provided to function"); };

[] remoteExecCall [QFUNC(openRespawnMenuModuleClient), owner _logic];

deleteVehicle _logic;

true
