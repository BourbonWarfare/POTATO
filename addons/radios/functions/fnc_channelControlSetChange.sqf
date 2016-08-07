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
private _fade = if (_switch) then { FADE_ENABLED } else { FADE_DISABLED };

_ctrlGroup setVariable [QGVAR(setChannel), _switch];
_ctrlChoose ctrlEnable _switch;
_ctrlChannel ctrlEnable _switch;

_ctrlChoose ctrlSetFade _fade;
_ctrlChannel ctrlSetFade _fade;

_ctrlChoose ctrlCommit FADE_LENGTH;
_ctrlChannel ctrlCommit FADE_LENGTH;
