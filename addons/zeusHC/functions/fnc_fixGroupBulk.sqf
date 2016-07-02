/*
 * Author: AACO
 * Function used try to "unstick" groups that have become unresponsive
 *
 * Arguments:
 * 0: groups you want to try to fix <ARRAY>
 *
 * Return Value: Nothing
 *
 * Examples:
 * [allGroups] call potato_zeusHC_fnc_fixGroupBulk;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_groups", [], [[]]]
];

{
    [_x] call FUNC(fixGroup);
} forEach _groups;
