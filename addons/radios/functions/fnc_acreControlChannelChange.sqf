/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlChannels","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannels;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannelEdit = _ctrlGroup controlsGroupCtrl CFG_CHANNEL_IDC;

private _selectedRadioIndex = lbCurSel _ctrlRadio;
private _selectedSideIndex = lbCurSel _ctrlSide;

TRACE_3("pre",(GVAR(sideChannelArray) select _selectedSideIndex),_selectedRadioIndex,_index);
(GVAR(sideChannelArray) select _selectedSideIndex) set [_selectedRadioIndex, _index];
TRACE_3("post",(GVAR(sideChannelArray) select _selectedSideIndex),_selectedRadioIndex,_index);

_ctrlChannelEdit ctrlSetText (_ctrlChannels lnbText [_index,1]);
