#include "../script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function initializes a CBA perframe event handler to slow the run away
* vehicle and eventually stop it all together.
*
* Arguments:
* _vic - The uncontrolled vehicle
*
* Return:
* None
*
* Example:
* [_vic] call FIAGA_lmd_coast_fnc_driverDeathInit;
*//***************************************************************************/
params ["_vic"];
if (speed _vic < 4) exitWith {};

private _eh = [
	FUNC(driverDeathPFEH),
	0.21,
	_this
] call CBA_fnc_addPerFrameHandler;
_vic setVariable [QGVAR(ddPFEH), _eh];
