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
private _selectedGroups = get3DENSelected "group";
private _selected = if (count _selectedGroups > 0) then {
    _selectedGroups
} else {
    get3DENSelected "object"
};
_ctrlGroup setVariable [QGVAR(selected), _selected];

// determine side of unit(s)/group(s) bail if there is a mix of sides
private _side = side (_selected select 0);
_ctrlGroup setVariable [QGVAR(channelsInvalid), false];
{
    if (side _x != _side) exitWith { _ctrlGroup setVariable [QGVAR(channelsInvalid), true]; };
} forEach _selected;

_ctrlGroup setVariable [QGVAR(setChannel), false];
_ctrlGroup setVariable [QGVAR(selectedChannels), [0,0,0]];

// there's either nothing selected, or a mix of sides, bail out
if (_ctrlGroup getVariable QGVAR(channelsInvalid) || {count _selected < 0}) exitWith {
    [false, [
        _ctrlChannel,
        _ctrlRadio,
        _ctrlSet
    ]] call EFUNC(core,setControlFade);
};

[_ctrlGroup, _side] call FUNC(setChannelArrays);

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(channelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(channelControlSetChange);

_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(channelControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(channelControlRadioChange);

_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(channelControlChannelChange);}];
