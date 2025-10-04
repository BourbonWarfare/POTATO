#include "\z\potato\addons\aiCfgFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT aiCfgFixes_gm

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ACE_ai",
            "gm_weapons_launchers_rpg7"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
