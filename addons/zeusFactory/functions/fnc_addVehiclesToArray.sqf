#include "script_component.hpp"
/*
 * Author: AACO
 * Moves and validates a config array of vic classnames to a provided variable array of vic classnames
 *
 * Arguments:
 * 0: Array to store the vic classnames in (modified by reference) <ARRAY>
 * 1: Config array to lookup <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [GVAR(carArray), "cars"] call potato_zeusFactory_fnc_addVehiclesToArray;
 * [GVAR(apcArray), "apcs"] call potato_zeusFactory_fnc_addVehiclesToArray;
 */

params ["_storageArray", "_lookup"];
TRACE_2("addVehiclesToArray",_storageArray,_lookup);

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
TRACE_1("",count _storageArray);

// Add vehicles from autoModule in zeusHC
// Lots of refinement could be done here (side-specific, check crew size)
private _zeusAutoVics = missionNamespace getVariable [QEGVAR(zeusHC,vehicleList), []];
{
    _x params ["_type"];
    if ((_storageArray findIf {_x == _type}) == -1) then { // avoid duplicates (case-insensitive)
        if (_type isKindOf "Plane") exitWith {};
        if (_type isKindOf "Ship") exitWith {};
        if (_type isKindOf "Helicopter") exitWith { // note: pularality (helicopters/Helicopter)s
            if (_lookup == "helicopters") then { _storageArray pushBack _type; };
        };
        if ((_type isKindOf "Wheeled_APC") || {_type isKindOf "Wheeled_APC_F"} || {_type isKindOf "Tank"}) exitWith { 
            if (_lookup == "apcs") then { _storageArray pushBack _type; };
        };
        if (_lookup == "cars") then { _storageArray pushBack _type; };
    };
} forEach _zeusAutoVics;
TRACE_1("",count _storageArray);
