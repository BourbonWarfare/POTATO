#include "..\script_component.hpp"
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
TRACE_1("Params",_this);
params ["_drawObject"];

private _localObject = local _drawObject;
private _hashKey = if (_drawObject isEqualType grpNull) then {
    _localObject = local leader _drawObject;
    groupId _drawObject
} else {
    if (_drawObject getVariable [QGVAR(groupMarker), false]) then {
        groupId group _drawObject
    } else {
        str _drawObject
    }
};

if (isNull _drawObject || !_localObject || _hashKey == ""
    || {!(_drawObject getVariable [QGVAR(addMarker), false])}
    || {_hashKey in GVAR(drawHash)}) exitWith {
    TRACE_3("Not adding marker info (exiting early)",_drawObject,_localObject,_hashKey);
    false
};
TRACE_2("Adding marker",_drawObject getVariable [QGVAR(groupMarker), false],_hashKey);
private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _icon = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _colorArray = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];

if (_drawObject isEqualType grpNull) then {
    _drawObject = leader _drawObject;
};

private _markerEventArray = [_hashKey, _drawObject, _text, _icon, _colorArray, _size];
private _endIndex = 5;
if (_size == DEFAULT_MARKER_SIZE) then {_endIndex = 4};
if (_colorArray == DEFAULT_MARKER_COLOR && _endIndex == 4) then {_endIndex = 3};
if ((_icon == DEFAULT_MARKER_ICON || _icon == "") && _endIndex == 3) then {_endIndex = 2};
if (_text == DEFAULT_MARKER_TEXT && _endIndex == 2) then {_endIndex = 1};

[
    QGVAR(markerHash),
    _markerEventArray select [0, _endIndex],
    "potato_marker_" + _hashKey
] call CBA_fnc_globalEventJIP;

true
