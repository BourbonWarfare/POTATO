/*
 * Author: AACO
 * Handles an admin slotting a spectator
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleSlotClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _spectatorIndex = lbCurSel ADMIN_SPEC_LIST_IDC;
private _groupPath = tvCurSel GROUP_TREE_IDC;

if (_spectatorIndex < 0 || count _groupPath != 2) exitWith { LOG("Bad selections when trying to slot"); };

private _spectatorUnit = missionNamespace getVariable [lbData [ADMIN_SPEC_LIST_IDC, _spectatorIndex], objNull];

 if (isNil "_spectatorUnit" || {isNull _spectatorUnit} || {!isPlayer _spectatorUnit}) exitWith { LOG("Bad spectator when trying to slot"); };

[_spectatorUnit, _groupPath, true] call FUNC(slotUnit);
