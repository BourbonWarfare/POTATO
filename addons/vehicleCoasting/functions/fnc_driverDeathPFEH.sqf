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
_arguments params ["_vic"];
private _spd = abs speed _vic;
if (isNull _vic ||
	_spd < 1 ||
	!(brakesDisabled _vic) ||
	{_vic getVariable QGVAR(ddETime) < CBA_missionTime}) exitWith {
    TRACE_2("exitPFEH",_spd,_vic);
    #ifdef DEBUG_MODE_FULL
	diag_log text ("null:" + str (isNull _vic) + " spd:" + str _spd);
    #endif
    #ifdef DEBUG_MODE_DRAW_EH
    GVAR(dev_traceHash) deleteAt str _vic;
    #endif
	_vic disableBrakes false;
	_handle call CBA_fnc_removePerFrameHandler;
	_vic sendSimpleCommand "KEY DOWN";
};
if (_vic getVariable [QGVAR(ddLImp), -1] > CBA_missionTime) exitWith {
#ifdef DEBUG_MODE_FULL
	diag_log text ("skipped " + str _vic + ": " + str (_vic getVariable [QGVAR(ddLImp), -1]));
#endif
};
/*if (_spd < 15 + random 10 && count (crew _vic select {!isPlayer _x && alive _x}) > 0) then {
    private _randValue = linearConversion [15, 30, _spd, 0.8, 0, true];
    {
        if (_randValue < random 1) then {
            unassignVehicle _x;
            _x leaveVehicle _vic;
            _x action ["eject", _vic];
        };
    } forEach crew _vic;
};*/
//private _force = _vic vectorModelToWorld [0, 1, 0];
_vic setVariable [QGVAR(ddLImp), CBA_missionTime + 0.2];