#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"potato_cheezItBoxPlaceable", "potato_serverPlaceable", "potato_gamestopPlaceable"};
        weapons[] = {"potato_cheezItBox", "potato_serverBox", "potato_funGun_red", "potato_funGun_green"};
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