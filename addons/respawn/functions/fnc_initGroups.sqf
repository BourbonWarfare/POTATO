/*
 * Author: AACO
 * After getting the initial batch of groups, add them to the client's tree
 *
 * Arguments:
 * 0: Array of all current groups <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [[]] call potato_respawn_fnc_initGroups;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [["_groups", [], [[]]]];

{
    _x call FUNC(addGroupClient);
} forEach _groups;
