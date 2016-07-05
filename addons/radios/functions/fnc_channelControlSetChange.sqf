/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlSet","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSet;
private _ctrlChoose = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannel = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

if (_index == 1) then {
    _ctrlChoose ctrlEnable true;
    _ctrlChannel ctrlEnable true;
    _ctrlChoose ctrlSetFade 0;
    _ctrlChannel ctrlSetFade 0;
    _ctrlChoose ctrlCommit 0.5;
    _ctrlChannel ctrlCommit 0.5;
} else {
    _ctrlChoose ctrlEnable false;
    _ctrlChannel ctrlEnable false;
    _ctrlChoose ctrlSetFade 0.7;
    _ctrlChannel ctrlSetFade 0.7;
    _ctrlChoose ctrlCommit 0.5;
    _ctrlChannel ctrlCommit 0.5;
};
