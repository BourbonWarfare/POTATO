/*
 * Author: AACO
 * Function used to read the stored briefing and display them to the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the briefing component <CONTROL>
 * 1: The stored briefing <STRING>
 *
 * Examples:
 * [_ctrlGroup, "briefing"] call potato_briefing_fnc_briefingAttributeLoad;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup",["_briefing", "", [""]]];

private _ctrlText = _ctrlGroup controlsGroupCtrl TEXT_IDC;
_ctrlText ctrlSetText ([_briefing] call FUNC(convertHTMLToNewLine));
