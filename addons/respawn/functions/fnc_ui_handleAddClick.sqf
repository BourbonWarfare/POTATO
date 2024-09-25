/*
 * Author: AACO
 * Handles adding a new group to the active groups list
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleAddClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _configIndex = lbCurSel ADMIN_CONFIG_COMBO_IDC;

((lbData [ADMIN_CONFIG_COMBO_IDC, _configIndex]) splitString ";") params [
    "_configData",
    "_colorString"
];

private _colorArray = [];
{
    _colorArray pushBack (parseNumber _x);
} forEach (_colorString splitString ",");

[
    lbData [ADMIN_FACTION_COMBO_IDC, lbCurSel ADMIN_FACTION_COMBO_IDC], // faction classname
    lbData [ADMIN_GROUP_COMBO_IDC, lbCurSel ADMIN_GROUP_COMBO_IDC], // group classname
    _configData, // config classname
    lbText [ADMIN_CONFIG_COMBO_IDC, _configIndex], // config text
    _colorArray, // config color
    lbPicture [ADMIN_CONFIG_COMBO_IDC, _configIndex] // config texture
] call FUNC(addGroup);
