/*
 * Author: AACO
 * Function to set a unit's team color.
 * Should only be called from the 3DEN workflow
 *
 * Arguments:
 * 0: Unit to assign team <OBJECT>
 * 1: Fireteam color <STRING>
 *
 * Example:
 * [player, 'RED'] call potato_teamColors_fnc_setColor;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);

[{_this remoteExec ["assignTeam"];}, _this, 5] call CBA_fnc_waitAndExecute;
