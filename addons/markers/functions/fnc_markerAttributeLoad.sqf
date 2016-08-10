/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_params", [], [[],true]]];


if (_params isEqualType true && {_params}) exitWith { LOG("channels not set, or in strange state, exiting early"); };

_params params [
    ["_isSet", _ctrlGroup getVariable [QGVAR(setMarker), false], [false]],
    ["_markerText", _ctrlGroup getVariable [QGVAR(markerText), ""], [""]],
    ["_markerInfo", _ctrlGroup getVariable [QGVAR(markerInfo), ""], [""]]
];

if (_isSet) then {
    private _ctrlSet = _ctrlGroup controlsGroupCtrl MARKER_SET_IDC;

    (_markerInfo splitString ",") params [
        ["_markerSize", _ctrlGroup getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE], [0]],
        ["_markerColor", _ctrlGroup getVariable [QGVAR(markerColor), "white"], [""]],
        ["_markerIcon", _ctrlGroup getVariable [QGVAR(markerIcon), DEFAULT_MARKER_ICON], [""]]
    ];

    _markerSize = parseNumber _markerSize;
    if (_markerSize < 1) then { _markerSize = DEFAULT_MARKER_SIZE; };

    _ctrlSet lbSetCurSel 1;
    [_ctrlSet,1] call FUNC(markerControlSetChange);

    _ctrlGroup setVariable [QGVAR(markerText),_markerText];
    _ctrlGroup setVariable [QGVAR(markerSize),_markerSize];
    _ctrlGroup setVariable [QGVAR(markerColor),_markerColor];
    _ctrlGroup setVariable [QGVAR(markerIcon),_markerIcon];
};
