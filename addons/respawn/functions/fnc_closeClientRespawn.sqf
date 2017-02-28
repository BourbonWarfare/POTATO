/*
 * Author: AACO
 * Closes the client respawn interface
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_closeClientRespawn;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if !(isNull CLIENT_RESPAWN) then {
    closeDialog 1;
};
