/*
 * Author: AACO
 * Function used to start the spectate script
 * Should only be called from respawn template onPlayerRespawn
 *
 * Arguments:
 * 0: Old unit <OBJECT>
 * 1: New unit <OBJECT>
 * 2: Respawn type https://community.bistudio.com/wiki/Arma_3_Respawn#Respawn_Types <NUMBER>
 * 3: Respawn delay <NUMBER>
 *
 * Examples:
 * [] call potato_spectate_fnc_init;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL // debug left on for a raisin
#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    ["_newUnit", objNull, [objNull]],
    ["_oldUnit", objNull, [objNull]],
    ["_respawnType", 1, [0]],
    ["_respawnDelay", 0, [0]]
];

[FUNC(setup), _this, _respawnDelay] call CBA_fnc_waitAndExecute;
