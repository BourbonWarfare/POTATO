/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;
private _ctrlChannelEdit = _ctrlGroup controlsGroupCtrl CFG_CHANNEL_IDC;
private _ctrlSharedMR = _ctrlGroup controlsGroupCtrl CFG_SHARED_MR;
private _ctrlSharedLR = _ctrlGroup controlsGroupCtrl CFG_SHARED_LR;

TRACE_2("",_ctrlSharedMR,_ctrlSharedLR);

GVAR(sideChannelArray) = [
    [false,false,false], // west
    [false,false,false], // east
    [false,false,false], // indy
    [false,false,false] // civ
];

[_ctrlBabel] call FUNC(populateBabelList);

// register event handlers
_ctrlSide ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(acreControlSideChange);}];
_ctrlSide lbSetCurSel 0;
[_ctrlSide,0] call FUNC(acreControlSideChange);

_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(acreControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(acreControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(acreControlChannelChange);}];
_ctrlChannels lnbSetCurSelRow 0;
[_ctrlChannels,0] call FUNC(acreControlChannelChange);

//_ctrlChannelEdit ctrlAddEventHandler ["onKillFocus",{_this spawn FUNC(acreControlChannelEditChange);}];
_ctrlChannelEdit ctrlAddEventHandler ["KeyDown",{_this spawn FUNC(acreControlChannelEditChange);}];

_ctrlBabel ctrlAddEventHandler ["lbselchanged",{_this spawn FUNC(acreControlBabelChange);}];
