/*
 * Author: AACO
 * Function used to add units from the faction unit list to the pending list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the unit in the faction unit list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the first index
 * [5] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_drawObject"];

if (isNull _drawObject
        || {!(_drawObject getVariable [QGVAR(addMarker), false])}
        || {_drawObject in (GVAR(drawHash) select 0)}) exitWith {
    TRACE_1("Not adding marker info (exiting early)",_drawObject);
    false
};

private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _texture = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _colorArray = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_SIZE];
private _position = if (_drawObject isEqualType grpNull) then {
    position (leader _drawObject)
} else {
    position _drawObject
};

(GVAR(drawHash) select 0) pushBack _drawObject;
(GVAR(drawHash) select 1) pushBack [_text, _texture, _color, _size, _position];

true
