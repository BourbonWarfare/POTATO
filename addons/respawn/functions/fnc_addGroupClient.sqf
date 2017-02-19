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
    "_factionData",
    "_factionDisplayName",
    "_groupData",
    "_groupDisplayName",
    "_configData",
    "_configText",
    "_configColor",
    "_configTexture",
    "_newUnits"
];

private _groupIndex = tvAdd [GROUP_TREE_IDC, [], format ["%1 (%2)", _configText, _groupDisplayName]];
tvSetPicture [GROUP_TREE_IDC, [_groupIndex], _configTexture];
tvSetPictureColor [GROUP_TREE_IDC, [_groupIndex], _configColor];
tvExpand [GROUP_TREE_IDC, [_groupIndex]];

{
    _x params [
        "_unitData",
        "_unitDisplayName",
        "_unitType",
        "_unit"
    ];

    if (isNull _unit) then {
        ["Empty", ""]
    } else {
        [[_unit] call EFUNC(spectate,getName), [_unit] call BIS_fnc_objectVar]
    } params ["_unitName", "_unitVar"];

    private _unitIndex = tvAdd [GROUP_TREE_IDC, [_groupIndex], format ["%1 - %2", _unitDisplayName, _unitName]];
    tvSetPicture [GROUP_TREE_IDC, [_groupIndex, _unitIndex], [_unitType] call EFUNC(spectate,getVehicleIcon)];
    tvSetTooltip [GROUP_TREE_IDC, [_groupIndex, _unitIndex], _unitName];
    tvSetData [GROUP_TREE_IDC, [_groupIndex, _unitIndex], _unitVar];
} forEach _newUnits;
