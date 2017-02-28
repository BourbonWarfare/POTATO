/*
 * Author: AACO
 * Client function to clear the group tree when the server clears the master group
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_resetGroupInfoClient;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

tvClear GROUP_TREE_IDC;
