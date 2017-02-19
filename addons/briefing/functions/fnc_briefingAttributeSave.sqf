/*
 * Author: AACO
 * Function used to store the briefing from the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the briefing component <CONTROL>
 *
 * Examples:
 * [_ctrlGroup] call potato_briefing_fnc_briefingAttributeSave;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup"];

private _ctrlText = _ctrlGroup controlsGroupCtrl TEXT_IDC;
[ctrlText _ctrlText] call FUNC(convertNewLineToHTML) // avoid saving ctrl characters
