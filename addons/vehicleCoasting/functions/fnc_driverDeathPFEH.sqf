#include "../script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is the PFEH handler that handles both the slowing and eventual
* stopping of the uncontrolled vehicle the event handler is attached to
*
* Arguments:
* _arguments - An array containing (Array):
*		_vic - The uncontrolled vehicle (Object)
*		_center - Center of mass of _vic (Array)
*		_mass - Base scale for slowing force (number)
* _handle - The handle of the PFEH (number)
*
* Return:
* None
*
* Example:
* [_vic] call lmd_coast_fnc_driverDeathInit;
*//***************************************************************************/

params ["_arguments", "_handle"];
_arguments params ["_vic", "_center", "_mass"];
private _spd = abs speed _vic;

if (isNull _vic ||
	_spd < 1 ||
	!(brakesDisabled _vic) ||
	{_vic getVariable QGVAR(ddETime) <= CBA_missionTime}) exitWith {
    TRACE_2("exitPFEH")
#ifdef DEBUG_MODE_FULL
	diag_log text ("null:" + str (isNull _vic) + " spd:" + str _spd);
#endif
	_vic disableBrakes false;
	_handle call CBA_fnc_removePerFrameHandler;
	_vic sendSimpleCommand "KEY DOWN";
};
if (_vic getVariable [QGVAR(ddLImp), -1] > CBA_missionTime) exitWith {
#ifdef DEBUG_MODE_FULL
	systemChat ("skipped " + str _vic + ": " + str (_vic getVariable [QGVAR(ddLImp), -1]));
#endif
};

//private _force = _vic vectorModelToWorld [0, 1, 0];
private _force = vectorNormalized velocity _vic;
if (_spd < 10) then {
	_force = _force vectorMultiply -12.5 * _mass;
} else {
	_force = _force vectorMultiply -1 * _mass;
};
_vic addForce [_force, _center];
_vic setVariable [QGVAR(ddLImp), CBA_missionTime + 0.2];