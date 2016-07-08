/*
 * Author: AACO
 * Function used to ungarrison a group, group must be local
 *
 * Arguments:
 * 0: group you want to ungarrison (must be local) <GROUP>
 *
 * Return Value: Nothing
 *
 * Examples:
 * [group player] call potato_zeusHC_fnc_ungarrisonGroup;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_group", grpNull, [grpNull]]
];

// if the group is not local, exit
if (isNull _group || !(local _group)) exitWith { ERROR("Group is null/not local, can not ungarrison"); };

// unset any doWatches, remove VCOM garrisoned flag
{
    _x doWatch objNull;
    _x doMove (getPos _x);
    _x setVariable ["potato_aiFrameworks_vcom_garrisoned", false];
} forEach (units _group);
