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

#include "..\script_component.hpp"
TRACE_1("Params",_this);

params ["_drawObject"];
private _groupMarker = _drawObject getVariable [QGVAR(groupMarker), false];

private _hashKey = if (_drawObject isEqualType grpNull) then {
    groupId _drawObject
} else {
    if (_groupMarker) then {
        groupId group _drawObject
    } else {
        str _drawObject
    }
};
if (isNull _drawObject
        || {!(_drawObject getVariable [QGVAR(addMarker), false])}
        || {_hashKey in GVAR(drawHash)}) exitWith {
    TRACE_1("Not adding marker info (exiting early)",_drawObject);
    false
};
TRACE_2("Adding marker",_groupMarker,_hashKey);
private _shouldClaim = false;
private _text = _drawObject getVariable [QGVAR(markerText), DEFAULT_MARKER_TEXT];
private _texture = _drawObject getVariable [QGVAR(markerTexture), DEFAULT_MARKER_ICON];
private _colorArray = _drawObject getVariable [QGVAR(markerColor), DEFAULT_MARKER_COLOR];
private _size = _drawObject getVariable [QGVAR(markerSize), DEFAULT_MARKER_SIZE];
private _position = if (_drawObject isEqualType grpNull) then {
    if ((units _drawObject) isEqualTo []) exitWith {[-10000, -10000, 0]};
    _shouldClaim = local _drawObject;
    position leader _drawObject
} else {
    position _drawObject
};

GVAR(drawHash) set [_hashKey, [_drawObject, _text, _texture, _colorArray, _size, _position]];

if (_shouldClaim) then {
    private _drawObject = leader _drawObject;
    _drawObject setVariable [QGVAR(groupMarker), true, true];
    [QGVAR(claimMarker), [_hashKey, leader _drawObject], _hashKey] call CBA_fnc_globalEventJIP;
};

true
