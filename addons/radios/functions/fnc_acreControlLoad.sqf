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

GVAR(sideChannelArray) = [
    [0,0,0], // west
    [0,0,0], // east
    [0,0,0], // indy
    [0,0,0] // civ
];

GVAR(sideBabelArray) = [
    0, // west
    0, // east
    0, // indy
    0 // civ
];

{
    _x params ["_short", "_long"];
    _ctrlBabel lnbAddRow [_short, _long];
} forEach GVAR(availableLanguages);

// register event handlers
_ctrlSide ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(acreControlSideChange);}];
_ctrlSide lbSetCurSel 0;
[_ctrlSide,0] call FUNC(acreControlSideChange);

_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(acreControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(acreControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(acreControlChannelChange);}];
[_ctrlChannels,0] call FUNC(acreControlChannelChange);

_ctrlChannelEdit ctrlAddEventHandler ["KeyDown",{_this call FUNC(acreControlChannelEditChange);}];
