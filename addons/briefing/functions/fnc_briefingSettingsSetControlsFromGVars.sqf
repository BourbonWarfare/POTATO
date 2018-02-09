/*
 * Author: AACO
 * Function used to read the stored briefing settings from GVARs and display them to the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the briefing component <CONTROL>
 *
 * Examples:
 * [_ctrlGroup] call potato_briefing_fnc_briefingSettingsSetControlsFromGVars;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

(_ctrlGroup controlsGroupCtrl AUTO_CREDS_SET_IDC) lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(brief_addCredits), true]));
(_ctrlGroup controlsGroupCtrl ORBAT_SET_IDC) lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(brief_addOrbat), true]));
