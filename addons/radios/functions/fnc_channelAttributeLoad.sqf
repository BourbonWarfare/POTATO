/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_channelString", "", ["",true]]];

if (_ctrlGroup getVariable [QGVAR(channelsInvalid), false]) exitWith { LOG("Multiple sides selected, exiting early"); };

if (_channelString isEqualType true && {_channelString}) exitWith { LOG("channels not set, or in strange state, exiting early"); };

private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

(_channelString splitString ",") params [
    ["_sr", "0", [""]],
    ["_mr", "0", [""]],
    ["_lr", "0", [""]]
];
private _channelArray = [parseNumber _sr, parseNumber _mr, parseNumber _lr];
_ctrlGroup setVariable [QGVAR(selectedChannels), _channelArray];

_ctrlSet lbSetCurSel 1;
[_ctrlSet,1] call FUNC(channelControlSetChange);
_ctrlChannels lnbSetCurSelRow (_channelArray select (lbCurSel _ctrlRadio));
