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

params ["_magazineClassname"];
TRACE_1("params",_magazineClassname);

GVAR(nextReload) = _magazineClassname;
