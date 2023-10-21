/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

// set default values
_ctrlGroup setVariable [QGVAR(setMarker), false];

// get controls
private _ctrlSet = _ctrlGroup controlsGroupCtrl MARKER_SET_IDC;
private _ctrlIcon = _ctrlGroup controlsGroupCtrl MARKER_ICON_IDC;
private _ctrlName = _ctrlGroup controlsGroupCtrl MARKER_NAME_IDC;
private _ctrlSize = _ctrlGroup controlsGroupCtrl MARKER_SIZE_IDC;
private _ctrlColor = _ctrlGroup controlsGroupCtrl MARKER_COLOR_IDC;

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(markerControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(markerControlSetChange);

_ctrlSize lbSetCurSel 1;
_ctrlColor lbSetCurSel 0;
_ctrlIcon lbSetCurSel 0;
