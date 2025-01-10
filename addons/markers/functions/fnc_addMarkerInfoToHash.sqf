/*
 * Author: AACO
 * Function used to add unit/group marker information into the marker hash
 *
 * Arguments:
 * 0: Unit or Group to add to the marker system <OBJECT/GROUP>
 *
 * Return Value:
 * True if the info was added to the hash, false otherwise <BOOL>
 *
 * Examples:
 * [player] call potato_markers_fnc_addMarkerInfoToHash;
 * [group player] call potato_markers_fnc_addMarkerInfoToHash;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_drawObject"];
private _hashValue = POTATO_MARKERS_HASHVALUE(_drawObject);
if (isNull _drawObject
        || {!(_drawObject getVariable [QGVAR(addMarker), false])}
        || {_hashValue in GVAR(drawHash)}) exitWith {
    TRACE_1("Not adding marker info (exiting early)",_drawObject);
    false
};

private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _texture = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _colorArray = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];
private _position = if (_drawObject isEqualType grpNull) then {
    if ((units _drawObject) isEqualTo []) exitWith {[-10000, -10000, 0]};
    if (GVAR(autoclaimGroupMarker)) then {
        position leader _drawObject
    } else {
        _drawObject = leader _drawObject;
        position _drawObject
    };
} else {
    position _drawObject
};

GVAR(drawHash) set [_hashValue, [_drawObject, _text, _texture, _colorArray, _size, _position]];

true
