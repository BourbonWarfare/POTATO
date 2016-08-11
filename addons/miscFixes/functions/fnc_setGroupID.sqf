/*
 * Author: AACO
 * Sets callsign (groupID) on a global level. (Hopefully BIS will fix this eventually)
 *
 * Arguments:
 * 0: Group <GROUP>
 * 1: Value <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [grp1, "This is Group 1"] call potato_miscFixes_fnc_setGroupID;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[
    {
        params ["_group","_value"];
        _group setGroupIdGlobal [_value];
    },
    _this,
    0
] call CBA_fnc_waitAndExecute;
