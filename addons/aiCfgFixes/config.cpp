#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ACE_ai", "CUP_Weapons_LoadOrder"
        };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
