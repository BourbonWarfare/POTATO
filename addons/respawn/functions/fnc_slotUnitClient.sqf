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

tvSetText [GROUP_TREE_IDC, _slotPath, format ["%1 - %2", _displayName, _unitName]]
tvSetTooltip [GROUP_TREE_IDC, _slotPath, _unitName];
tvSetTooltip [GROUP_TREE_IDC, _slotPath, _unitName]; // hack, one invocation literary doesn't work for some stupid fucking reason
tvSetData [GROUP_TREE_IDC, _slotPath, _unitVar];

if !(isNull ADMIN_RESPAWN) then {
    [] call FUNC(ui_updateAdminUI);
};
