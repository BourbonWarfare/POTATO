/*
 * Author: AACO
 * Function used to remove a pending unit from the list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the unit in the pending list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_buildAGroupDialogRemove; //unit in the first index
 * [5] call potato_zeusHC_fnc_buildAGroupDialogRemove; //unit in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_index", lbCurSel BUILD_GROUP_TO_ADD_IDC]];

lbDelete [BUILD_GROUP_TO_ADD_IDC, _index];
