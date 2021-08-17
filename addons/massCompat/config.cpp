#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "A3_Data_F_Enoch_Loadorder", "CUP_Weapons_LoadOrder" };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO", "Brandon (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"

#endif
