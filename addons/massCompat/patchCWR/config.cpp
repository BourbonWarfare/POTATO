#include "\z\potato\addons\massCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT massCompat_patchCWR

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "cwr3_intro", "cwr3_weapon_config" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {    
    class CUP_smg_MP5SD6;
    class cwr3_smg_sterling_sd: CUP_smg_MP5SD6 {
        magazineWell[] += { "CBA_9x19_STEN"};
    };
    class CUP_smg_MP5A5;
    class cwr3_smg_sterling: CUP_smg_MP5A5 {
        magazineWell[] += { "CBA_9x19_STEN" };
    };
    class CUP_arifle_Colt727;
    class cwr3_arifle_xm177e2: CUP_arifle_Colt727 {
        magazineWell[] += { "CBA_556x45_STANAG", "CBA_556x45_STANAG_L", "CBA_556x45_STANAG_2D", "CBA_556x45_STANAG_2D_XL" };
    };
    class cwr3_arifle_xr47: CUP_arifle_Colt727 {
        magazineWell[] += { "CBA_762x39_AK" };
    };
    class cwr3_arifle_xr74: cwr3_arifle_xr47 {
        magazineWell[] += { "CBA_545x39_AK" };
    };
};
