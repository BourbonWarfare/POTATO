/*
 * Author: AACO
 * Close the admin respawn tool
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_closeAdminRespawn;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if !(isNull ADMIN_RESPAWN) then {
    closeDialog 1;
};
