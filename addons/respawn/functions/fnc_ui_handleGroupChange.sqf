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

private _lookUp = lbData [ADMIN_GROUP_COMBO_IDC, _index];

lbClear ADMIN_CONFIG_COMBO_IDC;

{
    _x params [
        "_markerText",
        "_markerColor",
        "_markerTexture"
    ];
    private _index = lbAdd [ADMIN_CONFIG_COMBO_IDC, _markerText];
    lbSetPicture [ADMIN_CONFIG_COMBO_IDC, _index, _markerTexture];
    lbSetPictureColor [ADMIN_CONFIG_COMBO_IDC, _index, _markerColor]
} forEach ((GVAR(groupsToInfo) getVariable _lookUp) select 2);
