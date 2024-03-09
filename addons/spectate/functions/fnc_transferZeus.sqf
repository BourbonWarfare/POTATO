/*
 * Author: AACO
 * Function used to update the player list focus
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_updateListFocus;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    ["_newUnit", objNull, [objNull]],
    ["_zeusModule", objNull, [objNull]]
];

if (isNull _newUnit || isNull _zeusModule) exitWith { WARNING_2("Null parameters",_newUnit,_zeusModule); };

unassignCurator _zeusModule;
waitUntil {isNull (getAssignedCuratorUnit _zeusModule)};
_newUnit assignCurator _zeusModule;
