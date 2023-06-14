#include "script_component.hpp"

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif
#if __has_include("\CUP\Vehicles\CUP_Vehicles_Core\config.bin")
#else
#define PATCH_SKIP "CUP Vehicles"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "potato_aiCfgFixes", "A3_Data_F_Enoch_Loadorder", "CUP_Weapons_LoadOrder",
        //"cwr3_weapon_config"
       };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO", "Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"

#endif
