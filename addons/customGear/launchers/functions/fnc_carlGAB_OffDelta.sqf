#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles increasing airburst offset from laser
*
* Arguments:
* ace self interact menu params
* 0: Increase the offset
*
* Return:
* None
*
* Example:
* [false] call potato_customGear_launchers_fnc_carlGAB_OffDelta;
*//***************************************************************************/
//IGNORE_PRIVATE_WARNING ["_player"];
params [["_increase", false]];
private _distance = _player getVariable [QGVAR(abOffset), 5];
_distance = _distance + ([-5, 5] select _increase);
if (abs _distance > 25) exitWith {
    [format ["Maximum offset (%1m)", _distance - ([-5, 5] select _increase)], true, 5, 2] call ACEFUNC(common,displayText);
};
_player setVariable [QGVAR(abOffset), _distance];
[format ["Offset to laser set to %1m", _distance], true, 5, 2] call ACEFUNC(common,displayText);
