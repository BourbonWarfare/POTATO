#include "script_component.hpp"

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif
#if __has_include("\hlc_core\XEH_preInit.sqf")
#else
#define PATCH_SKIP "HLC"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
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
