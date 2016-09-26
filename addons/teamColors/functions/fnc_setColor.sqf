/*
 * Author: AACO
 * Function to set a unit's team color.
 *
 * Arguments:
 * 0: Unit to assign team <OBJECT>
 *
 * Example:
 * [player] call potato_teamColors_fnc_setColor;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("Params",_this);

[{
    params ["_unit", "_fireteam"];
    _unit assignTeam _fireteam;
}, _this, 1] call CBA_fnc_waitAndExecute;
