/*
 * Author: AACO
 * Opens the admin wave respawn tool
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_openAdminRespawn;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// only allow one screen open at once
if (isNull ADMIN_RESPAWN && isNull CLIENT_RESPAWN) then {
    createDialog QGVAR(adminRespawn);
};
