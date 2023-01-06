#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "CUP_Weapons_LoadOrder", "cwr3_weapon_config"};
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"

#endif
