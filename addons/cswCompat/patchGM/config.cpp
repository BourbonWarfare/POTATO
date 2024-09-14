// "\gm\gm_weapons\gm_launchers\gm_milan\gm_milan_heat_dm92.p3d"
// "\gm\gm_weapons\gm_launchers\gm_fagot\gm_fagot_heat_9m111.p3d"
#include "\z\potato\addons\cswCompatCUP\script_component.hpp"
#undef COMPONENT
#define COMPONENT cswCompatCUP_patchGM

class CfgPatches {
    class ADDON {
        units[] = {
          "gm_ge_army_milan_launcher_tripod_csw"
        };
        weapons[] = {
          QGVAR(gm_milan)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_cswCompatCUP",
            "gm_weapons_ammo",
            "gm_weapons_launchers_milan",
            "gm_weapons_launchers_fagot",
            "gm_weapons_machineguns_dshkm_gm_gc_army_dshkm",
            "gm_weapons_machineguns_mg3_gm_ge_army_mg3",
            "gm_weapons_launchers_fagot_gm_gc_army_fagot",
            "gm_weapons_launchers_spg9_gm_gc_army_spg9"
        };
        skipWhenMissingDependencies = 0;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "ACE_CSW_Groups.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
