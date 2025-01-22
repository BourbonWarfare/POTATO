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
if (hasInterface) then {
    [QGVAR(claimMarker), {
        params [
            ["_hashKey", "", [""]],
            ["_object", objNull]
        ];
        TRACE_1("claimMarker Event",_this);
        if (_hashKey == "") exitWith {};
        private _markerArray = GVAR(drawHash) getOrDefault [_hashKey, []];
        if (_markerArray isNotEqualTo []) then {
            TRACE_1("claimMarker Found Entry",_markerArray);
            if !(isNull _object) then {
                _object setVariable [QGVAR(addMarker), true];
                _object setVariable [QGVAR(markerText), _markerArray#1];
                _object setVariable [QGVAR(markerTexture), _markerArray#2];
                _object setVariable [QGVAR(markerColor), _markerArray#3];
                _object setVariable [QGVAR(markerSize), _markerArray#4];
            };
            if !(isNull (_markerArray#0)) then {
                private _oldObject = _markerArray#0;
                _oldObject setVariable [QGVAR(addMarker), false];
                _oldObject setVariable [QGVAR(markerText), nil];
                _oldObject setVariable [QGVAR(markerTexture), nil];
                _oldObject setVariable [QGVAR(markerColor), nil];
                _oldObject setVariable [QGVAR(markerSize), nil];
            };
            _markerArray set [0, _object];
        }
    }] call CBA_fnc_addEventHandler;
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
};

ADDON = true;
