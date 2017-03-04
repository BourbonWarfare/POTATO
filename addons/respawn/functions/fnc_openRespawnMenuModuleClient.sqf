/*
 * Author: AACO
 * If the player is authorized, opens the respawn screen,
 * if they still need to accept the eula it directs them there,
 * otherwise it does nothing
 * Should only be called from the zeus module workflow
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_OpenRespawnMenuModuleClient;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if ([] call EFUNC(core,isAuthorized)) then {
    [] call FUNC(openAdminRespawn);
} else {
    if (ZEUS_ENABLED && {!((getPlayerUID player) in BLACK_LIST_UIDS)}) then {
        if (profileNamespace getVariable [EULA_CHECK, false]) then {
            [] call FUNC(openAdminRespawn);
        } else {
            [] call FUNC(openRespawnEULA);
        };
    };
};
