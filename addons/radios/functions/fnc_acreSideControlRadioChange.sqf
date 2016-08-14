/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlRadio","_index",["_channelIndex",0,[0]]];

private _ctrlGroup = ctrlParentControlsGroup _ctrlRadio;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _channels = switch (_index) do {
    case (0): { _ctrlGroup getVariable QGVAR(srList) };
    case (1): { _ctrlGroup getVariable QGVAR(mrList) };
    case (2): { _ctrlGroup getVariable QGVAR(lrList) };
};

TRACE_5("radio change",_ctrlGroup,_ctrlSide,_ctrlRadio,_ctrlChannels,_channels);

lnbClear _ctrlChannels;
{
    _ctrlChannels lnbAddRow [str (_forEachIndex + 1), _x];
} forEach _channels;

private _sideIndex = lbCurSel _ctrlSide;
_ctrlChannels lnbSetCurSelRow _channelIndex;
