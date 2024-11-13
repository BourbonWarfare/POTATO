class CfgWeapons {
  class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class ACE_Burst_far;
        class close;
        class far_optic1;
        class far_optic2;
        class manual;
        class medium;
        class short;
        class Single;
    };
    class potato_lmg_LAMG: LMG_Mk200_F {
        bullet1[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\metal_1.ogg",2.0099,1,10};
        bullet2[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\metal_2.ogg",2.0099,1,10};
        bullet3[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\metal_3.ogg",2.0099,1,10};
        bullet4[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\metal_4.ogg",2.0099,1,10};
        bullet5[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\dirt_1.ogg",2.0099,1,10};
        bullet6[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\dirt_2.ogg",2.0099,1,10};
        bullet7[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\dirt_3.ogg",2.0099,1,10};
        bullet8[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\dirt_4.ogg",2.0099,1,10};
        bullet9[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\grass_1.ogg",2.0099,1,10};
        bullet10[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\grass_2.ogg",2.0099,1,10};
        bullet11[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\grass_3.ogg",2.0099,1,10};
        bullet12[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\weapons\shells\small\grass_4.ogg",2.0099,1,10};
        soundbullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
        class ACE_Burst_far: ACE_Burst_far {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class close: close {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class far_optic1: far_optic1 {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class far_optic2: far_optic2 {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class manual: manual {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class medium: medium {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class short: short {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        class Single: Single {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_uwg_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
        };
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun";
        descriptionShort = "Light Machine Gun<br />Caliber: 5.56x45 mm";
        baseWeapon = "potato_lmg_LAMG";
        recoil = "CUP_SAW_recoil";
        magazineWell[] = {"CBA_556x45_MINIMI"};
        magazines[] = {"CUP_100Rnd_TE4_Red_Tracer_556x45_M249"};
    };
    class potato_lmg_LAMG_black: potato_lmg_LAMG {
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun (Black)";
        baseWeapon = "potato_lmg_LAMG_black";
        picture = "\a3\Weapons_F_Enoch\Machineguns\M200\Data\UI\icon_LMG_Mk200_black_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\1st_person_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\Body_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\grip_black_co.paa"
        };
    };
};
