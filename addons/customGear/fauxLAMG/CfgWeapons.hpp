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
        // JSRSTODO: the SDAR was using the the WUG, so copying that structure
        class ACE_Burst_far: ACE_Burst_far {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class close: close {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class far_optic1: far_optic1 {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class far_optic2: far_optic2 {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class manual: manual {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class medium: medium {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class short: short {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
            };
        };
        class Single: Single {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_soundset","jsrs_2025_tailsystem_acp_SMG_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_2025_sdar_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
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
