/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlChannelEdit"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannelEdit;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _selectedSideIndex = lbCurSel _ctrlSide;
private _selectedRadioIndex = lbCurSel _ctrlRadio;
private _selectedChannelIndex = lnbCurSelRow _ctrlChannels;

private _channelName = ctrlText _ctrlChannelEdit;

switch (_selectedRadioIndex) do {
    case (0): { GVAR(srList) set [_selectedChannelIndex, _channelName]; };
    case (1): { GVAR(mrList) set [_selectedChannelIndex, _channelName]; };
    default { GVAR(lrList) set [_selectedChannelIndex, _channelName]; };
};

switch (_selectedSideIndex) do {
    case (0): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(westSRChannelNames) = GVAR(srList); };
            case (1): { GVAR(westMRChannelNames) = GVAR(mrList); };
            default { GVAR(westLRChannelNames) = GVAR(lrList); };
        };
    };
    case (1): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(eastSRChannelNames) = GVAR(srList); };
            case (1): { GVAR(eastMRChannelNames) = GVAR(mrList); };
            default { GVAR(eastLRChannelNames) = GVAR(lrList); };
        };
    };
    case (2): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(indySRChannelNames) = GVAR(srList); };
            case (1): { GVAR(indyMRChannelNames) = GVAR(mrList); };
            default { GVAR(indyLRChannelNames) = GVAR(lrList); };
        };
    };
    default {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(civSRChannelNames) = GVAR(srList); };
            case (1): { GVAR(civMRChannelNames) = GVAR(mrList); };
            default { GVAR(civLRChannelNames) = GVAR(lrList); };
        };
    };
};

[_ctrlRadio,lbCurSel _ctrlRadio] call FUNC(acreControlRadioChange);
