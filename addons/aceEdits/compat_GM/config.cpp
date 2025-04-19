#include "\z\potato\addons\aceEdits\script_component.hpp"
#undef COMPONENT
#define COMPONENT aceEdits_compat_GM

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "potato_core",
          "gm_vehicles_land_wheeled_fuchs_ge_army_fuchs",
          "gm_vehicles_land_wheeled_luchs_ge_army_luchs",
          "gm_vehicles_land_wheeled_brdm2_pl_army_brdm2",
          "gm_vehicles_land_wheeled_ot64_pl_army_ot64",
          "gm_vehicles_land_wheeled_brdm2_gc_army_brdm2",
          "gm_vehicles_land_wheeled_btr60_gc_army_btr60"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
