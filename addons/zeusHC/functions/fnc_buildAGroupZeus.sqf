/*
 * Author: AACO
 * Function called when the build a group module is placed in zeus
 *
 * Arguments:
 * 0: logic object <OBJECT>
 *
 * Examples:
 * [objLogic] call potato_zeusHC_fnc_buildAGroupZeus;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(buildSpawnLocation) = getPosATL _logic;
    createDialog QGVAR(build_a_group_dialog);
};

deleteVehicle _logic;
