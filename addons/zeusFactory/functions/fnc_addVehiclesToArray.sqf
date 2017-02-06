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
