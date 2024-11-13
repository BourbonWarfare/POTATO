#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxLAMG

class CfgPatches {
    class ADDON {
        weapons[] = {
            "potato_lmg_LAMG", 
            "potato_lmg_LAMG_black"
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder", "jsrs_soundmod_complete_edition", "jsrs_soundmod_complete_edition_soundFiles" };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
