/*
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

(_ctrlGroup controlsGroupCtrl AUTO_CREDS_SET_IDC) lbSetCurSel (parseNumber GVAR(brief_addCredits));
(_ctrlGroup controlsGroupCtrl ORBAT_SET_IDC) lbSetCurSel (parseNumber GVAR(brief_addOrbat));
