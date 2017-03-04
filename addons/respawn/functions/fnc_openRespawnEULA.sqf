/*
 * Author: AACO
 * Opens the wave respawn tool EULA
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_openRespawnEULA;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

createDialog QGVAR(respawnEULA);
