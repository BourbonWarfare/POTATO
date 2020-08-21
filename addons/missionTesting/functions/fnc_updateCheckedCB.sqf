/*
 * Author: BadWolf
 * Function is called by a control EH everytime that a CB is changed in the checklist.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateCheckedCB;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control", "_checked"];

