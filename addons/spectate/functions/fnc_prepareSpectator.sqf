/*
 * Author: AACO
 * Function used to prepare the spectator unit on all computer
 *
 * Arguments:
 * 0: unit to prepare <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_prepareSpectator;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_unit", objNull, [objNull]]];

if !(isNull _unit) then {
    _unit enableSimulation false;
    _unit allowDamage false;
    _unit setVariable [QACEGVAR(medical,allowDamage), false];
    _unit setVariable [QGVAR(timeOfDeath), CBA_missionTime];
};
