/*
 *
 */

#include "script_component.hpp"
TRACE_2("params",_this,_this getVariable QGVAR(setMarker));

private _setMarker = _this getVariable [QGVAR(setMarker), false];
if (_setMarker) then {
    private _ctrlIcon = _this controlsGroupCtrl MARKER_ICON_IDC;
    private _ctrlName = _this controlsGroupCtrl MARKER_NAME_IDC;
    private _ctrlSize = _this controlsGroupCtrl MARKER_SIZE_IDC;
    private _ctrlColor = _this controlsGroupCtrl MARKER_COLOR_IDC;
    format [
        "%1,%2,%3,%4",
        ((ctrlText _ctrlName) splitString ",") joinString "",
        [UNIT_MARKER_SIZES] select (lbCurSel _ctrlSize),
        [UNIT_MARKER_COLORS] select (lbCurSel _ctrlColor),
        [UNIT_MARKERS] select (lbCurSel _ctrlIcon)
    ]
} else {
    true
}
