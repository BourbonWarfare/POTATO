#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Saves the currently placed user markers under a given save name
 *
 *
 * Arguments:
 * _saveName - The name of the save entry to be load, unique per terrain
 *            (default "DEFAULT_SAVE_NAME") <STRING>
 *
 * Examples:
 *
 *
 * Public: No
 */
params [["_saveName", "DEFAULT_SAVE_NAME", [""]]];
private _savedMarkers = profileNamespace getVariable [QGVAR(savedMarkers), createHashMap];
private _terrainHash = _savedMarkers getOrDefault [worldName, createHashMap, true];
private _markers = _terrainHash getOrDefault [_saveName, "{}"];
if (_markers == "{}") exitWith {ERROR_1("No save data [%1]",_saveName)};
_markers = fromJSON _markers;
// Make a unique name string and starting point to avoid (in most cases) overwriting markers
private _nameString = "_USER_DEFINED #-1234/%1/" + str currentChannel;
private _IDOffset = clientOwner * 500; // unique ID w/ 500 marks gaurenteed to not overlap
while {getMarkerPos format [_nameString, _IDOffset] isNotEqualTo [0, 0, 0]} do {
    _IDOffset = _IDOffset + 1;
};
{
    private _marker = format [_nameString, _IDOffset + _forEachIndex];
    if (_y#0) then {
        _y params ["", "_color", "_pts"];
        if (getMarkerPos _marker isNotEqualTo [0, 0, 0]) then {
            deleteMarkerLocal _marker;
        };
        createMarkerLocal [_marker, [_pts#0, _pts#1, 0]];
        _marker setMarkerShapeLocal "POLYLINE";
        _marker setMarkerColorLocal _color;
        _marker setMarkerPolyline _pts;
    } else {
        _y params ["", "_color", "_pos", "_dir", "_size", "_type", "_text"];
        if (getMarkerPos _marker isEqualTo [0, 0, 0]) then {
            createMarkerLocal [_marker, _pos];
        } else {
            _marker setMarkerPosLocal _pos;
        };
        _marker setMarkerColorLocal _color;
        _marker setMarkerDirLocal _dir;
        _marker setMarkerSizeLocal _size;
        _marker setMarkerTypeLocal _type;
        _marker setMarkerText _text;
    };
} forEach _markers;
