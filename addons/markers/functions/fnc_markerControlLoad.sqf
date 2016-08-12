/*
 *
 */

#include "script_component.hpp"
TRACE_1("params");

params ["_ctrlGroup"];

// get controls
private _ctrlSet = _ctrlGroup controlsGroupCtrl MARKER_SET_IDC;
private _ctrlIcon = _ctrlGroup controlsGroupCtrl MARKER_ICON_IDC;
private _ctrlName = _ctrlGroup controlsGroupCtrl MARKER_NAME_IDC;
private _ctrlSize = _ctrlGroup controlsGroupCtrl MARKER_SIZE_IDC;
private _ctrlColor = _ctrlGroup controlsGroupCtrl MARKER_COLOR_IDC;

// set default values
_ctrlGroup setVariable [QGVAR(setMarker), false];
_ctrlGroup setVariable [QGVAR(markerIcon), DEFAULT_MARKER_ICON];
_ctrlGroup setVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
_ctrlGroup setVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];
_ctrlGroup setVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR_TEXT];

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(markerSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(markerSetChange);

// PROBABLY don't need the below, just grab on save with IDCs
_ctrlSize ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(markerSizeChange);}];
_ctrlSize lbSetCurSel 0;

_ctrlColor ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(markerColorChange);}];
_ctrlColor lbSetCurSel 0;

_ctrlIcon ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(markerIconChange);}];
_ctrlIcon lbSetCurSel 0;

_ctrlName ctrlAddEventHandler ["onKillFocus",{_this call FUNC(markerNameChange);}];
