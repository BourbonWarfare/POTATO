/*
 * Load map marker configuration from given configuration file.
 *
 * Arguments:
 * 0: Configuration File (default: missionConfigFile) <CONFIG>
 *
 * Return Value:
 * Nothing
 */

#include "script_component.hpp"

params [["_configFile", missionConfigFile]];

private _configrationPath = _configFile >> QGVAR(Configuration);

// If no configuration is available, fail early
if (!isClass _configrationPath) exitWith {};

// Extract base settings
GVAR(enabled) = [_configrationPath >> "enabled"] call BIS_fnc_getCfgDataBool;
private _updateRate = [_configrationPath >> "updateRate"] call BIS_fnc_getCfgData;
GVAR(updateRate) = if (isNil "_updateRate") then {GVAR(updateRate)} else {_updateRate};

// Extract visibility
private _visibilityPath = _configrationPath >> QUOTE(Visibility);

for "_visibilityIndex" from 0 to ((count _visibilityPath) - 1) do {
    private _visibilitySide = _visibilityPath select _visibilityIndex;
    private _sideName = configName _visibilitySide;
    private _visibleForSide = [];
    for "_sideIndex" from 0 to ((count _visibilitySide) - 1) do {
        _visibleForSide pushBack (configName (_visibilitySide select _sideIndex));
    };

    [GVAR(factionVisibilitySettings), _sideName, _visibleForSide] call EFUNC(datastructures,map_put);
};

// Define DRY helper function to extract marker settings from config class
private _fnc_getMarkerSettingsFromClass = {
    params ["_config"];
    [
        [_config >> "icon"] call BIS_fnc_getCfgData,
        [_config >> "color"] call BIS_fnc_getCfgData,
        [_config >> "size"] call BIS_fnc_getCfgData,
        [_config >> "displayText"] call BIS_fnc_getCfgDataBool
    ]
};

// Extract groups
private _groupsPath = _configrationPath >> QUOTE(Groups);

for "_groupsIndex" from 0 to ((count _groupsPath) - 1) do {
    private _group = _groupsPath select _groupsIndex;
    private _groupName = configName _group;
    private _groupData = [_group] call _fnc_getMarkerSettingsFromClass;

    [GVAR(groupMarkerSettings), _groupName, _groupData] call EFUNC(datastructures,map_put);
};

// Extract units
private _unitsPath = _configrationPath >> QUOTE(Units);

for "_groupsIndex" from 0 to ((count _groupsPath) - 1) do {
    private _unit = _groupsPath select _groupsIndex;
    private _unitName = configName _group;
    private _unitData = [_unit] call _fnc_getMarkerSettingsFromClass;

    [GVAR(unitMarkerSettings), _unitName, _unitData] call EFUNC(datastructures,map_put);
};
