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
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_csw", "CUP_Weapons_StaticWeapons", "CUP_Creatures_StaticWeapons"};
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineGroups.hpp"

#endif
