/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _ctrlRI = _this controlsGroupCtrl CFG_G_RI_IDC;
private _ctrlSet = _this controlsGroupCtrl CFG_G_SET_IDC;
private _ctrlOmni = _this controlsGroupCtrl CFG_G_OMNI_IDC;

GVAR(enabled) = (lbCurSel (_this controlsGroupCtrl CFG_G_SET_IDC) == 1);
GVAR(radioInterference) = (lbCurSel (_this controlsGroupCtrl CFG_G_RI_IDC) == 1);
GVAR(omnidirectionalAntenna) = (lbCurSel (_this controlsGroupCtrl CFG_G_OMNI_IDC) == 1);
GVAR(addCommonChannelName) = (ctrlText (_this controlsGroupCtrl CFG_G_CC_NAME_IDC));
GVAR(addCommonChannelNumber) = ((lbCurSel (_this controlsGroupCtrl CFG_G_CC_NUMBER_IDC)) + 1);
GVAR(addCommonChannelAllMR) = (lbCurSel (_this controlsGroupCtrl CFG_G_CC_MR_IDC) == 1);
GVAR(addCommonChannelAllLR) = (lbCurSel (_this controlsGroupCtrl CFG_G_CC_LR_IDC) == 1);

format [
    "%1,%2,%3,%4,%5,%6,%7,%8",
    GVAR(enabled),
    GVAR(radioInterference),
    GVAR(omnidirectionalAntenna),
    GVAR(terrainInterference),
    GVAR(addCommonChannelName),
    GVAR(addCommonChannelNumber),
    GVAR(addCommonChannelAllMR),
    GVAR(addCommonChannelAllLR)
];
