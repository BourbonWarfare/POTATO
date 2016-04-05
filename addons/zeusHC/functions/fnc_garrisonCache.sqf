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

// get unit limit, look up mission override first
GVAR(garrisonUnitLimit) = if (isNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")) then {
    getNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")
} else {
    getNumber (configFile >> "CfgGarrison" >> "maxUnits")
};

[missionConfigFile] call _addToCache; // look through mission config for setup
[configFile] call _addToCache; // look through the default config for any factions not defined
