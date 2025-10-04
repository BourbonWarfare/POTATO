#include "\z\potato\addons\aiCfgFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT aiCfgFixes_aiWeapons

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            QGVARMAIN(launch_RPG7V_optic),
            QGVARMAIN(launch_RPG7V_untrained),
            QGVARMAIN(launch_RPG7V_untrained_optic)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ACE_ai",
            "CUP_Weapons_LoadOrder"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
