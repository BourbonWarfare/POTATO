/*
 * Author: Dani (TCVM)
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

private _eh = _vehicle getVariable[QGVAR(handle_damage), nil];
if (isNil "_eh") then {
    _vehicle setVariable [QGVAR(handle_damage), _vehicle addEventHandler["HandleDamage", {
        params ["_vehicle", "", "_damage", "_injurer", "_projectile", "_hitIndex", "", "_hitPoint"];
        private _newDamage = _damage - (_vehicle getHitIndex _hitIndex);
        [LINKFUNC(handleVehicleDamage), [_vehicle, _hitPoint, _hitIndex, _injurer, _vehicle getHitIndex _hitIndex, _newDamage, _projectile]] call CBA_fnc_execNextFrame;
        _damage
    }]];
};

