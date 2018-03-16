/*
 * Author: AACO
 * Function called when the move headless clients to a position
 *
 * Arguments:
 * 0: position <ARRAY>
 *
 * Examples:
 * [[0,0,0]] call potato_missionModules_fnc_moveHcsToPos;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_pos", [0,0,0], [[]], [2, 3]]];

missionNamespace setVariable [QEGVAR(miscFixes,updateHCPosition), false, true];
{
    _x setPos _pos;
} forEach ((entities "HeadlessClient_F") select {isPlayer _x});
