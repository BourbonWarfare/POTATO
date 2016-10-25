/*
 * Author: AACO
 * Function used to store the toolbox attributes from the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the marker component <CONTROL>
 * 1: Control IDC <NUMBER>
 * 2: The selection of values <ARRAY>
 *
 * Examples:
 * [_ctrlGroup. 12412, ['mil_dot_noShadow']] call potato_missionModules_fnc_toolboxAttributeSave;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup", "_idc", "_values"];

_values select (lbCurSel (_ctrlGroup controlsGroupCtrl _idc));
