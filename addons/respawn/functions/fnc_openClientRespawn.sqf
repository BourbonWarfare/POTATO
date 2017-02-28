/*
 * Author: AACO
 * Opens the client respawn tool
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_openClientRespawn;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

createDialog QGVAR(clientRespawn);
