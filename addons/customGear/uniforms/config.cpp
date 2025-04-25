#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_uniforms

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            "csla_jehlici",
            "clsa_tan_jehlici",
            "potato_u_g3cw_serp_m05wdl_v2",
            "potato_u_g3cw_serp_m05wdl_v3",
            "potato_u_g3cw_serp_m05wdlwint",
            "potato_u_g3cw_serp_m05wdlwint_v2",
            "potato_U_CRYE_G3C_MARWDL_v8_US",
            "potato_U_CRYE_G3C_MARWDL_v9_US"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "cwr3_soldiers_us", "ptv_characters", "ptv_characters_cfg", "CUP_Weapons_LoadOrder", "CUP_Creatures_People_LoadOrder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"