#include "\z\potato\addons\aiCfgFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT aiCfgFixes_rhs_hlc

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { 
            "potato_core", "ACE_ai",
            "hlcweapons_AUG", "hlcweapons_g3", "hlcweapons_G36", "hlcweapons_MG3s", "hlcweapons_mp5", "hlcweapons_stgw57", "hlcweapons_Johnson",
            "rhs_main_loadorder"
            // todo VN?
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
