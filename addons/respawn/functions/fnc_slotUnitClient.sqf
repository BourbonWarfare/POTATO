/*
 * Author: AACO
 * Adds the given spectator into the given path for the group tree
 *
 * Arguments:
 * 0: Spectator to slot <OBJECT>
 * 1: The new slot display name <STRING>
 * 2: Path to place the spectator into <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player, 'Mr Cool Guy', [1,2]] call potato_respawn_fnc_slotUnitClient;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    "_spectator",
    "_displayName",
    "_slotPath"
];

if (isNull _spectator) then {
    ["Empty", ""]
} else {
    [[_spectator] call EFUNC(spectate,getName), [_spectator] call BIS_fnc_objectVar]
} params ["_unitName", "_unitVar"];

tvSetText [GROUP_TREE_IDC, _slotPath, format ["%1 - %2", _displayName, _unitName]];
tvSetTooltip [GROUP_TREE_IDC, _slotPath, _unitName];
tvSetData [GROUP_TREE_IDC, _slotPath, _unitVar];

if !(isNull ADMIN_RESPAWN) then {
    [] call FUNC(ui_updateAdminUI);
};
