/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

[_ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC, 0] call FUNC(acreSideControlSideChange);
[_ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC, 0] call FUNC(acreSideControlRadioChange);
[_ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC, 0] call FUNC(acreSideControlChannelChange);
