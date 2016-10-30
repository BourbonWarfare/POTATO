#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(usePotato) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "usePotato")) == 1);

if (GVAR(usePotato)) then {
    GVAR(loadoutCache) = call CBA_fnc_createNamespace;
    GVAR(classnameCache) = call CBA_fnc_createNamespace;
    GVAR(weaponAttachmentCache) = call CBA_fnc_createNamespace;

    GVAR(allowMagnifiedOptics) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "allowMagnifiedOptics")) == 1);
    GVAR(useFallback) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "useFallback")) == 1);
    GVAR(maxRandomization) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization")) then { getNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization") } else { 5 };
    GVAR(setVehicleLoadouts) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")) then {getNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")} else { 1 };
    GVAR(prefixes) = if (isArray (missionConfigFile >> "CfgLoadouts" >> "prefixes")) then { getArray (missionConfigFile >> "CfgLoadouts" >> "prefixes") } else { [] };

    diag_log text format ["[POTATO-assignGear] Enabled [useFallback:%1 allowMagnifiedOptics:%2 maxRandomization:%3 setVehicleLoadouts:%4, prefixes: %5]", GVAR(useFallback), GVAR(allowMagnifiedOptics), GVAR(maxRandomization), GVAR(setVehicleLoadouts), GVAR(prefixes)];
} else {
    diag_log text format ["[POTATO-assignGear] Disabled"];
};

ADDON = true;
