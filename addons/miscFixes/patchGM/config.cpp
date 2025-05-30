#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchGM

class CfgPatches {
    class ADDON {
        weapons[] = {
            "gm_mp2a1_gld"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_miscFixes",
            "gm_structures_euro_80",
            "gm_structures_euro_80_winter",
            "gm_core_weapons",
            "gm_weapons_ammo",
            "gm_weapons_put",
            "gm_weapons_throw",
            "gm_weapons_launchers_fim43",
            "gm_weapons_launchers_luna",
            "gm_weapons_launchers_m72",
            "gm_weapons_launchers_mlrs_110mm",
            "gm_weapons_launchers_mlrs_122mm",
            "gm_weapons_launchers_pzf3",
            "gm_weapons_launchers_pzf44_2",
            "gm_weapons_launchers_rpg7",
            "gm_weapons_launchers_rpg18",
            "gm_weapons_launchers_strela",
            "gm_weapons_machinepistols_gm_mp2"
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
#include "CfgAmmo.hpp"
#include "CfgCloudlets.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
