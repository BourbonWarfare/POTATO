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

class CfgWeapons {
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons {
    class Pistol;
    class Pistol_Base_F: Pistol {};
    class Rifle;
    class Rifle_Base_F: Rifle {};
    class UGL_F;
    class ptv_hk69_Base_F: Pistol_Base_F {};
    // Adds compat for CUP GL ammunition in PTV GL weapons
    class ptv_hk69: ptv_hk69_Base_F {
        magazines[] = {"CUP_1Rnd_HE_M203","CUP_1Rnd_HEDP_M203","CUP_1Rnd_StarCluster_White_M203","CUP_1Rnd_StarCluster_Red_M203","CUP_1Rnd_StarCluster_Green_M203","CUP_1Rnd_StarFlare_White_M203","CUP_1Rnd_StarFlare_Red_M203","CUP_1Rnd_StarFlare_Green_M203","CUP_FlareWhite_M203","CUP_FlareGreen_M203","CUP_FlareRed_M203","CUP_FlareYellow_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","CUP_1Rnd_SmokeYellow_M203","ptv_1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell"};
        magazineWell[] = {"UGL_40x36","CBA_40mm_M203","CBA_40mm_EGLM"};
    };
    class ptv_rs556: Rifle_Base_F {
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
            magazines[] = {"CUP_1Rnd_HE_M203","CUP_1Rnd_HEDP_M203","CUP_1Rnd_StarCluster_White_M203","CUP_1Rnd_StarCluster_Red_M203","CUP_1Rnd_StarCluster_Green_M203","CUP_1Rnd_StarFlare_White_M203","CUP_1Rnd_StarFlare_Red_M203","CUP_1Rnd_StarFlare_Green_M203","CUP_FlareWhite_M203","CUP_FlareGreen_M203","CUP_FlareRed_M203","CUP_FlareYellow_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","CUP_1Rnd_SmokeYellow_M203","ptv_1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell"};
            magazineWell[] = {"UGL_40x36","CBA_40mm_M203","CBA_40mm_EGLM"};
        };
    };
    class ptv_rs556s: ptv_rs556 {
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_scar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AG: Rifle_Base_F {
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    class ptv_AG: Rifle_Base_F {};
    class ptv_AG_k: ptv_AG {
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AG_k_r: ptv_AG_k {};
    class ptv_AG_GL_k_r: ptv_AG_k_r {
		class EGLM: UGL_F {
            magazines[] = {"CUP_1Rnd_HE_M203","CUP_1Rnd_HEDP_M203","CUP_1Rnd_StarCluster_White_M203","CUP_1Rnd_StarCluster_Red_M203","CUP_1Rnd_StarCluster_Green_M203","CUP_1Rnd_StarFlare_White_M203","CUP_1Rnd_StarFlare_Red_M203","CUP_1Rnd_StarFlare_Green_M203","CUP_FlareWhite_M203","CUP_FlareGreen_M203","CUP_FlareRed_M203","CUP_FlareYellow_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","CUP_1Rnd_SmokeYellow_M203","ptv_1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell"};
            magazineWell[] = {"UGL_40x36","CBA_40mm_M203","CBA_40mm_EGLM"};
        };
	};
    class ptv_AGM: ptv_AG_k {
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AG_c: ptv_AG {
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
    class ptv_AGM_GL: ptv_AGM {
        class EGLM: UGL_F {
            magazines[] = {"CUP_1Rnd_HE_M203","CUP_1Rnd_HEDP_M203","CUP_1Rnd_StarCluster_White_M203","CUP_1Rnd_StarCluster_Red_M203","CUP_1Rnd_StarCluster_Green_M203","CUP_1Rnd_StarFlare_White_M203","CUP_1Rnd_StarFlare_Red_M203","CUP_1Rnd_StarFlare_Green_M203","CUP_FlareWhite_M203","CUP_FlareGreen_M203","CUP_FlareRed_M203","CUP_FlareYellow_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","CUP_1Rnd_SmokeYellow_M203","ptv_1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell"};
            magazineWell[] = {"UGL_40x36","CBA_40mm_M203","CBA_40mm_EGLM"};
        };
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
        class single: mode_semiauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class fullauto: mode_fullauto {
            class basesoundmodetype;
            class standardsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class silencedsound: basesoundmodetype {
                soundsetshot[] = {"ptv_rifle_shake_soundset","jsrs_g36_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
    };
	};
    
    class Vest_Base;
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
                    armor = 16;
                    passThrough = 0.3;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was "28 + 3"
                    passThrough = 0.1;
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
