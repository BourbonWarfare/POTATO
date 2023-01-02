#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchJSRS

#if __has_include("\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\small\metal_1.ogg")
#else
#define PATCH_SKIP "JSRS"
#endif

#ifdef PATCH_SKIP
PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "jsrs_soundmod_cup_weapons", "jsrs_soundmod_cfg_cup_weapons" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Mode_FullAuto;
class CfgWeapons {
    class mgun;
    class cup_vlmg_m134_veh: mgun {
        class lowrof: mode_fullauto {
            class standardsound {
                // JSRS uses 
                // soundsetshot[] = {"jsrs_m134_shot_soundset","jsrs_5x56mm_reverb_soundset"};
                // but you cannot hear at range?? Just revert back to cup's
                soundSetShot[] = {"CUP_M134_Shot_SoundSet","CUP_mmg1_Tail_SoundSet"};
            };
        };
    };
};

#endif
