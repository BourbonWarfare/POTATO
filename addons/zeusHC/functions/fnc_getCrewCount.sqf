/*
 * Author: AACO
 * Function to get the number of crew slots in a vehicle
 *
 * Arguments:
 * 0: Vehicle to get the crew count of <OBJECT>
 *
 * Return Value:
 * Crew count <NUMBER>
 *
 * Example:
 * [tonk] call potato_zeusHC_fnc_getCrewCount;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_vehicle"];

{(_x select 2) == -1} count (fullCrew [_vehicle, "", true])
