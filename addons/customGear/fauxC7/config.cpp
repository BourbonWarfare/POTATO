#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxC7


class CfgPatches {
    class ADDON {
        weapons[] = { "potato_fauxC7_c7", "potato_fauxC7_c7GL", "potato_fauxC7_c7a2", "potato_fauxC7_c7a2GL", "potato_arifle_M4", "potato_arifle_M4_M203", "potato_arifle_M4_RIS", "potato_arifle_M4_RIS_grip", "potato_arifle_M4_RIS_M203" };
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

#include "CfgWeapons.hpp"
