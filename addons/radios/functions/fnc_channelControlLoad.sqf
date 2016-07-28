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

[_side] call FUNC(setChannelArrays);

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(channelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(channelControlSetChange);

_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(channelControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(channelControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(channelControlChannelChange);}];
