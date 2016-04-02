/*
 * Author: PabstMirror
 * 
 *
 * Arguments:
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call 
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh"];
TRACE_1("params",_mortarVeh);

[_mortarVeh] call FUNC(levelToGround);
