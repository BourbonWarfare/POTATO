/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,get3DENSelected "object",get3DENSelected "group");
params ["_ctrlGroup"];

// get controls
private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

// determine selected objects, prioritize groups
private _selectedObjects = get3DENSelected "object";
private _selectedGroups = get3DENSelected "group";
GVAR(selected) = if (count _selectedGroups > 0) then {
    _selectedGroups;
} else {
    _selectedObjects
};

// determine side of unit(s)/group(s) bail if there is a mix of sides
private _side = side (GVAR(selected) select 0);
GVAR(channelsInvalid) = false;
{
    if (side _x != _side) exitWith { GVAR(channelsInvalid) = true };
} forEach GVAR(selected);

GVAR(setChannel) = false;
GVAR(selectedChannels) = [0,0,0];

// there's either nothing selected, or a mix of sides, bail out
if (GVAR(channelsInvalid) || {count GVAR(selected) < 0}) exitWith {
    _ctrlChannel ctrlEnable false;
    _ctrlRadio ctrlEnable false;
    _ctrlSet ctrlEnable false;

    _ctrlChannel ctrlSetFade FADE_DISABLED;
    _ctrlRadio ctrlSetFade FADE_DISABLED;
    _ctrlSet ctrlSetFade FADE_DISABLED;

    _ctrlChannel ctrlCommit FADE_LENGTH;
    _ctrlRadio ctrlCommit FADE_LENGTH;
    _ctrlSet ctrlCommit FADE_LENGTH;
};

// build a list of SR/MR/LR channels from ACE settings/mission settings
private _populatedSR = [];
private _populatedMR = [];
private _populatedLR = [];
switch (_side) do {
    case (west): {
        _populatedSR = GVAR(westSRChannelNames);
        _populatedMR = GVAR(westMRChannelNames);
        _populatedLR = GVAR(westLRChannelNames);
    };
    case (east): {
        _populatedSR = GVAR(eastSRChannelNames);
        _populatedMR = GVAR(eastMRChannelNames);
        _populatedLR = GVAR(eastLRChannelNames);
    };
    case (resistance): {
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
// populate channel ingo
GVAR(srList) = [_populatedSR, 16] call FUNC(fillChannelArray);
GVAR(mrList) = [_populatedMR, 99] call FUNC(fillChannelArray);
GVAR(lrList) = [_populatedLR, 99] call FUNC(fillChannelArray);

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(channelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(channelControlSetChange);

_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(channelControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(channelControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(channelControlChannelChange);}];
