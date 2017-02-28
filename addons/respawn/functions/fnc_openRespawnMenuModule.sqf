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

if !(isServer) exitWith { ERROR("function not executed on server"); };
if !(EGVAR(spectate,enabled)) exitWith { WARNING("Open respawn menu called, without potato spectator being enabled"); };

params [["_logic", objNull, [objNull]]];

if (isNull _logic) exitWith { ERROR("Null object provided to function"); };

[] remoteExecCall [QFUNC(openRespawnMenuModuleClient), owner _logic];

deleteVehicle _logic;

true
