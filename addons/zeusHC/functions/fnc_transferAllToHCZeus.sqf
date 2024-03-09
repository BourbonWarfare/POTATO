#include "script_component.hpp"
/*
 * Author: AACO
 * Function called when the transfer all AI to HC module is placed in zeus
 *
 * Arguments:
 * 0: logic object <OBJECT>
 *
 * Examples:
 * [objLogic] call potato_zeusHC_fnc_transferAllToHCZeus;
 *
 * Public: No
 */

params ["_logic"];
TRACE_1("transferAllToHCZeus",_logic);

if (isNull _logic) exitWith { TRACE_1("Logic for zeus object is somehow null - exiting",_logic); };

[true] spawn FUNC(transferGroupsToHC);

deleteVehicle _logic;
