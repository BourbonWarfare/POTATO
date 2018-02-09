/*
 * Author: AACO
 * Function used to store the briefing settings from the specified component
 * Should only be called from 3DEN
 *
 * Arguments:
 * 0: Control group of the briefing component <CONTROL>
 *
 * Examples:
 * [_ctrlGroup] call potato_briefing_fnc_briefingSettingsAttributeSave;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

GVAR(brief_addCredits) = [lbCurSel (_this controlsGroupCtrl AUTO_CREDS_SET_IDC)] call CFUNC(parseBool);
GVAR(brief_addOrbat) = [lbCurSel (_this controlsGroupCtrl ORBAT_SET_IDC)] call CFUNC(parseBool);

format [
    "%1,%2",
    GVAR(brief_addCredits),
    GVAR(brief_addOrbat)
];
