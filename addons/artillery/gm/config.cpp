#include "\z\potato\addons\artillery\script_component.hpp"
#undef COMPONENT
#define COMPONENT artillery_gm


class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "gm_weapons_cannons_122mm_2a18",
            "gm_weapons_mortars_m120",
            "gm_weapons_mortars_2s12",
            "gm_weapons_cannons_155mm_m126",
            "gm_weapons_launchers_mlrs_110mm",
            "gm_weapons_launchers_luna",
            "gm_weapons_launchers_mlrs_122mm"
        };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
