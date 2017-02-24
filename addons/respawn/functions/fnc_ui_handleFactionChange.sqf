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

params ["", "_index"];

private _lookUp = lbData [ADMIN_FACTION_COMBO_IDC, _index];
GVAR(setupFaction) = _lookUp;

lbClear ADMIN_GROUP_COMBO_IDC;

{
    private _index = lbAdd [ADMIN_GROUP_COMBO_IDC, (GVAR(groupsToInfo) getVariable _x) select 0];
    lbSetData [ADMIN_GROUP_COMBO_IDC, _index, _x];
} forEach ((GVAR(factionsToInfo) getVariable _lookUp) select 4);

lbSetCurSel [ADMIN_GROUP_COMBO_IDC, 0];
[ADMIN_GROUP_COMBO, 0] call FUNC(ui_handleGroupChange);
