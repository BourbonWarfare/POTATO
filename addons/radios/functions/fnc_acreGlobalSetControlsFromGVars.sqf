/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

(_ctrlGroup controlsGroupCtrl CFG_G_SET_IDC) lbSetCurSel (parseNumber GVAR(enabled));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NAME_IDC) ctrlSetText GVAR(addCommonChannelName);
(_ctrlGroup controlsGroupCtrl CFG_G_RI_IDC) lbSetCurSel (parseNumber GVAR(radioInterference));
(_ctrlGroup controlsGroupCtrl CFG_G_TI_SLIDER_IDC) sliderSetPosition GVAR(terrainInterference);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NUMBER_IDC) lbSetCurSel (GVAR(addCommonChannelNumber) - 1);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_LR_IDC) lbSetCurSel (parseNumber GVAR(addCommonChannelAllLR));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_MR_IDC) lbSetCurSel (parseNumber GVAR(addCommonChannelAllMR));
(_ctrlGroup controlsGroupCtrl CFG_G_OMNI_IDC) lbSetCurSel (parseNumber GVAR(omnidirectionalAntenna));
(_ctrlGroup controlsGroupCtrl CFG_G_TI_EDIT_IDC) ctrlSetText format ["%1 %2", 100 * GVAR(terrainInterference), "%"];
