/*
 * Author: AACO
 * Function used to get the max unit limit from the mission/mod config
 *
 * Returns: the unit limit from the mission config, or the mod config <NUMBER>
 *
 * Example:
 * [] call potato_zeusHC_fnc_garrisonUnitLimit;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// get unit limit, look up mission override first
if (isNil QGVAR(garrisonUnitLimit)) then {
    GVAR(garrisonUnitLimit) = if (isNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")) then {
        getNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")
    } else {
        getNumber (configFile >> "CfgGarrison" >> "maxUnits")
    };
};
GVAR(garrisonUnitLimit)
