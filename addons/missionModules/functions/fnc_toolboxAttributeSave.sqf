/*
 * Author: AACO
 * Function used to store the icon from the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the marker component <CONTROL>
 *
 * Examples:
 * [_ctrlGroup] call potato_missionModules_fnc_iconAttributeSave;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup", "_idc", "_values"];

_values select (lbCurSel (_ctrlGroup controlsGroupCtrl _idc));
