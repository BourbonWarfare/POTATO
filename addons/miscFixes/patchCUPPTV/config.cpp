#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCUPPTV

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "ptv_characters_cfg", "CUP_Weapons_LoadOrder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class Rifle_Base_F;
    class CUP_arifle_ACR_BASE_556: Rifle_Base_F {
        reloadAction = "ptv_GestureReloadHK433";
        magazineReloadSwitchPhase = 0.3;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
    };
    class CUP_arifle_ACR_BASE_68: Rifle_Base_F {
        reloadAction = "ptv_GestureReloadHK433";
        magazineReloadSwitchPhase = 0.3;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {};
    class CUP_arifle_M4_Base: CUP_arifle_M16_Base {};
    class CUP_arifle_M4A1_BUIS_Base: CUP_arifle_M4_Base {};
    class CUP_arifle_M4A1_MOE_black: CUP_arifle_M4A1_BUIS_Base{
		reloadAction = "GestureReloadSPAR_01";
        magazineReloadSwitchPhase = 0.1829;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
	};
    class CUP_arifle_M4A1_MOE_short_black: CUP_arifle_M4A1_BUIS_Base {
        reloadAction = "GestureReloadSPAR_01";
        magazineReloadSwitchPhase = 0.1829;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
	};
    class CUP_arifle_M4A1_standard_black: CUP_arifle_M4A1_BUIS_Base {
		reloadAction = "GestureReloadSPAR_01";
        magazineReloadSwitchPhase = 0.1829;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
	};
    class CUP_arifle_M4A1_standard_short_black: CUP_arifle_M4A1_BUIS_Base {
        reloadAction = "GestureReloadSPAR_01";
        magazineReloadSwitchPhase = 0.1829;
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
    };
};
