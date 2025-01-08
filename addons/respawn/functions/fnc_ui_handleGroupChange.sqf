/*
 * Author: AACO
 * Handles a change in group
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleGroupChange;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["", "_index"];

private _lookUp = lbData [ADMIN_GROUP_COMBO_IDC, _index];
(GVAR(groupsToInfo) get _lookUp) params ["", "_units", "_configurations"];

// agressively look ahead into the units for a leader marker/color
private _unitMarkerColor = [0,0,0,0];
private _unitMarkerTexture = "";

{
    _x params [
        "", // config name
        "", // display name
        "", // type
        "", // rank
        "", // color team
        ["_isLeader", false, [false]],
        "", // marker text
        ["_markerColor", [0,0,0,0], [[]], 4],
        ["_markerTexture", "", [""]]
    ];

    if (_isLeader) exitWith {
        if (_markerTexture != "") then {
            _unitMarkerColor = _markerColor;
            _unitMarkerTexture = _markerTexture;
        };
    };
} forEach _units;

lbClear ADMIN_CONFIG_COMBO_IDC;

{
    _x params [
        ["_configName", "", [""]],
        ["_displayName", "", [""]],
        "", // marker prefix
        "", // marker text
        ["_markerColor", [0,0,0,0], [[]], 4],
        ["_markerTexture", "", [""]]
    ];

    private _index = lbAdd [ADMIN_CONFIG_COMBO_IDC, _displayName];

    // if the configuration marker texture is blank, look at the units
    if (_markerTexture == "") then {
        if (_unitMarkerTexture != "") then {
            _markerTexture = _unitMarkerTexture;
        };

        if (_unitMarkerColor isNotEqualTo [0,0,0,0]) then {
            _markerColor = _unitMarkerColor;
        };
    };

    lbSetPicture [ADMIN_CONFIG_COMBO_IDC, _index, _markerTexture];
    lbSetPictureColor [ADMIN_CONFIG_COMBO_IDC, _index, _markerColor];
    lbSetPictureColorSelected [ADMIN_CONFIG_COMBO_IDC, _index, _markerColor];
    lbSetData [ADMIN_CONFIG_COMBO_IDC, _index, [_configName, _markerColor joinString ","] joinString ";"];
} forEach _configurations;
