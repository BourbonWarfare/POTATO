/*
 * Author: AACO
 * Function to set the potato_zeusHC_addGroupToHC flag on groups.
 * Should only be called through 3DEN
 *
 * Arguments:
 * 0: Group to add flag to <GROUP>
 * 1: Value of flag (true/false) <BOOL>
 *
 * Example:
 * [grp1, true] call potato_zeusHC_fnc_transferSetVar;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_group","_value"];

[{
    params ["_group","_value"];
    (_group) setVariable [QGVAR(addGroupToHC), _value, true];
}, [_group, _value]] call CBA_fnc_execNextFrame;
