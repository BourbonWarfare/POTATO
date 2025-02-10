#include "..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles the map click event to teleport a leader and their
* group during safe start. It will not teleport a group if safe start is not
* on or the time window to teleport has elapsed. In addition, if the click is
* not within anallowed zone, it will not function.
*
* Arguments:
* MapSingleClick EH Arguments
*
* Return:
* none
*
* Example:
* [[], [0, 1, 0]] call potato_missionModules_teleportGroupHandle;
******************************************************************************/
params ["", "_pos"];
private _group = group ace_player;
TRACE_2("TP group",_group,_pos);
if (!EGVAR(safeStart,safeStartEnabled) ||
    leader ace_player != ace_player ||
    _group getVariable [QGVAR(mapClickWindow), -1] < CBA_missionTime ||
    !isNil QGVAR(safeStartTPClickEH) && {GVAR(safeStartTPClickEH) < 0 }) exitWith {
    TRACE_5("exit early",EGVAR(safeStart,safeStartEnabled),leader ace_player,_group getVariable [ARR_2(QGVAR(mapClickWindow),-1)],CBA_missionTime,GVAR(safeStartTPClickEH));
    systemChat format ["%1 %2 %3 %4",!EGVAR(safeStart,safeStartEnabled), leader ace_player != ace_player,  _group getVariable [QGVAR(mapClickWindow), -1] < CBA_missionTime, !isNil QGVAR(safeStartTPClickEH) || {GVAR(safeStartTPClickEH) < 0 }];
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
{
    [{
        params ["_unit", "_pos"];
        if (isNull objectParent _unit) then {
            [_unit, [_pos, [], 0, "NONE"]] remoteExec ["setVehiclePosition", _unit];
        }
    }, [_x, _pos], 0.05 * _forEachIndex] call CBA_fnc_waitAndExecute;
} forEach units _group;
openMap [false, false];
removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
GVAR(safeStartTPClickEH) = -1;
