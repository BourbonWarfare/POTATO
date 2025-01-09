/*
 * Author: AACO
 * Client function called when the server updates the underlying group
 *
 * Arguments:
 * 0: Faction data lookup <STRING>
 * 1: Faction display name <STRING>
 * 2: Group data lookup <STRING>
 * 3: Group display name <STRING>
 * 4: Config data lookup <STRING>
 * 5: Config marker text <STRING>
 * 6: Config marker color <ARRAY>
 * 7: Config marker texture <STRING>
 * 8: Units to add <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [
 *     'blu_f', 'NATO',
 *     'PlatoonLead', 'Platoon Lead',
 *     'OnePlt', '1Plt', [1,1,1,1], '/A3/path/texture.paa',
 *     ['Unit data lookup', 'Unit displayname', 'unit_classname_f', objNull]
 * ] call potato_respawn_fnc_addGroupClient;
 *
 * Public: No
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
if (_configTexture isNotEqualTo "") then {
    tvSetPicture [GROUP_TREE_IDC, [_groupIndex], _configTexture];
    tvSetPictureColor [GROUP_TREE_IDC, [_groupIndex], _configColor];
};

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
    tvSetPicture [GROUP_TREE_IDC, [_groupIndex, _unitIndex], [_unitType] call ACEFUNC(common,getVehicleIcon)];
    tvSetTooltip [GROUP_TREE_IDC, [_groupIndex, _unitIndex], _unitName];
    tvSetData [GROUP_TREE_IDC, [_groupIndex, _unitIndex], _unitVar];
} forEach _newUnits;
