/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,get3DENSelected "object",get3DENSelected "group");
params ["_ctrlGroup"];

private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _selectedObjects = get3DENSelected "object";
private _selectedGroups = get3DENSelected "group";
GVAR(selected) = if (count _selectedGroups > 0) then {
    _selectedGroups;
} else {
    _selectedObjects
};
private _side = side (GVAR(selected) select 0);
private _sideConflict = false;
{
    if (side _x != _side) exitWith { _sideConflict = true };
} forEach GVAR(selected);

if (_sideConflict || {count GVAR(selected) < 0}) exitWith {
    _ctrlChannel ctrlEnable false;
    _ctrlRadio ctrlEnable false;
    _ctrlSet ctrlEnable false;

    _ctrlChannel ctrlSetFade 0.7;
    _ctrlRadio ctrlSetFade 0.7;
    _ctrlSet ctrlSetFade 0.7;

    _ctrlChannel ctrlCommit 0.5;
    _ctrlRadio ctrlCommit 0.5;
    _ctrlSet ctrlCommit 0.5;
};

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

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR);
GVAR(srList) = [];
for "_i" from 0 to 15 do {
    if (_i < (count _populatedSR) && {(_populatedSR select _i) != ""}) then {
        GVAR(srList) pushBack (_populatedSR select _i);
    } else {
        GVAR(srList) pushBack (format ["Channel %1", _i + 1]);
    };
};

GVAR(mrList) = [];
for "_i" from 0 to 98 do {
    if (_i < (count _populatedMR) && {(_populatedMR select _i) != ""}) then {
        GVAR(mrList) pushBack (_populatedMR select _i);
    } else {
        GVAR(mrList) pushBack (format ["Channel %1", _i + 1]);
    };
};

GVAR(lrList) = [];
for "_i" from 0 to 98 do {
    if (_i < (count _populatedLR) && {(_populatedLR select _i) != ""}) then {
        GVAR(lrList) pushBack (_populatedLR select _i);
    } else {
        GVAR(lrList) pushBack (format ["Channel %1", _i + 1]);
    };
};

//_ctrlGroup ctrladdeventhandler ["setfocus",{with uinamespace do {AmmoBox_ctrlGroup = _this select 0;};}];
//_ctrlGroup ctrladdeventhandler ["killfocus",{with uinamespace do {AmmoBox_ctrlGroup = nil;};}];

_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(channelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(channelControlSetChange);


_ctrlRadio ctrlAddEventHandler ["toolboxselchanged",{_this call FUNC(channelControlRadioChange);}];
_ctrlRadio lbSetCurSel 0;
[_ctrlRadio,0] call FUNC(channelControlRadioChange);


_ctrlChannels ctrlAddEventHandler ["lbselchanged",{_this call FUNC(channelControlChannelChange);}];
