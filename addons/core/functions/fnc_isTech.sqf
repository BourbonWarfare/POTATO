/*
 * Author: PabstMirror
 * Function used see if the local player is in the authorized list or logged in as admin
 *
 * Return Value:
 * True if player is the logged in admin, or in the authorized player tech list <BOOL>
 *
 * Example:
 * [] call potato_core_fnc_isTech
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if !(hasInterface) exitWith { false };

isServer ||
GVAR(playerTech) ||
{serverCommandAvailable "#kick"}
