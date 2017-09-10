#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"potato_cheezItBoxPlaceable", "potato_serverPlaceable"};
        weapons[] = {"potato_cheezItBox", "potato_serverBox"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgLeaflets.hpp"
