#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_uniforms

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            "potato_jehlici",
            "potato_tan_jehlici",
            "potato_u_g3cw_serp_m05wdl_v2",
            "potato_u_g3cw_serp_m05wdl_v3",
            "potato_u_g3cw_serp_m05wdlwint",
            "potato_u_g3cw_serp_m05wdlwint_v2",
            "potato_U_CRYE_G3C_MARWDL_v8_US",
            "potato_U_CRYE_G3C_MARWDL_v9_US",
            "potato_helmet_6b28_irreg",
            "potato_helmet_6b28_irreg_ess",
            "potato_vest_grad2",
            "potato_U_M88_kamysh",
            "potato_U_M88_kamysh_rolled",
            "potato_U_M88_kamysh_rolled_gloves",
            "potato_U_M88_OREL",
            "potato_U_M88_OREL_rolled",
            "potato_U_M88_OREL_rolled_gloves",
            "potato_V_ORELVest_R_Black",
            "potato_V_ORELVest_R_Black_lite",
            "potato_V_ORELVest_Med_Black",
            "potato_V_ORELVest_Med_Black_lite",
            "potato_V_ORELVest_TL_Black",
            "potato_V_ORELVest_TL_Black_lite",
            "potato_V_ORELVest_R_Black_insignia",
            "potato_V_ORELVest_Med_Black_insignia",
            "potato_V_ORELVest_TL_Black_insignia",
            "potato_V_TacVest_blk_OREL",
            "gmx_csgo_vest_type3_cream"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { 
            "potato_core", 
            "cwr3_soldiers_us", 
            "ptv_characters", 
            "ptv_characters_cfg", 
            "CUP_Weapons_LoadOrder", 
            "CUP_Creatures_People_LoadOrder", 
            "rhs_main_loadorder", 
            "gm_characters_ge_characters"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
