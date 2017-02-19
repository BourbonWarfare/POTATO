/*
 * Author: AACO
 * Moves and validates a config array of vic classnames to a provided variable array of vic classnames
 *
 * Arguments:
 * 0: Array to store the vic classnames in <ARRAY>
 * 1: Config array to lookup <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [GVAR(carArray), "cars"] call potato_zeusFactory_fnc_addVehiclesToArray;
 * [GVAR(apcArray), "apcs"] call potato_zeusFactory_fnc_addVehiclesToArray;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_storageArray", "_lookup"];

private _arrayToParse = if (isClass (missionConfigFile >> "CfgZeusFactory") && {isArray (missionConfigFile >> "CfgZeusFactory" >> _lookup)}) then {
    getArray (missionConfigFile >> "CfgZeusFactory" >> _lookup)
} else {
    getArray (configFile >> "CfgZeusFactory" >> _lookup)
};

{
    if (isClass (configFile >> "CfgVehicles" >> _x)) then {
        _storageArray pushBack _x;
    } else {
        WARNING_1("Vehicle Classname [%1] does not exist in modset",_x);
    };
} forEach _arrayToParse;

TRACE_1("_storageArray", _storageArray);
