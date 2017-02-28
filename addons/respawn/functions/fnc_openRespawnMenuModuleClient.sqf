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
