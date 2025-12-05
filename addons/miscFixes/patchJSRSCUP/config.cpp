#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchJSRS_CUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "jsrs_soundmod_cup_weapons" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons {
    class mgun;
    class cup_vlmg_m134_veh: mgun {
        class lowrof: Mode_FullAuto {
            class standardsound {
                // JSRS uses 
                // soundsetshot[] = {"jsrs_m134_shot_soundset","jsrs_5x56mm_reverb_soundset"};
                // but you cannot hear at range?? Just revert back to cup's
                soundSetShot[] = {"CUP_M134_Shot_SoundSet","CUP_mmg1_Tail_SoundSet"};
            };
        };
    };

    class Rifle_Base_f;
    class CUP_arifle_M16_Base: Rifle_Base_f {
        class Single: Mode_SemiAuto {};
    };
    class cup_arifle_colt727: CUP_arifle_M16_Base {
        class Single: Single {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"jsrs_m4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"jsrs_m4_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class cup_arifle_g36_base: Rifle_Base_f {
        class Burst: Mode_Burst {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    
    class CUP_arifle_RPK74;
    class CUP_arifle_RPK74_45: CUP_arifle_RPK74 {
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_ak_m_shot_soundset","jsrs_7x62mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_ak12_shot_silenced_soundset","jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
    };
    class CUP_arifle_RPK74M: CUP_arifle_RPK74 {
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_ak_m_shot_soundset","jsrs_7x62mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_ak12_shot_silenced_soundset","jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
    };
};
