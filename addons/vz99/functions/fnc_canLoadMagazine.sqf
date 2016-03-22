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

private _baseMag = getText (configFile >> "CfgMagazines" >> _magazineClassname >> QGVAR(base));
TRACE_2("",_magazineClassname,_baseMag);

_baseMag in (magazines ace_player)
