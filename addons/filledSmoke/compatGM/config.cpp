#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        weapons[] = {};
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "potato_filledSmoke",
            "gm_core_weapons",
            "gm_weapons_throw"
        };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AACO", "Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgCloudlets.hpp"
