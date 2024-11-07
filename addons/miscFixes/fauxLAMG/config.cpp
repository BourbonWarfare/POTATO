#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        weapons[] = {
            "potato_lmg_LAMG", 
            "potato_lmg_LAMG_black"
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "CUP_Weapons_LoadOrder"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
