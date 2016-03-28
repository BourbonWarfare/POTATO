#include "script_component.hpp"

params [["_index", lbCurSel BUILD_GROUP_FACTIONS_IDC]];
TRACE_1("params",_index);

// clear both list boxes
lbClear BUILD_GROUP_UNITS_IDC;
lbClear BUILD_GROUP_TO_ADD_IDC;

private _faction = lbData [BUILD_GROUP_FACTIONS_IDC, _index];

// todo: get array of soldiers of a certain faction, and cachem
private _unitArray = [];

{
    private _unitIndex = lbAdd [BUILD_GROUP_UNITS_IDC, _x]; // cfg lookup for readable name?
    lbSetPicture [BUILD_GROUP_UNITS_IDC, _unitIndex, "_x"]; // cfg lookup for picture?
    lbSetData [BUILD_GROUP_UNITS_IDC, _unitIndex, _x];
} count _unitArray;
