/*
 * Author: AACO
 * Function used to add units from the faction unit list to the pending list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the unit in the faction unit list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the first index
 * [5] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_index", lbCurSel BUILD_GROUP_UNITS_IDC]];

private _newIndex = lbAdd [BUILD_GROUP_TO_ADD_IDC, lbText [BUILD_GROUP_UNITS_IDC, _index]];
lbSetPicture [BUILD_GROUP_TO_ADD_IDC, _newIndex, lbPicture [BUILD_GROUP_UNITS_IDC, _index]];
lbSetData [BUILD_GROUP_TO_ADD_IDC, _newIndex, lbData [BUILD_GROUP_UNITS_IDC, _index]];
