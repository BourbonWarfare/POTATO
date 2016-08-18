/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_markerInfo", "", ["",true]]];

if (_markerInfo isEqualType true && {_markerInfo}) exitWith { LOG("channels not set, or in strange state, exiting early"); };

(_markerInfo splitString ",") params [
    ["_markerText", _ctrlGroup getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT], [""]],
    ["_markerSize", _ctrlGroup getVariable [QGVAR(markerSize), str DEFAULT_MARKER_SIZE], [""]],
    ["_markerColor", _ctrlGroup getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR_TEXT], [""]],
    ["_markerIcon", _ctrlGroup getVariable [QGVAR(markerIcon), DEFAULT_MARKER_ICON], [""]]
];

_markerSize = parseNumber _markerSize;
if (_markerSize < 1) then { _markerSize = DEFAULT_MARKER_SIZE; };

_ctrlGroup setVariable [QGVAR(markerText),_markerText];
_ctrlGroup setVariable [QGVAR(markerSize),_markerSize];
_ctrlGroup setVariable [QGVAR(markerColor),_markerColor];
_ctrlGroup setVariable [QGVAR(markerIcon),_markerIcon];

private _ctrlSet = _ctrlGroup controlsGroupCtrl MARKER_SET_IDC;
private _ctrlIcon = _ctrlGroup controlsGroupCtrl MARKER_ICON_IDC;
private _ctrlName = _ctrlGroup controlsGroupCtrl MARKER_NAME_IDC;
private _ctrlSize = _ctrlGroup controlsGroupCtrl MARKER_SIZE_IDC;
private _ctrlColor = _ctrlGroup controlsGroupCtrl MARKER_COLOR_IDC;

_ctrlSet lbSetCurSel 1;
[_ctrlSet,1] call FUNC(markerControlSetChange);

_ctrlName ctrlSetText _markerText;
_ctrlIcon lbSetCurSel ([UNIT_MARKERS] find _markerIcon);
_ctrlSize lbSetCurSel ([UNIT_MARKER_SIZES] find _markerSize);
_ctrlColor lbSetCurSel ([UNIT_MARKER_COLORS] find _markerColor);
