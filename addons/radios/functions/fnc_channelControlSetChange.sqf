/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlSet","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSet;
private _ctrlChoose = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannel = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _switch = _index == 1;
GVAR(setChannel) = _switch;
_ctrlChoose ctrlEnable _switch;
_ctrlChannel ctrlEnable _switch;

if (_switch) then {
    _ctrlChoose ctrlSetFade FADE_ENABLED;
    _ctrlChannel ctrlSetFade FADE_ENABLED;
} else {
    _ctrlChoose ctrlSetFade FADE_DISABLED;
    _ctrlChannel ctrlSetFade FADE_DISABLED;
};

_ctrlChoose ctrlCommit FADE_LENGTH;
_ctrlChannel ctrlCommit FADE_LENGTH;
