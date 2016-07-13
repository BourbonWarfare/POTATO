/*
 * Author: AACO
 * Function used used to ungarrison an array of groups, the groups must be local
 *
 * Arguments:
 * 0: groups you want to ungarrison (must be local) <ARRAY>
 *
 * Return Value: Nothing
 *
 * Examples:
 * [allGroups] call potato_zeusHC_fnc_ungarrisonGroupBulk;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_groups", [], [[]]]
];

{
    [_x] call FUNC(ungarrisonGroup);
} forEach _groups;
