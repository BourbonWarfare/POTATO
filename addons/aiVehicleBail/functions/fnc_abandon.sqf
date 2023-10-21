/*
 * Author: Dani (TCVM)
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
TRACE_1("abandon",_vehicle);

sleep (random 12);

_vehicle allowCrewInImmobile false;

private _center = getPosASL _vehicle;
TRACE_2("bailing out crew after delay",_vehicle,_center);
{
    [QGVAR(bailOut), [_center, _x, _vehicle], _x] call CBA_fnc_targetEvent;
} forEach crew _vehicle;

