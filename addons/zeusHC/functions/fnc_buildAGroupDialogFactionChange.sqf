#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_index", lbCurSel BUILD_GROUP_FACTIONS_IDC]];

// clear both list boxes
lbClear BUILD_GROUP_UNITS_IDC;
lbClear BUILD_GROUP_TO_ADD_IDC;

private _factionIndex = (GVAR(buildFactionCache) select 0) find (lbData [BUILD_GROUP_FACTIONS_IDC, _index]);
if (_factionIndex > -1) then {
    private _unitArray = (GVAR(buildFactionCache) select 1) select _factionIndex;
    {
        _x params ["_classname", "_displayName", "_icon"];
        private _unitIndex = lbAdd [BUILD_GROUP_UNITS_IDC, _displayName];
        lbSetPicture [BUILD_GROUP_UNITS_IDC, _unitIndex, getText(configfile >> "CfgVehicleIcons" >> _icon)];
        lbSetData [BUILD_GROUP_UNITS_IDC, _unitIndex, _classname];
        nil
    } count _unitArray;
};
