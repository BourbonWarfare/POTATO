/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlChannels","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannels;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _selectedRadioIndex = lbCurSel _ctrlRadio;

TRACE_3("pre",GVAR(selectedChannels),_selectedRadioIndex,_index);
GVAR(selectedChannels) set [_selectedRadioIndex, _index];
TRACE_3("post",GVAR(selectedChannels),_selectedRadioIndex,_index);
