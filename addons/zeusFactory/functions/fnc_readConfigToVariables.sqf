/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// parse car info
GVAR(carArray) = [];
[GVAR(carArray), "cars"] call FUNC(addVehiclesToArray);

GVAR(apcArray) = [];
[GVAR(apcArray), "apcs"] call FUNC(addVehiclesToArray);

GVAR(helicopterArray) = [];
[GVAR(helicopterArray), "helicopters"] call FUNC(addVehiclesToArray);

TRACE_3("vars", GVAR(carArray), GVAR(apcArray), GVAR(helicopterArray));
