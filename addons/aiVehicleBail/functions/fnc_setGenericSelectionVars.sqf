/*
 * Author: Brandon (TCVM)
 * Adds generic variables to the vehicle
 *
 * Arguments:
 * 0: The vehicle in which to add variables
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] call potato_aiVehicleBail_setGenericSelectionVars;
 *
 * Public: No
 */
#include "script_component.hpp"
params["_vehicle"];

_vehicle allowCrewInImmobile true;

private _hitPoint = "";

_hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitEngine" >> "Name");
_vehicle setVariable [QGVAR(engine_name), _hitPoint, true];

_hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitHull" >> "Name");
_vehicle setVariable [QGVAR(hull_name), _hitPoint, true];

_hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "Turrets" >> "MainTurret" >> "HitPoints" >> "HitGun" >> "Name");
_vehicle setVariable [QGVAR(gun_name), _hitPoint, true];

_hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "Turrets" >> "MainTurret" >> "HitPoints" >> "HitTurret" >> "Name");
_vehicle setVariable [QGVAR(turret_name), _hitPoint, true];

_vehicle setVariable [QGVAR(can_move), true, true];
_vehicle setVariable [QGVAR(can_shoot), true, true];

