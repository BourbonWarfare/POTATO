// "\gm\gm_weapons\gm_launchers\gm_milan\gm_milan_heat_dm92.p3d"
// "\gm\gm_weapons\gm_launchers\gm_fagot\gm_fagot_heat_9m111.p3d"
#include "\z\potato\addons\cswCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT cswCompatCUP_patchGM

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
          QGVAR(gm_milan_backpack),
          QGVAR(gm_fagot_backpack),
          QGVAR(gm_MG3TripodCarry),
          QGVAR(gm_milan_launcher_proxy),
          QGVAR(gm_fagot_launcher_proxy)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_cswCompatCUP",
            "gm_weapons_ammo",
            "gm_weapons_launchers_milan",
            "gm_weapons_launchers_fagot",
            "gm_weapons_machineguns_mg3_gm_ge_army_mg3",
            "gm_weapons_launchers_fagot_gm_gc_army_fagot"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
