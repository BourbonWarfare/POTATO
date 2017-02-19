/*
 * Author: AACO
 * Function to load a unit's team color from a stored value in the mission sqm.
 * Should only be called from the 3DEN workflow
 *
 * Arguments:
 * 0: Control group of the team color component <CONTROL>
 * 1: Fireteam color <STRING>
 *
 * Example:
 * [control, 'RED'] call potato_teamColors_fnc_teamAttributeLoad;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlGroup","_value"];

(_ctrlGroup controlsGroupCtrl TEAM_COLOR_IDC) lbSetCurSel ([TEAM_COLORS] find _value);
