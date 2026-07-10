#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles toggling airburst enable
*
* Arguments:
* ace self interact menu params
*
* Return:
* None
*
* Example:
* [] call potato_customGear_launchers_fnc_carlGAB_Toggle;
*//***************************************************************************/
//IGNORE_PRIVATE_WARNING ["_player"];
params [["_increase", false]];
private _burst = _player getVariable [QGVAR(abCGRnd), false];
_burst = !_burst;
[format ["Airburst HE programming %1.", ["DISABLED", "ENABLED"] select _burst], true, 5, 2] call ACEFUNC(common,displayText);
_player setVariable [QGVAR(abCGRnd), _burst];
