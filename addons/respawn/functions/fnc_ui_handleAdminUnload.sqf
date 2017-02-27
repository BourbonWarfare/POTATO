/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[clientOwner] call FUNC(deregisterClientForUpdates);

[GVAR(adminUpdateEH)] call CBA_fnc_removePerFrameHandler;
GVAR(adminUpdateEH) = nil;

// reset spectate state
if !(GVAR(currentSpecChat) isEqualTo GVAR(oldSpecChat)) then {
    [GVAR(oldSpecChat)] call acre_api_fnc_setSpectator;
};

// reset spectator array
GVAR(currentSpectators) = [];

// set rp highlight
GVAR(mapHighlighted) = objNull;

// save current dropdown config
GVAR(lastFactionIndex) = lbCurSel ADMIN_FACTION_COMBO_IDC;
GVAR(lastGroupIndex) = lbCurSel ADMIN_GROUP_COMBO_IDC;
GVAR(lastConfigIndex) = lbCurSel ADMIN_CONFIG_COMBO_IDC;
