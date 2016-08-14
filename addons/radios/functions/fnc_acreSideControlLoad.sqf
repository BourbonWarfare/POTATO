/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;
private _ctrlChannelEdit = _ctrlGroup controlsGroupCtrl CFG_S_CHANNEL_IDC;
private _ctrlSharedMR = _ctrlGroup controlsGroupCtrl CFG_S_SHARED_MR;
private _ctrlSharedLR = _ctrlGroup controlsGroupCtrl CFG_S_SHARED_LR;

[_ctrlBabel] call FUNC(populateBabelList);

// register event handlers
_ctrlSharedMR ctrlAddEventHandler ["toolboxSelChanged",{[_this, false] call FUNC(acreSideControlSharedChange);}];
_ctrlSharedMR lbSetCurSel 0;

_ctrlSharedLR ctrlAddEventHandler ["toolboxSelChanged",{[_this, true] call FUNC(acreSideControlSharedChange);}];
_ctrlSharedLR lbSetCurSel 0;

_ctrlSide ctrlAddeventHandler ["toolboxSelChanged",{_this call FUNC(acreSideControlSideChange);}];
_ctrlSide lbSetCurSel 0;
[_ctrlSide,0] call FUNC(acreSideControlSideChange);

_ctrlRadio ctrlAddEventHandler ["toolboxSelChanged",{_this call FUNC(acreSideControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(acreSideControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbSelChanged",{_this call FUNC(acreSideControlChannelChange);}];
_ctrlChannels lnbSetCurSelRow 0;
[_ctrlChannels,0] call FUNC(acreSideControlChannelChange);

_ctrlChannelEdit ctrlAddEventHandler ["keyUp",{_this call FUNC(acreSideControlChannelEditChange);}];

_ctrlBabel ctrlAddEventHandler ["lbSelChanged",{_this call FUNC(acreSideControlBabelChange);}];
