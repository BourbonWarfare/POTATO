/*
 * Author: AACO
 * Function used to create a cache of spawnable units
 *
 * Example:
 * [] call potato_zeusHC_fnc_garrisonCache;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// create new cache
GVAR(garrisonCache) = [[],[]];

// define private helper method
private _addToCache = {
    TRACE_1("Params",_this);
    params ["_configFile"];

    private _configs = "true" configClasses (_configFile >> "CfgGarrison");
    {
        if (!((configName _x) in (GVAR(garrisonCache) select 0)) && (isArray (_x >> "units"))) then {
            (GVAR(garrisonCache) select 0) pushBack (configName _x);
            (GVAR(garrisonCache) select 1) pushBack (getArray (_x >> "units"));
        };
        nil
    } count _configs;
};


[missionConfigFile] call _addToCache; // look through mission config for setup
[configFile] call _addToCache; // look through the default config for any factions not defined
