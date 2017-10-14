/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;
[_ctrlBabel] call FUNC(populateBabelList);

// register event handlers
_ctrlBabel ctrlAddEventHandler ["lbSelChanged", {_this spawn FUNC(acreSideControlBabelChange);}];
(_ctrlGroup controlsGroupCtrl CFG_S_CHANNEL_IDC) ctrlAddEventHandler ["keyUp", {_this call FUNC(acreSideControlChannelEditChange);}];
(_ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC) ctrlAddeventHandler ["toolboxSelChanged", {_this call FUNC(acreSideControlSideChange);}];
(_ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC) ctrlAddEventHandler ["lbSelChanged", {_this call FUNC(acreSideControlChannelChange);}];
(_ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC) ctrlAddEventHandler ["toolboxSelChanged", {_this call FUNC(acreSideControlRadioChange);}];
(_ctrlGroup controlsGroupCtrl CFG_S_SHARED_LR) ctrlAddEventHandler ["toolboxSelChanged", {[_this, true] call FUNC(acreSideControlSharedChange);}];
(_ctrlGroup controlsGroupCtrl CFG_S_SHARED_MR) ctrlAddEventHandler ["toolboxSelChanged", {[_this, false] call FUNC(acreSideControlSharedChange);}];

[_ctrlGroup] call FUNC(acreSideSetControlsFromGVars);
