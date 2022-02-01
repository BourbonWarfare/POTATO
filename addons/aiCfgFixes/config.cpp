#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ACE_ai",
            "hlcweapons_AUG", "hlcweapons_g3", "hlcweapons_G36", "hlcweapons_MG3s", "hlcweapons_mp5", "hlcweapons_stgw57", "hlcweapons_Johnson",
            "rhs_main_loadorder", "CUP_Weapons_LoadOrder"
        };
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"

#endif
