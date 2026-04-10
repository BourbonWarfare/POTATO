/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion takes a marker and returns a random position (ATL) within the
* dimensions of the area
*
* Arguments:
* _mark   - <string> marker variable name
*
* Return:
* _position <array> - Position in ATL format, [0, 0, 0] if a marker
*					is not given;
*
* Example:
* ["objectiveZone"] call bw_fnc_posInMarker;
*//***************************************************************************/
params [
    ["_mark", "", [""]]
];

if (_mark isEqualTo "") exitWith {[0, 0, 0]};

private _center = getMarkerPos _mark;
private _dims = getMarkerSize _mark;
private _dir = markerDir _mark;

private _x = (-1 + random 2)*_dims#0;
private _y = (-1 + random 2)*_dims#1;

private _cDir = cos _dir;
private _sDir = sin _dir;
[
    _x * _cDir + _y * _sDir,
    -_x * _sDir + _y * _cDir,
    0
] vectorAdd _center
