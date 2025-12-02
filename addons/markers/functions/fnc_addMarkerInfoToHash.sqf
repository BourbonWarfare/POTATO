#include "..\script_component.hpp"
/*
 * Author: AACO, Lambda.Tiger
 * Function used to add unit/group marker information into the marker hash.
 * Will broadcast new markers to other machines using remoteExec
 *
 * Arguments:
 * 0: Unit or Group to add to the marker system <OBJECT><GROUP>
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
    GROUP_MARKER_ID_GROUPSTRING_GROUP(_drawObject)
} else {
    if (_drawObject getVariable [QGVAR(groupMarker), false]) then {
        GROUP_MARKER_ID_GROUPSTRING_UNIT(_drawObject)
    } else {
        GROUP_MARKER_ID_UNITSTRING_UNIT(_drawObject)
    }
};

if (isNull _drawObject || !_localObject || _hashKey == ""
    || {!(_drawObject getVariable [QGVAR(addMarker), false])}
    || {_hashKey in GVAR(markerHash)}) exitWith {
    TRACE_3("Not adding marker info (exiting early)",_drawObject,_localObject,_hashKey);
    false
};
TRACE_2("Adding marker",_drawObject,_hashKey);
private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _icon = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _color = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];
TRACE_4("Marker params",_text,_icon,_color,_size);

// we convert here to make variables more readable for other marker debugging
private _findIndex = COLOR_INDEX_ARRAY find _color;
if (_findIndex >= 0) then {_color = _findIndex};

_findIndex = [UNIT_MARKERS_STRINGS] find _icon;
_icon = [_findIndex, DEFAULT_MARKER_ICON_INDEX] select (_findIndex < 0);

if (_drawObject isEqualType grpNull) then {
    _drawObject = leader _drawObject;
};

private _markerArray = [_hashKey, getPosATL _drawObject, _drawObject, side _drawObject, _text, _color, _icon, _size];
private _endIndex = 8;
if (_size == DEFAULT_MARKER_SIZE) then {_endIndex = 7};
if (_icon == DEFAULT_MARKER_ICON_INDEX && _endIndex == 7) then {_endIndex = 6};

_markerArray = _markerArray select [0, _endIndex];
TRACE_1("Final marker array",_markerArray);
GVAR(markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, _markerArray, true];
_markerArray remoteExecCall [QFUNC(addMarker)];

true
