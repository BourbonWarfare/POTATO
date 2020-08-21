/*
 * Author: BadWolf
 * Function is called by a control EH everytime that a multiEdit box is exited by the used.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateNotesFlag;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control"];

//Get idc from control and then get text, copy it to array and store.
