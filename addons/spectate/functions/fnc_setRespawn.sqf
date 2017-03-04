/*
 * Author: AACO
 * Function used to toggle the respawn portion of the UI
 *
 * Arguments:
 * 0: Enable respawn button <BOOL>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [true] call potato_spectate_fnc_setRespawn;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_open", false, [false]]];

RESPAWN ctrlSetFade ([1, 0] select _open);
RESPAWN ctrlEnable _open;
RESPAWN ctrlCommit 0.25;
