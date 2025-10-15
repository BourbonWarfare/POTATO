#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPTV

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "ptv_vehicles", "ptv_characters_cfg", "ptv_characters", "ptv_sounds", "jsrs_soundmod_complete_edition", "jsrs_soundmod_complete_edition_soundfiles" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};



class CBA_Extended_EventHandlers;
class CfgVehicles {
    // Fix XEH: "[CBA] (xeh) WARNING: ptv_Pnd_Base_F does not support Extended Event Handlers! Addon: 3092130870"
    class B_APC_Wheeled_03_cannon_F;
    class ptv_Pnd_Base_F: B_APC_Wheeled_03_cannon_F {
        class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; };
    };
    class I_APC_tracked_03_cannon_F;
    class ptv_Warrior_Base_F: I_APC_tracked_03_cannon_F {
        class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; };
    };


    // Increase storage capacity of Contact DLC Radio Backpack to hold ACRE radios and radio accessories.
    class B_RadioBag_01_base_F;
    class ptv_RadioBag_01_Desert: B_RadioBag_01_base_F {maximumLoad=300;}; // from Project True Viking
    class ptv_RadioBag_01_Woodland: B_RadioBag_01_base_F {maximumLoad=300;};
};


class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons {
    class Pistol;
    class Pistol_Base_F: Pistol {};
    class Rifle;
    class Rifle_Base_F: Rifle {};
    class UGL_F;
    class Rifle_Long_Base_F: Rifle_Base_F {};
    class ptv_m249: Rifle_Long_Base_F {
        UiPicture = "\A3\weapons_f\data\UI\icon_mg_CA.paa"; // STHUD/DUI Compat
    };
    class ptv_rs556 : Rifle_Base_F {
        bullet1[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_1.ogg",2.0099,1,10};
        bullet2[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_2.ogg",2.0099,1,10};
        bullet3[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_3.ogg",2.0099,1,10};
        bullet4[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_4.ogg",2.0099,1,10};
        bullet5[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_1.ogg",2.0099,1,10};
        bullet6[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_2.ogg",2.0099,1,10};
        bullet7[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_3.ogg",2.0099,1,10};
        bullet8[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_4.ogg",2.0099,1,10};
        bullet9[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_1.ogg",2.0099,1,10};
        bullet10[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_2.ogg",2.0099,1,10};
        bullet11[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_3.ogg",2.0099,1,10};
        bullet12[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_4.ogg",2.0099,1,10};
        soundbullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class M203: UGL_F {
            magazineWell[] = {"UGL_40x36", "CBA_40mm_M203"};
        };
    };
    class ptv_rs556s: ptv_rs556 {
    // Updating base class Mode_SemiAuto->Single, by z\potato\addons\miscFixes\patchptv\config.cpp/CfgWeapons/ptv_rs556s/Single/ (original (ptv_weapons_cfg\config.bin - no unload))
    // due to ptv_sounds, as it has different inheritance from ptv_weapons_cfg
        class Single : Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto : FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };

    class ptv_rk62m2: Rifle_Base_F {
        bullet1[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_1.ogg",2.0099,1,10};
        bullet2[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_2.ogg",2.0099,1,10};
        bullet3[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_3.ogg",2.0099,1,10};
        bullet4[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_4.ogg",2.0099,1,10};
        bullet5[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_1.ogg",2.0099,1,10};
        bullet6[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_2.ogg",2.0099,1,10};
        bullet7[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_3.ogg",2.0099,1,10};
        bullet8[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_4.ogg",2.0099,1,10};
        bullet9[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_1.ogg",2.0099,1,10};
        bullet10[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_2.ogg",2.0099,1,10};
        bullet11[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_3.ogg",2.0099,1,10};
        bullet12[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_4.ogg",2.0099,1,10};
        soundbullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_ak103_shot_soundset","jsrs_7x62mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_ak103_shot_silenced_soundset","jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_ak103_shot_soundset","jsrs_7x62mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_ak103_shot_silenced_soundset","jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
    };

    class ptv_hk433: Rifle_Base_F {
        bullet1[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_1.ogg",2.01,1,10};
        bullet2[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_2.ogg",2.01,1,10};
        bullet3[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_3.ogg",2.01,1,10};
        bullet4[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_4.ogg",2.01,1,10};
        bullet5[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_1.ogg",2.01,1,10};
        bullet6[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_2.ogg",2.01,1,10};
        bullet7[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_3.ogg",2.01,1,10};
        bullet8[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_4.ogg",2.01,1,10};
        bullet9[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_1.ogg",2.01,1,10};
        bullet10[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_2.ogg",2.01,1,10};
        bullet11[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_3.ogg",2.01,1,10};
        bullet12[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_4.ogg",2.01,1,10};
        soundbullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_hk416_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_hk416_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_hk433s: ptv_rs556 {
        class Single: Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_hk416_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_hk416_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };

    class ptv_AG : Rifle_Base_F {
        bullet1[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_1.ogg",2.0099,1,10};
        bullet2[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_2.ogg",2.0099,1,10};
        bullet3[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_3.ogg",2.0099,1,10};
        bullet4[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\metal_4.ogg",2.0099,1,10};
        bullet5[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_1.ogg",2.0099,1,10};
        bullet6[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_2.ogg",2.0099,1,10};
        bullet7[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_3.ogg",2.0099,1,10};
        bullet8[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\dirt_4.ogg",2.0099,1,10};
        bullet9[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_1.ogg",2.0099,1,10};
        bullet10[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_2.ogg",2.0099,1,10};
        bullet11[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_3.ogg",2.0099,1,10};
        bullet12[] = {"\jsrs_soundmod_complete\jsrs_soundmod_soundfiles\weapons\shells\medium\grass_4.ogg",2.0099,1,10};
        soundbullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class EGLM: UGL_F {
            magazineWell[] = {"UGL_40x36", "CBA_40mm_M203", "CBA_40mm_EGLM"};
        };
    };
    class ptv_AG_k : ptv_AG {
         class Single: Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AG_c : ptv_AG {
         class Single: Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AGM : ptv_AG_k {
         class Single: Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AGM_GL: ptv_AGM {
        class Single: Single {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class FullAuto: FullAuto {
            sounds[] = {"StandardSound","SilencedSound"};
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };

    class ptv_hk69_Base_F: Pistol_Base_F {
        magazineWell[] = {"UGL_40x36", "CBA_40mm_M203", "CBA_40mm_EGLM"};
    };

    class VestItem;
    class V_PlateCarrier1_rgr;
    // Normalizes PTV armor values to be in line with vanilla/CUP armor values
    class V_thor: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16; // was 28
                    passThrough = 0.3; // was 0.1
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.4
                };
            };
        };
    };
    class V_thor2: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was 28
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_rgr: V_thor {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.4
                };
            };
        };
    };
    class V_thor_rgr2: V_thor {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was 28
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.4
                };
            };
        };
    };
    class V_thor_wdl: V_thor {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.4
                };
            };
        };
    };
    class V_thor_wdl2: V_thor {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was 28
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.4
                };
            };
        };
    };
    class V_thor02: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor02_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor02_wdl: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor03: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor03_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor03_wdl: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_r: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_r_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_r2: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_r2_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16; // was 28
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = "16"; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_sl: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_sl_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_tl: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class V_thor_tl_rgr: V_PlateCarrier1_rgr {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16;
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
};

class SlotInfo;
class CowsSlot: SlotInfo {};
class CowsSlot_Rail: CowsSlot {
    class compatibleItems {};
};
class gm_slotOptic_risrail: CowsSlot_Rail {
    class compatibleItems {
        ptv_rmr = 1;
        ptv_rmr_des = 1;
        ptv_rmr_wdl = 1;
        ptv_compm4s = 1;
        ptv_cm4s3xmag = 1;
        ptv_cm4s3xmag_f = 1;
        ptv_cm4s3xmag_pip = 1;
        ptv_cm4s3xmag_pf = 1;
        ptv_compm5 = 1;
        ptv_compm5s = 1;
        ptv_cm53xmag = 1;
        ptv_cm53xmag_f = 1;
        ptv_cm53xmag_pip = 1;
        ptv_cm53xmag_pf = 1;
        ptv_cm5s3xmag = 1;
        ptv_cm5s3xmag_f = 1;
        ptv_cm5s3xmag_pip = 1;
        ptv_cm5s3xmag_pf = 1;
        ptv_aimcs = 1;
        ptv_aimcs2 = 1;
        ptv_aim3xmag = 1;
        ptv_aim3xmag_f = 1;
        ptv_eot552 = 1;
        ptv_xps3 = 1;
        ptv_xps3_des = 1;
        ptv_xps3xmag = 1;
        ptv_xps3xmag_f = 1;
        ptv_xps3xmag_pip = 1;
        ptv_xps3xmag_pf = 1;
        ptv_xps3xmag_des = 1;
        ptv_xps3xmag_des_f = 1;
        ptv_xps3xmag_des_pip = 1;
        ptv_xps3xmag_des_pf = 1;
        ptv_c79 = 1;
        ptv_c79_2D = 1;
        ptv_c79_pip = 1;
        ptv_m145 = 1;
        ptv_m145_2D = 1;
        ptv_m145_pip = 1;
        ptv_PMII = 1;
        ptv_PMII_sunshade = 1;
        ptv_PMII_des = 1;
        ptv_PMII_des_sunshade = 1;
        ptv_PMII_wdl = 1;
        ptv_PMII_wdl_sunshade = 1;
        ptv_PMII_rmr = 1;
        ptv_PMII_rmr_sunshade = 1;
        ptv_PMII_rmr_des = 1;
        ptv_PMII_rmr_des_sunshade = 1;
        ptv_PMII_rmr_wdl = 1;
        ptv_PMII_rmr_wdl_sunshade = 1;
        ptv_PMII_525 = 1;
        ptv_PMII_525_des = 1;
        ptv_PMII_525_wdl = 1;
        ptv_t1 = 1;
        ptv_t1s = 1;
        ptv_t13xmag = 1;
        ptv_t13xmag_f = 1;
        ptv_t1s3xmag = 1;
        ptv_t1s3xmag_f = 1;
        ptv_t13xmag_pip = 1;
        ptv_t13xmag_pf = 1;
        ptv_t1s3xmag_pip = 1;
        ptv_t1s3xmag_pf = 1;
        ptv_ta11 = 1;
        ptv_ta11_2D = 1;
        ptv_ta11_2Dpip = 1;
        ptv_ta11_pip = 1;
        ptv_ta11rmr = 1;
        ptv_ta11rmr_2D = 1;
        ptv_ta11rmr_2Dpip = 1;
        ptv_ta11rmr_pip = 1;
        ptv_ta02led = 1;
        ptv_ta02led_2D = 1;
        ptv_ta02led_2Dpip = 1;
        ptv_ta02led_pip = 1;
        ptv_ta02led_rmr = 1;
        ptv_ta02led_rmr_2D = 1;
        ptv_ta02led_rmr_2Dpip = 1;
        ptv_ta02led_rmr_pip = 1;
        ptv_ta648 = 1;
        ptv_ta648_pip = 1;
        ptv_ta648_rmr = 1;
        ptv_zo = 1;
        ptv_zo_rmr = 1;
        ptv_zos = 1;
        ptv_zos_rmr = 1;
        ptv_specterdr = 1;
        ptv_specterdr_2D = 1;
        ptv_specterdr_pip = 1;
        ptv_specterdr_des = 1;
        ptv_specterdr_des_2D = 1;
        ptv_specterdr_des_pip = 1;
        ptv_specterdr_rmr = 1;
        ptv_specterdr_rmr_2D = 1;
        ptv_specterdr_rmr_pip = 1;
        ptv_specterdr_rmr_des = 1;
        ptv_specterdr_rmr_des_2D = 1;
        ptv_specterdr_rmr_des_pip = 1;
        ptv_specterdr6 = 1;
        ptv_specterdr6_2D = 1;
        ptv_specterdr6_pip = 1;
        ptv_specterdr6_des = 1;
        ptv_specterdr6_des_2D = 1;
        ptv_specterdr6_des_pip = 1;
        ptv_specterdr6_rmr = 1;
        ptv_specterdr6_rmr_2D = 1;
        ptv_specterdr6_rmr_pip = 1;
        ptv_specterdr6_rmr_des = 1;
        ptv_specterdr6_rmr_des_2D = 1;
        ptv_specterdr6_rmr_des_pip = 1;
        ptv_shortdot = 1;
        ptv_shortdot_wdl = 1;
        ptv_shortdot_des = 1;
        ptv_shortdot_pip = 1;
        ptv_shortdot_wdl_pip = 1;
        ptv_shortdot_des_pip = 1;
        ptv_shortdot_dcc = 1;
        ptv_shortdot_dcc_wdl = 1;
        ptv_shortdot_dcc_des = 1;
        ptv_shortdot_dcc_pip = 1;
        ptv_shortdot_dcc_wdl_pip = 1;
        ptv_shortdot_dcc_des_pip = 1;
        ptv_s3x = 1;
        ptv_s3x_des = 1;
        ptv_s3x_wdl = 1;
        ptv_CWS = 1;
        ptv_vipir2 = 1;
        ptv_vipir2p = 1;
    };
};


class CfgMagazineWells {
    class CBA_556x45_SCAR_EGLM {
        PTV_Magazines[] = {"ptv_30Rnd_556x45_Stanag","ptv_30Rnd_556x45_Stanag_g","ptv_30Rnd_556x45_Stanag_t","ptv_30Rnd_556x45_Stanag_pull","ptv_30Rnd_556x45_Stanag_pull_t","ptv_30Rnd_556x45_Stanag_pull_g","ptv_30Rnd_556x45_Stanag_Red","ptv_30Rnd_556x45_Stanag_g_Red","ptv_30Rnd_556x45_Stanag_t_Red","ptv_30Rnd_556x45_Stanag_pull_Red","ptv_30Rnd_556x45_Stanag_pull_t_Red","ptv_30Rnd_556x45_Stanag_pull_g_Red","ptv_40Rnd_556x45_Pmag","ptv_40Rnd_556x45_Pmag_g","ptv_40Rnd_556x45_Pmag_t","ptv_40Rnd_556x45_Pmag_Red","ptv_40Rnd_556x45_Pmag_g_Red","ptv_40Rnd_556x45_Pmag_t_Red","ptv_30Rnd_556x45_Pmag","ptv_30Rnd_556x45_Pmag_g","ptv_30Rnd_556x45_Pmag_t","ptv_30Rnd_556x45_Pmag_Red","ptv_30Rnd_556x45_Pmag_g_Red","ptv_30Rnd_556x45_Pmag_t_Red","ptv_30Rnd_556x45_Pmagw","ptv_30Rnd_556x45_Pmagw_g","ptv_30Rnd_556x45_Pmagw_t","ptv_30Rnd_556x45_Pmagw_Red","ptv_30Rnd_556x45_Pmagw_g_Red","ptv_30Rnd_556x45_Pmagw_t_Red","ptv_30Rnd_556x45_L5awm","ptv_30Rnd_556x45_L5awm_g","ptv_30Rnd_556x45_L5awm_t","ptv_30Rnd_556x45_L5awm_Red","ptv_30Rnd_556x45_L5awm_g_Red","ptv_30Rnd_556x45_L5awm_t_Red","ptv_30Rnd_556x45_L5awmc","ptv_30Rnd_556x45_L5awmc_Red","ptv_30Rnd_556x45_L5awmc_pull","ptv_30Rnd_556x45_L5awmc_pull_Red"};
    };
};
