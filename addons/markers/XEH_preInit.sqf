#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;
GVAR(nextUpdate) = -9999;
GVAR(nextUpdateDrawHash) = -9999;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];
GVAR(autoclaimGroupMarker) = false;
[QGVAR(addMarker), LINKFUNC(addMarkerEvent)] call CBA_fnc_addEventHandler;
[QGVAR(deleteMarker), LINKFUNC(deleteMarkerEvent)] call CBA_fnc_addEventHandler;
[QGVAR(claimMarker), LINKFUNC(claimMarkerEvent)] call CBA_fnc_addEventHandler;

[QGVAR(deleteMarker), {
    params [
        ["_hashKey", "", [""]]
    ];
    TRACE_1("deleteMarker Event",_this);
    if (_hashKey == "") exitWith {};
    private _markerArray = GVAR(drawHash) getOrDefault [_hashKey, [objNull]];
    if !(isNull (_markerArray#0)) then {
        private _oldObject = _markerArray#0;
        _oldObject setVariable [QGVAR(addMarker), false];
        _oldObject setVariable [QGVAR(markerText), nil];
        _oldObject setVariable [QGVAR(markerTexture), nil];
        _oldObject setVariable [QGVAR(markerColor), nil];
        _oldObject setVariable [QGVAR(markerSize), nil];
    };
    GVAR(drawHash) deleteAt _hashKey;
}] call CBA_fnc_addEventHandler;
[QGVAR(transferMarker), {
    params [
        ["_hashKey", "", [""]],
        ["_newOwner", objNull, [objNull, grpNull]]
    ];
    TRACE_1("transferMarker Event",_this);
    if (_hashKey == "") exitWith {};
    private _markerArray = GVAR(drawHash) getOrDefault [_hashKey, []];
    if (_markerArray isEqualTo []) exitWith {};
    //private _newHashKey = if ()
    GVAR(drawHash) deleteAt _hashKey;
}] call CBA_fnc_addEventHandler;


ADDON = true;
