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

// validate user
if (!([] call EFUNC(core,isAuthorized)) && !(ZEUS_ENABLED && !((getPlayerUID player) in BLACK_LIST_UIDS) && profileNamespace getVariable [EULA_CHECK, false])) exitWith {
    WARNING("Not authorized for respawn");
    [] call FUNC(closeAdminRespawn);
};

// hide stage 2 spawn map
ctrlShow [ADMIN_MAP_IDC, false];
[] call FUNC(updateChatButton);
[] call FUNC(updateOpenButton);

{
    (GVAR(factionsToInfo) getVariable _x) params ["_displayName", "", "_factionClassname"];
    private _index = lbAdd [ADMIN_FACTION_COMBO_IDC, _displayName];
    if (isText (configfile >> "CfgFactionClasses" >> _factionClassname >> "icon")) then {
        lbSetPicture [ADMIN_FACTION_COMBO_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _factionClassname >> "icon")];
    };
    lbSetData [ADMIN_FACTION_COMBO_IDC, _index, _x];
} forEach (allVariables GVAR(factionsToInfo));

private _factionIndex = if !(isNil QGVAR(lastFactionIndex)) then {
    GVAR(lastFactionIndex)
} else {
    0
};
lbSetCurSel [ADMIN_FACTION_COMBO_IDC, _factionIndex];
[ADMIN_FACTION_COMBO, _factionIndex] call FUNC(ui_handleFactionChange);

private _groupIndex = if !(isNil QGVAR(lastGroupIndex)) then {
    GVAR(lastGroupIndex)
} else {
    0
};
lbSetCurSel [ADMIN_GROUP_COMBO_IDC, _groupIndex];
[ADMIN_GROUP_COMBO, _groupIndex] call FUNC(ui_handleGroupChange);

private _configIndex = if !(isNil QGVAR(lastConfigIndex)) then {
    GVAR(lastConfigIndex)
} else {
    0
};
lbSetCurSel [ADMIN_CONFIG_COMBO_IDC, _configIndex];

GVAR(adminUpdateEH) = [FUNC(ui_updateAdminUI), 0.25] call CBA_fnc_addPerFrameHandler;

[clientOwner] call FUNC(registerClientForUpdates);
