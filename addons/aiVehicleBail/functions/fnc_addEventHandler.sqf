/*
 * Author: Brandon (TCVM)
 * Adds the event handler to a vehicle
 *
 * Arguments:
 * 0: The vehicle in which to add the event handler to
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] call potato_aiVehicleBail_fnc_addEventHandler;
 *
 * Public: No
 */
#include "script_component.hpp"
params["_vehicle"];

_vehicle allowCrewInImmobile true;

if !(GVAR(enableCrewBailing)) exitWith {};

private _eh = _vehicle getVariable[QGVAR(handle_damage), nil];
if (isNil "_eh") then {
    _vehicle setVariable [QGVAR(handle_damage), _vehicle addEventHandler["HandleDamage", {
        params ["_vehicle", "", "_damage", "_injurer", "", "_hitIndex", "", "_hitPoint"];
        [LINKFUNC(handleVehicleDamage), [_vehicle, _hitPoint, _hitIndex, _injurer]] call CBA_fnc_execNextFrame;
        _damage
    }]];
    
    _vehicle setVariable [QGVAR(can_move), true];
    _vehicle setVariable [QGVAR(can_shoot), true];
};

