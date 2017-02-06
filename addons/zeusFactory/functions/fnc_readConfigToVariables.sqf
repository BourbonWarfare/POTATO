/*
 * Author: AACO
 * Should only be run once per mission,
 * stores zeusFaction vehicle information into GVARs so we can easily access them
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_zeusFactory_fnc_readConfigToVariables;
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
