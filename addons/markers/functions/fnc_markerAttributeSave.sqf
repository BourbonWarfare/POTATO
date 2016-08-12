/*
 *
 */

#include "script_component.hpp"
TRACE_6("params",_this,_this getVariable QGVAR(setMarker),\
_this getVariable QGVAR(markerText),_this getVariable QGVAR(markerSize),\
_this getVariable QGVAR(markerColor),_this getVariable QGVAR(markerIcon));

private _setMarker = _this getVariable [QGVAR(setMarker), false];
if (_setMarker) then {
    format [
        "%1,%2,%3,%4",
        ((_this getVariable [QGVAR(markerText), ""] splitString ",") joinString ""),
        _this getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE],
        _this getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR_TEXT],
        _this getVariable [QGVAR(markerIcon), DEFAULT_MARKER_ICON]
    ]
} else {
    true
}
