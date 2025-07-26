#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(supply_westSquad), QGVAR(supply_westPlatoon), QGVAR(supply_eastSquad), QGVAR(supply_eastPlatoon), QGVAR(supply_indSquad), QGVAR(supply_indPlatoon)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
