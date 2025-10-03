#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function attempts to stop crew from dismounting from a burning vic while
* actively engaging infantry within seconds.
*
*
* Arguments:
* _vehicle - A vehicle suffering a cook-off or engine fire event
* _unit - A unit in a vehicle that should bail out.
*
* Return:
* None
*
* Example:
* [objNull, _unit] call potato_vehicleCoasting_fnc_forgetTargets;
*//***************************************************************************/
params ["", ["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {};

private _targetInfo = _unit targets [true, -1, [], 10];
{
    _unit forgetTarget _x;
} forEach _targetInfo;
