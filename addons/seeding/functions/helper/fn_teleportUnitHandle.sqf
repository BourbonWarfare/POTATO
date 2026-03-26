#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles the map click event to teleport unit to a designated
* area. It will not teleport a unit if the time window to teleport has elapsed.
* In addition, if the click is not within an allowed zone, it will not function.
*
* Arguments:
* MapSingleClick EH Arguments
*
* Return:
* none
*
* Example:
* [[], [0, 1, 0]] call bw_fnc_teleportUnitHandle;
*//***************************************************************************/
params ["", "_pos"];

if (ace_player getVariable [QGVAR(mapClickWindow), -1] < CBA_missionTime) exitWith {
    removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
    GVAR(safeStartTPClickEH) = -1;
};

_pos set [2, 0];
private _nearObjects = _pos nearObjects [BW_TP_FLAG_TYPE, 250];

if (_nearObjects isEqualTo []) exitWith {
    hint "Please click near a teleport point.";
};
_pos = getPosATL (_nearObjects#0);
_pos set [2, 0];
[ace_player, [_pos, [], 15, "NONE"]] remoteExecCall ["setVehiclePosition", ace_player];

openMap [false, false];
removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
GVAR(safeStartTPClickEH) = -1;
