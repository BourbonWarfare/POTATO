/*
 * Author: BadWolf
 * Function called to update the checklistMaster everytime that a selection is changed in a ListBox.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateSelectionLB;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control", "_selectedIndex"];
