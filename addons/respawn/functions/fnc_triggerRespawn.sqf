/*
 * Author: AACO
 * Kicks off the respawn process for the current active group array
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_triggerRespawn;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define UNIT_SPACING 5
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(triggerRespawn), SERVER_CLIENT_ID];
};

// warning, mutating _position
params [["_position", [-999, -999], [[]], [2, 3]]];

_position resize 2;

if (_position isEqualTo [-999, -999]) exitWith { ERROR("Invalid position given to trigger respawn script"); };

{
    _x params [
        "_factionData",
        "",
        "_groupData",
        "",
        "_configData",
        "",
        "",
        "",
        "_newUnits"
    ];

    private _unitCount = { !isNull (_x select 3) } count _newUnits;

    if (_unitCount > 0) then {
        (GVAR(factionsToInfo) getVariable _factionData) params [
            "",
            "_callsignPrefix",
            "_factionClassname",
            "_factionPrefix"
        ];

        private _factionSide = [getNumber (configFile >> "CfgFactionClasses" >> _factionClassname >> "side")] call EFUNC(core,toSide);

        (GVAR(groupsToInfo) getVariable _groupData) params [
            "_groupDisplayName",
            "_unitsArray",
            "_configsArray"
        ];

        private _configArray = [];
        {
            if (_configData == (_x select 0)) exitWith { _configArray = _x };
        } forEach _configsArray;

        if (_configArray isEqualTo []) then {
            ERROR_1("Could not find a matching configuration for the given classname", _configData);
        } else {
            _configArray params [
                "", // config name
                "", // display name
                ["_markerPrefix", "", [""]],
                ["_markerText", "", [""]],
                ["_markerColor", [0,0,0,0], [[]], [4]],
                ["_markerTexture", "", [""]],
                ["_markerSize", 24, [0]],
                ["_srChannel", 1, [0]],
                ["_mrChannel", 1, [0]],
                ["_lrChannel", 1, [0]],
                "_colorTeamArray"
            ];

            private _newRespawnGroup = createGroup [_factionSide, true]; // explicitly mark for cleanup
            TRACE_2("new group", _factionSide, _newRespawnGroup);

            if (_markerTexture != "") then {
                _newRespawnGroup setVariable [QEGVAR(markers,addMarker), true, true];
                _newRespawnGroup setVariable [QEGVAR(markers,markerText), format ["%1%2", _markerPrefix, _markerText], true];
                _newRespawnGroup setVariable [QEGVAR(markers,markerTexture), _markerTexture, true];
                _newRespawnGroup setVariable [QEGVAR(markers,markerColor), _markerColor, true];
                _newRespawnGroup setVariable [QEGVAR(markers,markerSize), _markerSize, true];
            };

            _newRespawnGroup setVariable [QEGVAR(radios,srChannel), _srChannel, true];
            _newRespawnGroup setVariable [QEGVAR(radios,mrChannel), _mrChannel, true];
            _newRespawnGroup setVariable [QEGVAR(radios,lrChannel), _lrChannel, true];

            _newRespawnGroup setGroupIdGlobal [format ["RG %1: %2 %3", GVAR(groupCount), _callsignPrefix, _markerText]];
            GVAR(groupCount) = GVAR(groupCount) + 1;

            {
                private _unit = _x select 3;

                if !(isNull _unit) then {
                    (_unitsArray select _forEachIndex) params [
                        "", // config name
                        "", // display name
                        ["_unitType", "soldier_f", [""]],
                        ["_unitRank", "private", [""]],
                        ["_unitColorTeamIndex", 0, [0]],
                        ["_isUnitLeader", false, [false]],
                        ["_unitMarkerText", "", [""]],
                        ["_unitMarkerColor", [0,0,0,0], [[]], 4],
                        ["_unitMarkerTexture", "", [""]],
                        ["_unitMarkerSize", 16, [0]]
                    ];

                    [
                        _newRespawnGroup,
                        format ["%1%2", _factionPrefix, _unitType],
                        _position,
                        _colorTeamArray select _unitColorTeamIndex,
                        _unitRank,
                        _isUnitLeader,
                        _srChannel,
                        _mrChannel,
                        _lrChannel,
                        format ["%1%2", _markerPrefix, _unitMarkerText],
                        [_unitMarkerColor, _markerColor] select (_unitMarkerColor isEqualTo [0,0,0,0]),
                        _unitMarkerTexture,
                        _unitMarkerSize
                    ] remoteExecCall [QFUNC(respawnClient), _unit];

                    _position set [0, (_position select 0) + UNIT_SPACING];
                };
            } forEach _newUnits;
        };
        _position set [1, (_position select 1) + UNIT_SPACING];
    };
} forEach GVAR(activeGroups);

[] call FUNC(resetGroupInfo);
