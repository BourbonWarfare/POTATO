/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (GVAR(channelsInvalid)) exitWith { LOG("Multiple sides selected, exiting early"); };

params ["_ctrlGroup",["_params", [], [[],true]]];
if (_params isEqualType true && {_params}) exitWith { LOG("channels not set, or in strange state, exiting early"); };

_params params [["_isSet",GVAR(setChannel), [false]], ["_channelArray",GVAR(selectedChannels), [[]]]];

if (_isSet) then {
    private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
    private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
    private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

    GVAR(setChannel) = _isSet;
    GVAR(selectedChannels) = _channelArray;

    _ctrlSet lbSetCurSel 1;
    [_ctrlSet,1] call FUNC(channelControlSetChange);
    _ctrlChannels lnbSetCurSelRow (GVAR(selectedChannels) select (lbCurSel _ctrlRadio));
};
