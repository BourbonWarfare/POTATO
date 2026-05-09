#include "..\script_component.hpp"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This fucntion takes a vehicle and unloads all passengers minus the ignored
* units. Ignored units by default are those in the group of the driver, passing
* [objNull] as the second argument is effective in dismounting all units.
*
* Arguments:
* _vic - vehicle to unload
* _ignArr - Units to not dismount the vehicle
*
* Return:
* none
*
* Example:
* [vehicle player] call potato_zeusHC_fnc_unloadCargo;
******************************************************************************/
params [
	["_vic", objNull, [objNull]],
	["_ignArr", [], [[]]]
];
if (isNull _vic || {driver _vic == _vic}) exitWith {};
if (!local _vic) exitWith {
	[_this] remoteExecCall [QFUNC(reinforceUnloadCargo), _vic];
};
if (_ignArr isEqualTo []) then {
	_ignArr = units group driver _vic;
};
private _crew = (crew _vic) - _ignArr;
{
	_x setBehaviour "AWARE";
	unassignVehicle _x;
	_x leaveVehicle _vic;
} forEach (_crew select {!isNull _x});
