#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxL96A1


class CfgPatches {
    class ADDON {
        weapons[] = { 
            "potato_srifle_L96A1",
            "potato_srifle_L96A1_des",
            "potato_srifle_L96A1_blk"
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "CUP_Weapons_LoadOrder", "jsrs_soundmod_cup_weapons"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
