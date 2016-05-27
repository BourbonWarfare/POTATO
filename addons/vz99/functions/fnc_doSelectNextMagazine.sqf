/*
 * Author: PabstMirror
 * Selects the next magazine to load.
 *
 * Arguments:
 * 0: Magazine Classname <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * ["potato_vz99_he"] call potato_vz99_fnc_doSelectNextMagazine
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_magazineClassname"];
TRACE_1("params",_magazineClassname);

GVAR(nextReload) = _magazineClassname;

