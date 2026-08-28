#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * radio parameters, adds relevant events and ACE actions, and configures
 * local variables for marker sharing
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params [["_jsonMarkers", "{}"]];
private _markers = fromJSON _jsonMarkers;

if (isNil {_markers} || {_markers isEqualTo createHashMap}) exitWith {
    TRACE_1("Bad JSON sent",_jsonMarkers);
};
if (ace_player getSlotItemName 608 == "") exitWith {
    ["You tried to copy someone's markers but you don't have a map.", true, 5] call ACEFUNC(common,displayText);
};

["Markers copied to map.", true, 5] call ACEFUNC(common,displayText);
{
    if (_y#0) then {
        _y params ["", "_color", "_pts"];
        private _marker = createMarkerLocal [_x, [_pts#0, _pts#1, 0]];
        _x setMarkerShapeLocal "POLYLINE";
        _x setMarkerColorLocal _color;
        _x setMarkerPolylineLocal _pts;
    } else {
        _y params ["", "_color", "_pos", "_dir", "_size", "_type", "_text"];
        private _marker = createMarkerLocal [_x, _pos];
        _x setMarkerColorLocal _color;
        _x setMarkerDirLocal _dir;
        _x setMarkerSizeLocal _size;
        _x setMarkerTypeLocal _type;
        _x setMarkerTextLocal _text;
    };
} forEach _markers;
