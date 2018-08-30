/*
 * Author: Brandon (TCVM)
 * Returns the type of part from a generic list
 *
 * Arguments:
 * 0: The vehicle
 * 1: The selection which got hit
 *
 * Return Value:
 * Type of part
 *
 * Example:
 * [tank1, "Hit_Engine"] call potato_aiVehicleBail_determineGenericSelectionType
 *
 *
 * Public: No
 */
#include "script_component.hpp"

params["_vehicle", "_selection"];

private _type = "exit";

switch (true) do {
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(engine_name))):         { _type = "engine" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(hull_name))):           { _type = "hull" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(gun_name))):            { _type = "turret" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(turret_name))):         { _type = "turret" };
    default { _type = "exit"; }
};

_type

