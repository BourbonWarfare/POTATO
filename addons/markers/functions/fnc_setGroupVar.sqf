/*
 * Author: AACO
 * Function to set marker vars on groups
 * Should only be called through 3DEN
 *
 * Arguments:
 * 0: Group to add attributes to <GROUP>
 * 1: Value of attribute <ANY>
 * 2: Variable of the attribute <STRING>
 *
 * Example:
 * [grp1, true, "potato_markers_addMarker"] call potato_markers_fnc_setGroupVar;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_group","_value","_var"];

[{
    params ["_group","_value","_var"];
    _group setVariable [_var,_value,true];
}, [_group, _value,_var]] call CBA_fnc_execNextFrame;
