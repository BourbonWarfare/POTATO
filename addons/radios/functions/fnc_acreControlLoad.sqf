/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlGroup"];

private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

{
    _x params ["_short", "_long"];
    _ctrlBabel lnbAddRow [_short, _long];
} forEach GVAR(availableLanguages);
