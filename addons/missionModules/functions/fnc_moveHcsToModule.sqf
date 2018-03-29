/*
 * Author: AACO
 * Function called when the move headless clients to a zeus module position
 *
 * Arguments:
 * 0: logic object <OBJECT>
 *
 * Examples:
 * [objLogic] call potato_missionModules_fnc_moveHcsToModule;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_logic", objNull, [objNull]]];
if (isNull _logic) exitWith { TRACE_1("Logic for zeus object is somehow null, exiting"); };

[getPos _logic] call FUNC(moveHcsToPos);

deleteVehicle _logic;
