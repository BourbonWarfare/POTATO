#include "..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles the map click event to teleport a unit during
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
* [[], [0, 1, 0]] call potato_missionModules_fnc_teleportUnitHandle;
******************************************************************************/
params ["", "_pos"];
private _unit = ace_player;
TRACE_2("TP unit",_unit,_pos);
if (!EGVAR(safeStart,safeStartEnabled) ||
    !isNull objectParent _unit ||
    _unit getVariable [QGVAR(mapClickWindow), -1] < CBA_missionTime ||
    !isNil QGVAR(safeStartTPClickEH) && {GVAR(safeStartTPClickEH) < 0 }) exitWith {
    TRACE_5("exit early",EGVAR(safeStart,safeStartEnabled),objectParent _unit,_unit getVariable [ARR_2(QGVAR(mapClickWindow),-1)],CBA_missionTime,GVAR(safeStartTPClickEH));
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
_unit setVehiclePosition [_pos, [], 0, "NONE"];
openMap [false, false];
removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
GVAR(safeStartTPClickEH) = -1;
