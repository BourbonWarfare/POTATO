#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxC7


class CfgPatches {
    class ADDON {
        weapons[] = { "potato_fauxC7_c7", "potato_fauxC7_c7GL", "potato_fauxC7_c7a2", "potato_fauxC7_c7a2GL",
            "potato_lmg_m249_pip1_coop", "potato_lmg_m249_pip3_coop", "potato_lmg_m249_E1_coop", "potato_lmg_m249_E2_coop", "potato_lmg_minimipara_coop" };
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

#include "CfgRecoils.hpp"
#include "CfgWeapons.hpp"
