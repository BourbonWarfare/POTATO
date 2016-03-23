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

systemChat format ["switching to %1", _magazineClassname];
GVAR(nextReload) = _magazineClassname;
