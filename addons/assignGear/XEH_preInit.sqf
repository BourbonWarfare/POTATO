#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(usePotato) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "usePotato")) == 1);

if (GVAR(usePotato)) then {
    GVAR(loadoutCache) = call CBA_fnc_createNamespace;

    GVAR(allowMagnifiedOptics) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "allowMagnifiedOptics")) == 1);
    GVAR(useFallback) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "useFallback")) == 1);
    GVAR(maxRandomization) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization")) then { getNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization") } else {5};
    GVAR(setVehicleLoadouts) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")) then {getNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")} else {1};

    diag_log text format ["[POTATO-assignGear] Enabled [useFallback:%1 allowMagnifiedOptics:%2 maxRandomization:%3 setVehicleLoadouts:%4]", GVAR(useFallback), GVAR(allowMagnifiedOptics), GVAR(maxRandomization), GVAR(setVehicleLoadouts)];
} else {
    diag_log text format ["[POTATO-assignGear] Disabled"];
};

ADDON = true;
