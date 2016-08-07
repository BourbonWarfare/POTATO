/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlRadio","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlRadio;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _channels = switch (_index) do {
    case (0): { _ctrlGroup getVariable QGVAR(srList) };
    case (1): { _ctrlGroup getVariable QGVAR(mrList) };
    case (2): { _ctrlGroup getVariable QGVAR(lrList) };
};

lnbClear _ctrlChannels;
{
    _ctrlChannels lnbAddRow [str (_forEachIndex + 1), _x];
} forEach _channels;

_ctrlChannels lnbSetCurSelRow ((_ctrlGroup getVariable [QGVAR(selectedChannels), [0,0,0]]) select _index);
