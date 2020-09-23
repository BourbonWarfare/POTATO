/*
 * Author: AACO
 * Function used populate the UI, must be spawned
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (isNil QGVAR(groupFactionWhiteList)) then {
    GVAR(groupFactionWhiteList) = ["potato_w","potato_e","potato_i","rhs_faction_msv"];
};
TRACE_1("white list",GVAR(groupFactionWhiteList));

if (isNil QGVAR(buildFactionCache)) then {
    [] call FUNC(buildACache);
    TRACE_1("Cache populated",GVAR(buildFactionCache));
};

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

// setup faction dropdown, and populate possible unit list
{
    private _index = lbAdd [BUILD_GROUP_FACTIONS_IDC, getText (configfile >> "CfgFactionClasses" >> _x >> "displayName")];
    lbSetData [BUILD_GROUP_FACTIONS_IDC, _index, _x];
    lbSetPicture [BUILD_GROUP_FACTIONS_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _x >> "icon")];

    nil
} count GVAR(groupFactionWhiteList);

lbSetCurSel [BUILD_GROUP_FACTIONS_IDC, if (isNil QGVAR(lastGroupFactionIndex)) then { 0 } else { GVAR(lastGroupFactionIndex) }];

if (!isNil QGVAR(lastGroupUnitArray)) then {
    {
        _x params ["_classname", "_displayName", "_icon"];
        private _unitIndex = lbAdd [BUILD_GROUP_TO_ADD_IDC, _displayName];
        lbSetPicture [BUILD_GROUP_TO_ADD_IDC, _unitIndex, _icon];
        lbSetData [BUILD_GROUP_TO_ADD_IDC, _unitIndex, _classname];
        nil
    } count GVAR(lastGroupUnitArray);
};
