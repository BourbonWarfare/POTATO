/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

(_ctrlGroup controlsGroupCtrl CFG_G_SET_IDC) lbSetCurSel (parseNumber GVAR(enabled));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NAME_IDC) ctrlSetText GVAR(addCommonChannelName);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NUMBER_IDC) lbSetCurSel (GVAR(addCommonChannelNumber) - 1);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_LR_IDC) lbSetCurSel (parseNumber GVAR(addCommonChannelAllLR));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_MR_IDC) lbSetCurSel (parseNumber GVAR(addCommonChannelAllMR));
