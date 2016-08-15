/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlChannelEdit"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannelEdit;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _selectedSideIndex = lbCurSel _ctrlSide;
private _selectedRadioIndex = lbCurSel _ctrlRadio;
private _selectedChannelIndex = lnbCurSelRow _ctrlChannels;

private _channelName = (((ctrlText _ctrlChannelEdit) splitString ",") joinString "");

private _side = civilian;
switch (_selectedSideIndex) do {
    case (0): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(westSRChannelNames) set [_selectedChannelIndex, _channelName]; };
            case (1): { GVAR(westMRChannelNames) set [_selectedChannelIndex, _channelName]; };
            default { GVAR(westLRChannelNames) set [_selectedChannelIndex, _channelName]; };
        };
        _side = west;
    };
    case (1): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(eastSRChannelNames) set [_selectedChannelIndex, _channelName]; };
            case (1): { GVAR(eastMRChannelNames) set [_selectedChannelIndex, _channelName]; };
            default { GVAR(eastLRChannelNames) set [_selectedChannelIndex, _channelName]; };
        };
        _side = east;
    };
    case (2): {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(indySRChannelNames) set [_selectedChannelIndex, _channelName]; };
            case (1): { GVAR(indyMRChannelNames) set [_selectedChannelIndex, _channelName]; };
            default { GVAR(indyLRChannelNames) set [_selectedChannelIndex, _channelName]; };
        };
        _side = independent;
    };
    default {
        switch (_selectedRadioIndex) do {
            case (0): { GVAR(civSRChannelNames) set [_selectedChannelIndex, _channelName]; };
            case (1): { GVAR(civMRChannelNames) set [_selectedChannelIndex, _channelName]; };
            default { GVAR(civLRChannelNames) set [_selectedChannelIndex, _channelName]; };
        };
    };
};

[_ctrlGroup,_side] call FUNC(setChannelArrays);
[_ctrlRadio,lbCurSel _ctrlRadio] call FUNC(acreSideControlRadioChange);
