#include "..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles the map click event to teleport vehicles forward during
* safe start. It will not teleport a unit if safe start is not on or the time
* window to teleport has elapsed. In addition, if the click is not within an
* allowed zone, it will not function.
*
* Arguments:
* MapSingleClick EH Arguments
*
* Return:
* none
*
* Example:
* [[], [0, 1, 0]] call potato_missionModules_teleportVehicleHandle;
******************************************************************************/
params ["", "_pos"];
private _vehicle = vehicle ace_player;
TRACE_2("TP group",_vehicle,_pos);
if (!EGVAR(safeStart,safeStartEnabled) ||
    _vehicle getVariable [QGVAR(mapClickWindow), -1] < CBA_missionTime ||
    !isNil QGVAR(safeStartTPClickEH) && {GVAR(safeStartTPClickEH) < 0 }) exitWith {
    TRACE_4("exit early",EGVAR(safeStart,safeStartEnabled),_vehicle getVariable [ARR_2(QGVAR(mapClickWindow),-1)],CBA_missionTime,GVAR(safeStartTPClickEH));
    removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
    GVAR(safeStartTPClickEH) = -1;
};
_pos set [2, 0];
private _inZone = [false, true] select (GVAR(ssTPZones) isEqualTo []);
{
    if (_pos inArea _x) exitWith {
        _inZone = true;
    };
} forEach GVAR(ssTPZones);
if !(_inZone) exitWith {
    hint "Please click within a shaded zone.";
};
{
    _x setMarkerAlphaLocal SAFESTART_MARKER_ALPHA;
} forEach GVAR(ssTPZones);
[_vehicle, [_pos, [], 0, "NONE"]] remoteExec ["setVehiclePosition", _vehicle];
openMap [false, false];
removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
GVAR(safeStartTPClickEH) = -1;
