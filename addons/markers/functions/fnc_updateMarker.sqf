#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles visual updates to a marker already in the marker cache
 * It updates a marker locally. The global marker cache will be updated when
 * this function is run on the server, but will not delete marker on current
 * units.
 * Function should be called by remoteExecCall or by global event.
 *
 * Arguments:
 * 0: Hashkey of marker <STRING>
 * 1: Marker text <STRING>
 * 2: Marker icon size DEFAULT_MARKER_SIZE <SCALAR>
 * 3: Color array of the  or default color array index <ARRAY/NUMBER>
 *      (OPTIONAL, default -1 or no change)
 * 4: Icon of the marker to show or default marker array index <STRING/NUMBER>
 *      (OPTIONAL, default -1 or no change)
 *
 * Example:
 * [groupId group player, "Yar", 3] call potato_markers_fnc_updateMarker;
 *
 * Public: Yes
 */
params [
    ["_hashKey", "", [""]],
    ["_newText", DEFAULT_MARKER_TEXT, [DEFAULT_MARKER_TEXT]],
    ["_newSize", DEFAULT_MARKER_SIZE, [DEFAULT_MARKER_SIZE]],
    ["_newColor", -1, [DEFAULT_MARKER_COLOR, DEFAULT_MARKER_COLOR_INDEX]],
    ["_newIcon", -1, [DEFAULT_MARKER_ICON, DEFAULT_MARKER_ICON_INDEX]]
];

private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, []];

if (_markerArray isEqualTo []) exitWith {
    TRACE_1("No entry found in marker hash:",_this);
};

// Update marker array
_markerArray set [1, _newText];
if (_newIcon isEqualType "") then {
    _markerArray set [2, _newIcon];
} else {
    if (_newIcon >= 0) then {
        _markerArray set [2, [UNIT_MARKERS_STRINGS]#_newIcon];
    };
};
if (_newColor isEqualType []) then {
    _markerArray set [3, _newColor];
} else {
    if (_newColor >= 0) then {
        _markerArray set [3, COLOR_INDEX_ARRAY#_newColor];
    };
};
_markerArray set [4, _newSize];
private _newPosATL = getPosATL (_markerArray#0);
if (_newPosATL isNotEqualTo [0, 0, 0]) then {
    _markerArray set [5, _newPosATL];
};

if (isServer) then {// server updates cache for JIPs, a bit of work since we "optimized" size
    private _markerCacheEntry = GVAR(markerCache) getVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, []];
    if (_markerCacheEntry isEqualTo []) exitWith {
        WARNING_1("Invalid marker update attempt with key: %1",_hashKey);
    };
    private _currLength = count _markerCacheEntry - 1;
    private _newLength = switch (true) do {
        case ((_newSize != DEFAULT_MARKER_SIZE && _currLength < 7) ||
                (_currLength == 7 && {_newSize != _markerCacheEntry#7 })): {7};
        case !(_newIcon isEqualType -1 && {_newIcon < 0}): {6};
        case !(_newColor isEqualType -1 && {_newColor < 0}): {5};
        default {4};
    };
    _markerCacheEntry set [4, _newText];
    if (_newLength > 4) then {
        if (_newColor isEqualType [] || {_newColor >= 0}) then {
            _markerCacheEntry set [5, _newColor];
        } else {
            if (_currLength < 5) then {
                _markerCacheEntry set [5, DEFAULT_MARKER_COLOR_INDEX];
            };
        };
    };
    if (_newLength > 5) then {
        if (_newIcon isEqualType "" || {_newIcon >= 0}) then {
            _markerCacheEntry set [6, _newIcon];
        } else {
            if (_currLength < 6) then {
                _markerCacheEntry set [6, DEFAULT_MARKER_ICON_INDEX];
            };
        };
    };
    if (_newLength > 6 && _currLength < 7) then {
        _markerCacheEntry set [7, _newSize];
    };
    TRACE_1("Updating marker cache entry",_markerCacheEntry);
    GVAR(markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, _markerCacheEntry, true];
};

if (_markerArray#6 in ([] call FUNC(getSideArray))) then {
    GVAR(drawHash) set [_hashKey, _markerArray];
};
