/*
 * Author: AACO
 * handles the load of the admin wave respawn tool. Will validate authorization
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_ui_handleAdminLoad;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// build caches if needed
if (isNil QGVAR(factionsToInfo)) then {
    [] call FUNC(readConfigToVariables);
};

// get spectator chat status
GVAR(oldSpecChat) = [] call acre_api_fnc_isSpectator;
GVAR(currentSpecChat) = GVAR(oldSpecChat);

// set rp highlight
GVAR(mapHighlighted) = objNull;

// set spectator array
GVAR(currentSpectators) = [];

// wait until the dialog is created
waitUntil {dialog};

params ["_display"];
private _ctrlNoMarkerFrame = _display ctrlCreate ["RscText", -1];
private _ctrlNoMarkerCheckBox = _display ctrlCreate ["RscCheckBox", ADMIN_NOMARKERS_IDC];

_ctrlNoMarkerFrame ctrlSetPosition [0.62 * safezoneW + safezoneX, 0.22 * safezoneH + safezoneY, 0.11 * safezoneW, 0.05 * safezoneH];
_ctrlNoMarkerFrame ctrlCommit 0;
_ctrlNoMarkerFrame ctrlSetText "No Markers";

_ctrlNoMarkerCheckBox ctrlSetPosition [0.69 * safezoneW + safezoneX, 0.23 * safezoneH + safezoneY, 0.02 * safezoneW, 4/3 * 0.02 * safezoneW];
_ctrlNoMarkerCheckBox ctrlCommit 0;
_ctrlNoMarkerCheckBox ctrlSetTooltip "Secret Respawn";
_ctrlNoMarkerCheckBox cbSetChecked (missionNamespace getVariable [QGVAR(noMarkers), false]);
_ctrlNoMarkerCheckBox ctrlAddEventHandler ["CheckedChanged", {
    params ["", "_checked"];
    _checked = [false, true] select _checked;
    missionNamespace setVariable [QGVAR(noMarkers), _checked, true];
    systemChat format ["Respawn No-Markers: %1", _checked];
}];


// validate user
if (!([] call EFUNC(core,isAuthorized)) && !(ZEUS_ENABLED && !((getPlayerUID player) in BLACK_LIST_UIDS) && profileNamespace getVariable [EULA_CHECK, false])) exitWith {
    WARNING("Not authorized for respawn");
    [] call FUNC(closeAdminRespawn);
};

// hide stage 2 spawn map
ctrlShow [ADMIN_MAP_IDC, false];
[] call FUNC(updateChatButton);
[] call FUNC(updateOpenButton);

// get count of players on each faction so we don't respawn on the wrong side
private _allFactions = createHashMap; 
{ 
    if (isPlayer _x) then { 
        private _faction = faction _x; 
        _allFactions set [_faction, 1 + (_allFactions getOrDefault [_faction, 0])]; 
    }; 
} forEach allUnits;

{
    (GVAR(factionsToInfo) getVariable _x) params ["_displayName", "", "_factionClassname"];
    private _count = _allFactions getOrDefault [_factionClassname, 0];
    if (_count > 0) then { _displayName = _displayName + format [" [%1]", _count]; };

    private _index = lbAdd [ADMIN_FACTION_COMBO_IDC, _displayName];
    if (isText (configfile >> "CfgFactionClasses" >> _factionClassname >> "icon")) then {
        lbSetPicture [ADMIN_FACTION_COMBO_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _factionClassname >> "icon")];
    };
    lbSetData [ADMIN_FACTION_COMBO_IDC, _index, _x];
} forEach (allVariables GVAR(factionsToInfo));

private _factionIndex = if (isNil QGVAR(lastFactionIndex)) then {
    0
} else {
    GVAR(lastFactionIndex)
};
lbSetCurSel [ADMIN_FACTION_COMBO_IDC, _factionIndex];
[ADMIN_FACTION_COMBO, _factionIndex] call FUNC(ui_handleFactionChange);

private _groupIndex = if (isNil QGVAR(lastGroupIndex)) then {
    0
} else {
    GVAR(lastGroupIndex)
};
lbSetCurSel [ADMIN_GROUP_COMBO_IDC, _groupIndex];
[ADMIN_GROUP_COMBO, _groupIndex] call FUNC(ui_handleGroupChange);

private _configIndex = if (isNil QGVAR(lastConfigIndex)) then {
    0
} else {
    GVAR(lastConfigIndex)
};
lbSetCurSel [ADMIN_CONFIG_COMBO_IDC, _configIndex];

GVAR(adminUpdateEH) = [FUNC(ui_updateAdminUI), 0.25] call CBA_fnc_addPerFrameHandler;

[clientOwner] call FUNC(registerClientForUpdates);
