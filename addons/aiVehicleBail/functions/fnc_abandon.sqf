/*
 * Author: Brandon (TCVM)
 * Forces the AI currently in a vehicle to bail out
 *
 * Arguments:
 * 0: The vehicle in which to bail out
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] spawn potato_aiVehicleBail_fnc_abandon;
 *
 * Public: No
 */
#include "script_component.hpp"

params["_vehicle"];

sleep (random 12);

_vehicle allowCrewInImmobile false;

private _center = getPosASL _vehicle;

{
    [QGVAR(bailOut), [_center, _x, _vehicle], _x] call CBA_fnc_targetEvent;
} forEach crew _vehicle;

