#include "\z\potato\addons\miscFixes\script_component.hpp"
#include "\z\potato\addons\missileGuidanceCompat\CfgMissileTypesWarsaw.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchTBDMTLB

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "potato_missileGuidanceCompat",
            "CUP_Weapons_VehicleWeapons",
            "tbd_mtlb_main",
            "tbd_mtlb_6m",
            "tbd_mtlb_strela",
            "tbd_mtlb_shturm"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
