/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlChannels","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannels;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _selectedRadioIndex = lbCurSel _ctrlRadio;

private _selectedChannels = _ctrlGroup getVariable [QGVAR(selectedChannels), [0,0,0]];
TRACE_3("pre",_selectedChannels,_selectedRadioIndex,_index);
_selectedChannels set [_selectedRadioIndex, _index];
TRACE_3("post",_selectedChannels,_selectedRadioIndex,_index);
_ctrlGroup setVariable [QGVAR(selectedChannels), _selectedChannels];
