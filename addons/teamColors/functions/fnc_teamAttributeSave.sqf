/*
 * Author: AACO
 * Function to save a unit's team color to a stored value in the mission sqm.
 * Should only be called from the 3DEN workflow
 *
 * Arguments:
 * 0: Control group of the team color component <CONTROL>
 *
 * Example:
 * [control] call potato_teamColors_fnc_teamAttributeSave;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_2("params",_this,_this getVariable QGVAR(selectedColor));

[TEAM_COLORS] select (_this getVariable [QGVAR(selectedColor),0]);
