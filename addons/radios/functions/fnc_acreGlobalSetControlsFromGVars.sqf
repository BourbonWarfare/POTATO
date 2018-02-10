/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

(_ctrlGroup controlsGroupCtrl CFG_G_SET_IDC) lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(enabled), DEFAULT_ENABLED]));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NAME_IDC) ctrlSetText (missionNamespace getVariable [QGVAR(addCommonChannelName), DEFAULT_COMMON_CH_NAME]);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_NUMBER_IDC) lbSetCurSel ((missionNamespace getVariable [QGVAR(addCommonChannelNumber), DEFAULT_COMMON_CH_NUM]) - 1);
(_ctrlGroup controlsGroupCtrl CFG_G_CC_LR_IDC) lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelAllLR), DEFAULT_COMMON_CH_ENABLED]));
(_ctrlGroup controlsGroupCtrl CFG_G_CC_MR_IDC) lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelAllMR), DEFAULT_COMMON_CH_ENABLED]));
