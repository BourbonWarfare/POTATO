#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

GVAR(drawHash) = createHashMap;
GVAR(nextUpdate) = -9999;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];
GVAR(autoclaimGroupMarker) = false;
[QGVAR(claimMarker), {
    params [
        ["_hashKey", "", [""]],
        ["_object", objNull]
    ];
    if (_hashKey == "") exitWith {};
    private _markerArray = GVAR(drawHash) getOrDefault [_hashKey, []];
    if (_markerArray isNotEqualTo []) then {
        if (local _object) then {
            _object setVariable [QGVAR(markerText), _markerArray#1, true];
            _object setVariable [QGVAR(markerTexture), _markerArray#2, true];
            _object setVariable [QGVAR(markerColor), _markerArray#3, true];
            _object setVariable [QGVAR(markerSize), _markerArray#4, true];
        };
        if (local (_markerArray#0)) then {
            _object setVariable [QGVAR(markerText), nil, true];
            _object setVariable [QGVAR(markerTexture), nil, true];
            _object setVariable [QGVAR(markerColor), nil, true];
            _object setVariable [QGVAR(markerSize), nil, true];
        };
        _markerArray set [0, _object];
    }
}] call CBA_fnc_addEventHandler;

ADDON = true;
