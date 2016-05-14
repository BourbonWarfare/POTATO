/*
 * Author: AACO
 * Function called when the spawn a vic module is placed in zeus
 *
 * Arguments:
 * 0: logic object <OBJECT>
 *
 * Examples:
 * [objLogic] call potato_zeusHC_fnc_spawnAVicZeus;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(vicSpawnLocation) = getPosATL _logic;
    createDialog QGVAR(spawn_a_vic_dialog);
    deleteVehicle _logic;
};
