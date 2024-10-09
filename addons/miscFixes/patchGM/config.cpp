#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchGM

class CfgPatches {
    class ADDON {
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_miscFixes",
            "gm_structures_euro_80",
            "gm_structures_euro_80_winter"
        };
        units[] = {
            "land_gm_euro_bridge_02_20_mainroad",
            "land_gm_euro_bridge_02_20_mainroad_win",
            "land_gm_euro_bridge_02_20_normalroad",
            "land_gm_euro_bridge_02_20_normalroad_win",
            "land_gm_euro_bridge_02_20_mainroad_half",
            "land_gm_euro_bridge_02_20_mainroad_half_win",
            "land_gm_euro_bridge_02_20_normalroad_half",
            "land_gm_euro_bridge_02_20_normalroad_half_win",
            "land_gm_euro_bridge_01_25_badroad",
            "land_gm_euro_bridge_01_25_badroad_win",
            "land_gm_euro_bridge_01_25_patrolPath",
            "land_gm_euro_bridge_01_25_patrolPath_win",
            "land_gm_euro_bridge_01_25_track",
            "land_gm_euro_bridge_01_25_track_win",
            "land_gm_euro_bridge_03_50_highway",
            "land_gm_euro_bridge_03_50_highway_win",
            "land_gm_euro_bridge_03_50_highway_half",
            "land_gm_euro_bridge_03_50_highway_half_win"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};
#include "CfgVehicles.hpp"
