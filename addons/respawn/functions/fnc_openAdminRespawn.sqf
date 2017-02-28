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

createDialog QGVAR(adminRespawn);
