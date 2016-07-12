/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlChannels","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlChannels;
private _ctrlChannelEdit = _ctrlGroup controlsGroupCtrl CFG_CHANNEL_IDC;

_ctrlChannelEdit ctrlSetText (_ctrlChannels lnbText [_index,1]);
