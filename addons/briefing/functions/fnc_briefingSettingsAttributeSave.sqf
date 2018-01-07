/*
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

GVAR(brief_addCredits) = [lbCurSel (_this controlsGroupCtrl AUTO_CREDS_SET_IDC)] call CFUNC(parseBool);
GVAR(brief_addOrbat) = [lbCurSel (_this controlsGroupCtrl ORBAT_SET_IDC)] call CFUNC(parseBool);

format [
    "%1,%2",
    GVAR(brief_addCredits),
    GVAR(brief_addOrbat)
];
