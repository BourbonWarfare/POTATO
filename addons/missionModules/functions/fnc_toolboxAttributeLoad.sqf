/*
 * Author: AACO
 * Function used to read the stored toolbox attributes and display them to the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the marker component <CONTROL>
 * 1: Control IDC <NUMBER>
 * 2: The stored icon <STRING>
 * 3: The selection of values <ARRAY>
 *
 * Examples:
 * [_ctrlGroup, 65431, "mil_dot_noShadow", ["mil_dot_noShadow"]] call potato_missionModules_fnc_toolboxAttributeLoad;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup", "_idc", "_value", "_values"];

(_ctrlGroup controlsGroupCtrl _idc) lbSetCurSel (_values find _value);
