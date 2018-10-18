/*
 * Author: AACO
 * Function called when the ARES reinforcement module is placed down
 *
 * Arguments:
 * 0: placed logic object <OBJECT>
 *
 * Return Value:
 * Always returns true <BOOL>
 *
 * Example:
 * [gameLogic] call potato_reinforceToHC_fnc_reinforcementsZeus;
 *
 * Public: No
 */

#include "script_component.hpp"

params["_logic"];
TRACE_1("params",_logic);

if (local _logic) then {
    GVAR(reinforcementLocation) = getPosATL _logic;
    createDialog QGVAR(reinforcement_dialog);
    deleteVehicle _logic;
};
