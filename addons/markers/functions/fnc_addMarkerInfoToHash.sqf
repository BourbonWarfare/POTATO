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
TRACE_2("Adding marker",_drawObject getVariable [ARR_2(QGVAR(groupMarker),false)],_hashKey);
private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _icon = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _color = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];

// we convert here to make variables more readable for other marker debugging
if (_color == "") then {
    _color = DEFAULT_MARKER_COLOR;
};
private _findIndex = COLOR_INDEX_ARRAY find _color;
if (_findIndex >= 0) then {_color = _findIndex};

_findIndex = [UNIT_MARKERS_STRINGS] find _icon;
if (_findIndex >= 0) then {_icon = _findIndex};

if (_drawObject isEqualType grpNull) then {
    _drawObject = leader _drawObject;
};

private _markerEventArray = [_hashKey, getPosATL _drawObject, _drawObject, side _drawObject, _text, _color, _icon, _size];
private _endIndex = 7;
if (_size == DEFAULT_MARKER_SIZE) then {_endIndex = 6};
if (_icon == DEFAULT_MARKER_ICON_INDEX && _endIndex == 6) then {_endIndex = 5};
if (_color == DEFAULT_MARKER_COLOR_INDEX && _endIndex == 5) then {_endIndex = 4};
if (_text == DEFAULT_MARKER_TEXT && _endIndex == 4) then {_endIndex = 3};

[
    QGVAR(markerHash),
    _markerEventArray select [0, _endIndex],
    POTATO_MARKER_JIP_PREFIX + _hashKey
] call CBA_fnc_globalEventJIP;

true
