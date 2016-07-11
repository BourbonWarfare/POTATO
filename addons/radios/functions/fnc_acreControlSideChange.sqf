/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlSide","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSide;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _populatedSR = [];
private _populatedMR = [];
private _populatedLR = [];
switch (_index) do {
    case (0): {
        _populatedSR = GVAR(westSRChannelNames);
        _populatedMR = GVAR(westMRChannelNames);
        _populatedLR = GVAR(westLRChannelNames);
    };
    case (1): {
        _populatedSR = GVAR(eastSRChannelNames);
        _populatedMR = GVAR(eastMRChannelNames);
        _populatedLR = GVAR(eastLRChannelNames);
    };
    case (2): {
        _populatedSR = GVAR(indySRChannelNames);
        _populatedMR = GVAR(indyMRChannelNames);
        _populatedLR = GVAR(indyLRChannelNames);
    };
    default {
        _populatedSR = GVAR(civSRChannelNames);
        _populatedMR = GVAR(civMRChannelNames);
        _populatedLR = GVAR(civLRChannelNames);
    };
};

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR); // log channel info
// populate channel info
GVAR(srList) = [_populatedSR, 16] call FUNC(fillChannelArray);
GVAR(mrList) = [_populatedMR, 99] call FUNC(fillChannelArray);
GVAR(lrList) = [_populatedLR, 99] call FUNC(fillChannelArray);

[_ctrlRadio,lbCurSel _ctrlRadio] call FUNC(acreControlRadioChange);
