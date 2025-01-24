#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "potato_customGear", "CUP_Weapons_LoadOrder", "CUP_Vehicles_LoadOrder", "CUP_Creatures_People_LoadOrder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    // Fix broken artillery computer on FV432 Mortar (shows artillery computer for 7.62mg)
    class CUP_B_FV432_Bulldog_GB_D;
    class CUP_B_FV432_Base: CUP_B_FV432_Bulldog_GB_D {
        class Turrets;
    };
    class CUP_B_FV432_GB_GPMG: CUP_B_FV432_Base {
        class NewTurret;
        class Turrets: Turrets {
            class MainTurret;
            class Commander;
        };
    };
    class CUP_B_FV432_Mortar: CUP_B_FV432_GB_GPMG {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                primaryGunner = 0;
            };
            class Commander: Commander {
                primaryGunner = 0;
            };
            class MortarTurret: NewTurret {
                primaryGunner = 1; // this breaks "stow gpmg" user action
                gunnerOutOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
            };
        };
        class UserActions {}; // clear all user actions (not a big deal)
    };
    // Fix the M1038 back seat
    class Car_F;
    class CUP_nHMMWV_Base: Car_F {
        class CargoTurret;
    };
    class CUP_nM1038_Base: CUP_nHMMWV_Base {
        class Turrets {
            class CargoTurret_01: CargoTurret {
                gunnerAction = "CUP_HMMWV_bench_gunner_1";
            };
        };
    };
    // Tweaks to the GTK Boxer's handling (accel/braking) + HMG swap to M3M + countermeasures move to gunner
    class Wheeled_APC_F: Car_F {
        class NewTurret;
        class Turrets {
            class MainTurret: NewTurret {
                class Turrets {};
            };
        };
    };
    class CUP_Boxer_Base: Wheeled_APC_F {
        class AnimationSources;
    };
    class CUP_Boxer_Base_HMG: CUP_Boxer_Base {
        class CargoTurret;
        class Turrets {
            class MainTurret: NewTurret {
                weapons[] = {"CUP_Vhmg_M3P_veh","SmokeLauncher"}; // was CUP_Vhmg_M2_veh
                magazines[] = {"CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "SmokeLauncherMag"}; // was CUP_200Rnd_TE1_Red_Tracer_127x99_M
            };
            class CommanderTurret: NewTurret {
                weapons[] = {}; // was "SmokeLauncher"
                magazines[] = {}; // was "SmokeLauncherMag"
            };
        };
        accelAidForceCoef = 2.3; // was 1.4
        accelAidForceSpd = 25; // was 5
        brakeIdleSpeed = 1.78; // was 0
        maxFordingDepth = 1.0; // was 1.5
        class Wheels {
            class wheel_1_1 {
                maxBrakeTorque = 20000; // was 12500
                maxHandBrakeTorque = 30000; // was 25000
            };
        };
        class AnimationSources: AnimationSources {
            class main_gun_muzzle_rot {
                weapon = "CUP_Vhmg_M3P_veh";
            };
            class main_gun_reload {
                weapon="CUP_Vhmg_M3P_veh";
            };
            class main_gun_reload_mag {
                weapon="CUP_Vhmg_M3P_veh";
            };
            class main_gun_revolving {
                weapon="CUP_Vhmg_M3P_veh";
            };
        };
    };
    class CUP_Boxer_Base_GMG: CUP_Boxer_Base_HMG {
        class CargoTurret;
        class Turrets {
            class MainTurret: NewTurret {
                weapons[] = {"CUP_Vgmg_HKGMG_veh","SmokeLauncher"}; // added smoke launcher
                magazines[] = {"CUP_32Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","SmokeLauncherMag"}; // added smoke mag
            };
            class CommanderTurret: NewTurret {
                weapons[] = {}; // was "SmokeLauncher"
                magazines[] = {}; // was "SmokeLauncherMag"
            };
        };
    };
};

class CfgRecoils {
    class recoil_default;
    class GVAR(recoil_m240): recoil_default {
        muzzleOuter[] = {0.9,1.3,0.35,0.25};
        kickBack[] = {0.015,0.02};
        permanent = 0.05;
        temporary = 0.005;
    };
    class GVAR(recoil_pkm): recoil_default {
        muzzleOuter[] = {1.1,0.8,0.4,0.2};
        kickBack[] = {0.015,0.03};
        permanent = 0.1;
        temporary = 0.005;
    };
    class GVAR(recoil_SAW): recoil_default {
        muzzleOuter[] = {0.8,1.4,0.35,0.25};
        kickBack[] = {0.015,0.02};
        permanent = 0.08;
        temporary = 0.005;
    };
    class GVAR(recoil_uk59): recoil_default {
        muzzleOuter[] = {0.71,1.22,0.35,0.55};
        kickBack[] = {0.026,0.064};
        permanent = 0.13;
        temporary = 0.005;
    };
};

class CfgMagazines {
    class CUP_6Rnd_HE_M203;
    class potato_6Rnd_40mm_M433_HEDP: CUP_6Rnd_HE_M203 {
        ammo = "potato_40x46mm_HEDP_M433";
        descriptionShort = "Type: High Explosive Dual Purpose<br/>Rounds: 6<br/>Used in: M32 grenade launcher";
        displayName = "40x46mm 6Rnd M433 (HEDP) Grenade";
        displayNameshort = "M433 HEDP";
    };
};

class CfgMagazineWells {
    class CBA_40mm_M203_6rnds {
        potato_magazineWell[] = { "potato_6Rnd_40mm_M433_HEDP" };
    };
};

class CfgWeapons {
    class CUP_arifle_RPK74;
    class potato_arifle_RPK: CUP_arifle_RPK74 {
        // CUP_arifle_RPK74 is actually a chambered in 7.62 and just called RPK in-game
        // CUP_arifle_RPK74_45 is the 5.45 version and is called RPK-74 in game
        // so this isn't needed anymore
        scope = 1;
        UiPicture = "\A3\weapons_f\data\UI\icon_mg_CA.paa"; // STHUD/DUI Compat
    };

    // Add "plot armor" to some vests /* From V_PlateCarrier2_rgr */
    class ItemCore;
    class CUP_Vest_Camo_Base;
    class CUP_V_B_ALICE: CUP_Vest_Camo_Base {
        class ItemInfo;
    };
    class rhsgref_alice_webbing_bwArmorMod: CUP_V_B_ALICE { // must keep old classname, but this is now based on CUP
        displayName = "ALICE Webbing [coop plot armor]";
        descriptionShort = "Armor Level IV";
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };

    class Rifle_Base_F;
    class Rifle_Short_Base_F;
    class Rifle_Long_Base_F;
    class CUP_lmg_M240: Rifle_Long_Base_F { // Applies good cool m240 custom recoil values defined in cfgrecoil
        recoil = QGVAR(recoil_m240);
    };

    class CUP_lmg_PKM: Rifle_Long_Base_F { // Applies good cool PKM custom recoil values defined in cfgrecoil
        recoil = QGVAR(recoil_pkm);
    };
    class CUP_saw_base;
    class CUP_lmg_minimipara: CUP_saw_base { // Applies good cool M249 custom recoil values defined in cfgrecoil
        recoil = QGVAR(recoil_SAW);
    };
    class CUP_smg_MP7: Rifle_Short_Base_F { // Applies the APEX dlc MP5 recoil to the CUP MP7
        recoil = "recoil_smg_05";
    };
    class CUP_lmg_UK59: Rifle_Long_Base_F { // Tones down the horrific standing recoil to a more manageable state. Still stucks, but less now
        recoil = QGVAR(recoil_uk59);
    };

    // 40mm HEDP
    class CUP_Vhmg_AGS30_veh;
    class CUP_Vgmg_MK19_veh: CUP_Vhmg_AGS30_veh {
        magazineWell[] += {"potato_HV_40x53mm"};
    };

    // Boxer HMG weapon
    class CUP_Vhmg_M2_veh;
    class CUP_Vhmg_M3P_veh: CUP_Vhmg_M2_veh {
         magazines[] = {
            "CUP_250Rnd_TE1_Red_Tracer_127x99_M", // CUP_Vhmg_M3P_veh default
            "CUP_100Rnd_127x99_M", // rest from CUP_Vhmg_M2_veh
            "CUP_100Rnd_TE4_Red_Tracer_127x99_M",
            "CUP_100Rnd_TE4_Green_Tracer_127x99_M",
            "CUP_100Rnd_TE4_Yellow_Tracer_127x99_M",
            "CUP_100Rnd_TE4_White_Tracer_127x99_M",
            "CUP_100Rnd_TE1_Red_Tracer_127x99_M",
            "CUP_100Rnd_TE1_Green_Tracer_127x99_M",
            "CUP_100Rnd_TE1_Yellow_Tracer_127x99_M",
            "CUP_100Rnd_TE1_White_Tracer_127x99_M",
            "CUP_200Rnd_TE1_Red_Tracer_127x99_M"
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
        CUP_optic_SB_3_12x50_PMII = 1;
        CUP_optic_SB_3_12x50_PMII_Tan = 1;
        CUP_optic_SB_3_12x50_PMII_PIP = 1;
        CUP_optic_SB_3_12x50_PMII_Tan_PIP = 1;
        CUP_optic_AN_PAS_13c2 = 1;
        CUP_optic_AN_PAS_13c1 = 1;
        CUP_optic_CWS = 1;
        CUP_optic_CWS_NV = 1;
        CUP_optic_CWS_NV_RDS = 1;
        CUP_optic_AN_PVS_10 = 1;
        CUP_optic_AN_PVS_10_black = 1;
        CUP_optic_AN_PVS_10_od = 1;
        CUP_optic_SUSAT = 1;
        CUP_optic_SUSAT_PIP = 1;
        CUP_optic_SUSAT_3D = 1;
        CUP_optic_HoloBlack = 1;
        CUP_optic_HoloWdl = 1;
        CUP_optic_HoloDesert = 1;
        CUP_optic_Eotech533 = 1;
        CUP_optic_Eotech533Grey = 1;
        CUP_optic_Eotech553_OD = 1;
        CUP_optic_Eotech553_Black = 1;
        CUP_optic_Eotech553_Coyote = 1;
        CUP_optic_CompM2_Black = 1;
        CUP_optic_CompM2_Woodland = 1;
        CUP_optic_CompM2_Woodland2 = 1;
        CUP_optic_CompM2_Desert = 1;
        CUP_optic_CompM2_OD = 1;
        CUP_optic_CompM2_Coyote = 1;
        CUP_optic_CompM2_low = 1;
        CUP_optic_CompM2_low_OD = 1;
        CUP_optic_CompM2_low_coyote = 1;
        CUP_optic_CompM4 = 1;
        CUP_optic_MicroT1 = 1;
        CUP_optic_MicroT1_OD = 1;
        CUP_optic_MicroT1_coyote = 1;
        CUP_optic_MicroT1_low = 1;
        CUP_optic_MicroT1_low_OD = 1;
        CUP_optic_MicroT1_low_coyote = 1;
        CUP_optic_ACOG = 1;
        CUP_optic_ACOG_PIP = 1;
        CUP_optic_ACOG_3D = 1;
        CUP_optic_ACOG_Reflex_Desert = 1;
        CUP_optic_ACOG_Reflex_Desert_PIP = 1;
        CUP_optic_ACOG_Reflex_Desert_3D = 1;
        CUP_optic_ACOG_Reflex_Wood = 1;
        CUP_optic_ACOG_Reflex_Wood_PIP = 1;
        CUP_optic_ACOG_Reflex_Wood_3D = 1;
        CUP_optic_ACOG2 = 1;
        CUP_optic_ACOG2_PIP = 1;
        CUP_optic_ACOG2_3D = 1;
        CUP_optic_ACOG_TA31_KF = 1;
        CUP_optic_ACOG_TA31_KF_PIP = 1;
        CUP_optic_ACOG_TA31_KF_3D = 1;
        CUP_optic_ACOG_TA31_KF_Desert = 1;
        CUP_optic_ACOG_TA31_KF_Desert_PIP = 1;
        CUP_optic_ACOG_TA31_KF_Desert_3D = 1;
        CUP_optic_ACOG_TA31_KF_Wood = 1;
        CUP_optic_ACOG_TA31_KF_Wood_PIP = 1;
        CUP_optic_ACOG_TA31_KF_Wood_3D = 1;
        CUP_optic_RCO = 1;
        CUP_optic_ACOG_TA01NSN_Black_PIP = 1;
        CUP_optic_ACOG_TA01NSN_Black_3D = 1;
        CUP_optic_RCO_desert = 1;
        CUP_optic_ACOG_TA01NSN_Coyote_PIP = 1;
        CUP_optic_ACOG_TA01NSN_Coyote_3D = 1;
        CUP_optic_ACOG_TA01NSN_Tan = 1;
        CUP_optic_ACOG_TA01NSN_Tan_PIP = 1;
        CUP_optic_ACOG_TA01NSN_Tan_3D = 1;
        CUP_optic_ACOG_TA01NSN_OD = 1;
        CUP_optic_ACOG_TA01NSN_OD_PIP = 1;
        CUP_optic_ACOG_TA01NSN_OD_3D = 1;
        CUP_optic_ACOG_TA01NSN_Tropic = 1;
        CUP_optic_ACOG_TA01NSN_Tropic_PIP = 1;
        CUP_optic_ACOG_TA01NSN_Tropic_3D = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Black = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Black_PIP = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Black_3D = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Coyote = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Coyote_PIP = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Coyote_3D = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tan = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tan_PIP = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tan_3D = 1;
        CUP_optic_ACOG_TA01NSN_RMR_OD = 1;
        CUP_optic_ACOG_TA01NSN_RMR_OD_PIP = 1;
        CUP_optic_ACOG_TA01NSN_RMR_OD_3D = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tropic = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tropic_PIP = 1;
        CUP_optic_ACOG_TA01NSN_RMR_Tropic_3D = 1;
        CUP_optic_ACOG_TA01B_Black = 1;
        CUP_optic_ACOG_TA01B_Black_PIP = 1;
        CUP_optic_ACOG_TA01B_Black_3D = 1;
        CUP_optic_ACOG_TA01B_Coyote = 1;
        CUP_optic_ACOG_TA01B_Coyote_PIP = 1;
        CUP_optic_ACOG_TA01B_Coyote_3D = 1;
        CUP_optic_ACOG_TA01B_Tan = 1;
        CUP_optic_ACOG_TA01B_Tan_PIP = 1;
        CUP_optic_ACOG_TA01B_Tan_3D = 1;
        CUP_optic_ACOG_TA01B_OD = 1;
        CUP_optic_ACOG_TA01B_OD_PIP = 1;
        CUP_optic_ACOG_TA01B_OD_3D = 1;
        CUP_optic_ACOG_TA01B_Tropic = 1;
        CUP_optic_ACOG_TA01B_Tropic_PIP = 1;
        CUP_optic_ACOG_TA01B_Tropic_3D = 1;
        CUP_optic_ACOG_TA01B_RMR_Black = 1;
        CUP_optic_ACOG_TA01B_RMR_Black_PIP = 1;
        CUP_optic_ACOG_TA01B_RMR_Black_3D = 1;
        CUP_optic_ACOG_TA01B_RMR_Coyote = 1;
        CUP_optic_ACOG_TA01B_RMR_Coyote_PIP = 1;
        CUP_optic_ACOG_TA01B_RMR_Coyote_3D = 1;
        CUP_optic_ACOG_TA01B_RMR_Tan = 1;
        CUP_optic_ACOG_TA01B_RMR_Tan_PIP = 1;
        CUP_optic_ACOG_TA01B_RMR_Tan_3D = 1;
        CUP_optic_ACOG_TA01B_RMR_OD = 1;
        CUP_optic_ACOG_TA01B_RMR_OD_PIP = 1;
        CUP_optic_ACOG_TA01B_RMR_OD_3D = 1;
        CUP_optic_ACOG_TA01B_RMR_Tropic = 1;
        CUP_optic_ACOG_TA01B_RMR_Tropic_PIP = 1;
        CUP_optic_ACOG_TA01B_RMR_Tropic_3D = 1;
        CUP_optic_ACOG_TA648_308_RDS_Black = 1;
        CUP_optic_ACOG_TA648_308_RDS_Black_PIP = 1;
        CUP_optic_ACOG_TA648_308_Black = 1;
        CUP_optic_ACOG_TA648_308_Black_PIP = 1;
        CUP_optic_ACOG_TA648_308_RDS_Desert = 1;
        CUP_optic_ACOG_TA648_308_RDS_Desert_PIP = 1;
        CUP_optic_ACOG_TA648_308_Desert = 1;
        CUP_optic_ACOG_TA648_308_Desert_PIP = 1;
        CUP_optic_ACOG_TA648_308_RDS_Wdl = 1;
        CUP_optic_ACOG_TA648_308_RDS_Wdl_PIP = 1;
        CUP_optic_ACOG_TA648_308_Wdl = 1;
        CUP_optic_ACOG_TA648_308_Wdl_PIP = 1;
        CUP_optic_ACOG_TA648_308_RDS_od = 1;
        CUP_optic_ACOG_TA648_308_RDS_od_PIP = 1;
        CUP_optic_ACOG_TA648_308_od = 1;
        CUP_optic_ACOG_TA648_308_od_PIP = 1;
        CUP_optic_ACOG_TA648_308_RDS_coyo = 1;
        CUP_optic_ACOG_TA648_308_RDS_coyo_PIP = 1;
        CUP_optic_ACOG_TA648_308_coyo = 1;
        CUP_optic_ACOG_TA648_308_coyo_PIP = 1;
        CUP_optic_LeupoldMk4 = 1;
        CUP_optic_LeupoldMk4_pip = 1;
        CUP_optic_Leupold_VX3 = 1;
        CUP_optic_Leupold_VX3_pip = 1;
        CUP_optic_LeupoldM3LR = 1;
        CUP_optic_LeupoldM3LR_pip = 1;
        CUP_optic_LeupoldMk4_10x40_LRT_Desert = 1;
        CUP_optic_LeupoldMk4_10x40_LRT_Woodland = 1;
        CUP_optic_LeupoldMk4_10x40_LRT_Desert_pip = 1;
        CUP_optic_LeupoldMk4_10x40_LRT_Woodland_pip = 1;
        CUP_optic_LeupoldMk4_CQ_T = 1;
        CUP_optic_LeupoldMk4_MRT_tan = 1;
        CUP_optic_LeupoldMk4_MRT_tan_pip = 1;
        CUP_optic_LeupoldMk4_20x40_LRT = 1;
        CUP_optic_LeupoldMk4_20x40_LRT_pip = 1;
        CUP_optic_LeupoldMk4_25x50_LRT = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_pip = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_DESERT = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_DESERT_pip = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_SNOW = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_SNOW_pip = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_WOODLAND = 1;
        CUP_optic_LeupoldMk4_25x50_LRT_WOODLAND_pip = 1;
        CUP_optic_SB_11_4x20_PM = 1;
        CUP_optic_SB_11_4x20_PM_pip = 1;
        CUP_optic_SB_11_4x20_PM_tan = 1;
        CUP_optic_SB_11_4x20_PM_tan_pip = 1;
        CUP_optic_SB_11_4x20_PM_od = 1;
        CUP_optic_SB_11_4x20_PM_od_PIP = 1;
        CUP_optic_ZDDot = 1;
        CUP_optic_MRad = 1;
        CUP_optic_TrijiconRx01_desert = 1;
        CUP_optic_TrijiconRx01_black = 1;
        CUP_optic_TrijiconRx01_od = 1;
        CUP_optic_TrijiconRx01_kf_desert = 1;
        CUP_optic_TrijiconRx01_kf_black = 1;
        CUP_optic_TrijiconRx01_kf_od = 1;
        CUP_optic_AN_PVS_4 = 1;
        CUP_optic_AN_PVS_4_M14 = 1;
        CUP_optic_AN_PVS_4_M16 = 1;
        CUP_optic_Elcan_SpecterDR = 1;
        CUP_optic_Elcan_SpecterDR_pip = 1;
        CUP_optic_Elcan_SpecterDR_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF = 1;
        CUP_optic_Elcan_SpecterDR_KF_pip = 1;
        CUP_optic_Elcan_SpecterDR_KF_3D = 1;
        CUP_optic_Elcan_SpecterDR_RMR = 1;
        CUP_optic_Elcan_SpecterDR_RMR_pip = 1;
        CUP_optic_Elcan_SpecterDR_RMR_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_pip = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_3D = 1;
        CUP_optic_Elcan_SpecterDR_black = 1;
        CUP_optic_Elcan_SpecterDR_black_PIP = 1;
        CUP_optic_Elcan_SpecterDR_black_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_black = 1;
        CUP_optic_Elcan_SpecterDR_KF_black_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_black_3D = 1;
        CUP_optic_Elcan_SpecterDR_RMR_black = 1;
        CUP_optic_Elcan_SpecterDR_RMR_black_PIP = 1;
        CUP_optic_Elcan_SpecterDR_RMR_black_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_black = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_black_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_black_3D = 1;
        CUP_optic_Elcan_SpecterDR_coyote = 1;
        CUP_optic_Elcan_SpecterDR_coyote_PIP = 1;
        CUP_optic_Elcan_SpecterDR_coyote_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_coyote = 1;
        CUP_optic_Elcan_SpecterDR_KF_coyote_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_coyote_3D = 1;
        CUP_optic_Elcan_SpecterDR_RMR_coyote = 1;
        CUP_optic_Elcan_SpecterDR_RMR_coyote_PIP = 1;
        CUP_optic_Elcan_SpecterDR_RMR_coyote_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_coyote = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_coyote_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_coyote_3D = 1;
        CUP_optic_Elcan_SpecterDR_od = 1;
        CUP_optic_Elcan_SpecterDR_od_PIP = 1;
        CUP_optic_Elcan_SpecterDR_od_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_od = 1;
        CUP_optic_Elcan_SpecterDR_KF_od_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_od_3D = 1;
        CUP_optic_Elcan_SpecterDR_RMR_od = 1;
        CUP_optic_Elcan_SpecterDR_RMR_od_PIP = 1;
        CUP_optic_Elcan_SpecterDR_RMR_od_3D = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_od = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_od_PIP = 1;
        CUP_optic_Elcan_SpecterDR_KF_RMR_od_3D = 1;
        CUP_optic_Elcan = 1;
        CUP_optic_Elcan_pip = 1;
        CUP_optic_Elcan_3D = 1;
        CUP_optic_Elcan_OD = 1;
        CUP_optic_Elcan_OD_pip = 1;
        CUP_optic_Elcan_OD_3D = 1;
        CUP_optic_Elcan_Coyote = 1;
        CUP_optic_Elcan_Coyote_pip = 1;
        CUP_optic_Elcan_Coyote_3D = 1;
        CUP_optic_Elcan_reflex = 1;
        CUP_optic_Elcan_reflex_pip = 1;
        CUP_optic_Elcan_reflex_3D = 1;
        CUP_optic_Elcan_reflex_OD = 1;
        CUP_optic_Elcan_reflex_OD_pip = 1;
        CUP_optic_Elcan_reflex_OD_3D = 1;
        CUP_optic_Elcan_reflex_Coyote = 1;
        CUP_optic_Elcan_reflex_Coyote_pip = 1;
        CUP_optic_Elcan_reflex_Coyote_3D = 1;
        CUP_optic_ElcanM145 = 1;
        CUP_optic_ElcanM145_PIP = 1;
        CUP_optic_ElcanM145_3D = 1;
        CUP_optic_ZeissZPoint = 1;
        CUP_optic_ZeissZPoint_desert = 1;
        CUP_optic_ZeissZPoint_wood = 1;
        CUP_optic_ZeissZPoint_hex = 1;
        CUP_optic_MARS = 1;
        CUP_optic_MARS_OD = 1;
        CUP_optic_MARS_tan = 1;
        CUP_optic_MARS_V = 1;
        CUP_optic_MARS_OD_V = 1;
        CUP_optic_MARS_tan_V = 1;
        CUP_optic_ISM1400A7 = 1;
        CUP_optic_ISM1400A7_V = 1;
        CUP_optic_ISM1400A7_F = 1;
        CUP_optic_ISM1400A7_green = 1;
        CUP_optic_ISM1400A7_green_V = 1;
        CUP_optic_ISM1400A7_green_F = 1;
        CUP_optic_ISM1400A7_OD = 1;
        CUP_optic_ISM1400A7_OD_V = 1;
        CUP_optic_ISM1400A7_OD_F = 1;
        CUP_optic_ISM1400A7_tan = 1;
        CUP_optic_ISM1400A7_tan_V = 1;
        CUP_optic_ISM1400A7_tan_F = 1;
        CUP_optic_MEPRO = 1;
        CUP_optic_MEPRO_openx_orange = 1;
        CUP_optic_MEPRO_moa_clear = 1;
        CUP_optic_MEPRO_tri_clear = 1;
        CUP_optic_HensoldtZO = 1;
        CUP_optic_HensoldtZO_PIP = 1;
        CUP_optic_HensoldtZO_3D = 1;
        CUP_optic_HensoldtZO_RDS = 1;
        CUP_optic_HensoldtZO_RDS_PIP = 1;
        CUP_optic_HensoldtZO_RDS_3D = 1;
        CUP_optic_HensoldtZO_desert = 1;
        CUP_optic_HensoldtZO_desert_PIP = 1;
        CUP_optic_HensoldtZO_desert_3D = 1;
        CUP_optic_HensoldtZO_RDS_desert = 1;
        CUP_optic_HensoldtZO_RDS_desert_PIP = 1;
        CUP_optic_HensoldtZO_RDS_desert_3D = 1;
        CUP_optic_HensoldtZO_hex = 1;
        CUP_optic_HensoldtZO_hex_PIP = 1;
        CUP_optic_HensoldtZO_hex_3D = 1;
        CUP_optic_HensoldtZO_RDS_hex = 1;
        CUP_optic_HensoldtZO_RDS_hex_PIP = 1;
        CUP_optic_HensoldtZO_RDS_hex_3D = 1;
        CUP_optic_HensoldtZO_od = 1;
        CUP_optic_HensoldtZO_od_PIP = 1;
        CUP_optic_HensoldtZO_od_3D = 1;
        CUP_optic_HensoldtZO_RDS_od = 1;
        CUP_optic_HensoldtZO_RDS_od_PIP = 1;
        CUP_optic_HensoldtZO_RDS_od_3D = 1;
        CUP_optic_HensoldtZO_coyote = 1;
        CUP_optic_HensoldtZO_coyote_PIP = 1;
        CUP_optic_HensoldtZO_coyote_3D = 1;
        CUP_optic_HensoldtZO_RDS_coyote = 1;
        CUP_optic_HensoldtZO_RDS_coyote_PIP = 1;
        CUP_optic_HensoldtZO_RDS_coyote_3D = 1;
        CUP_optic_HensoldtZO_low = 1;
        CUP_optic_HensoldtZO_low_PIP = 1;
        CUP_optic_HensoldtZO_low_3D = 1;
        CUP_optic_HensoldtZO_low_RDS = 1;
        CUP_optic_HensoldtZO_low_RDS_PIP = 1;
        CUP_optic_HensoldtZO_low_RDS_3D = 1;
        CUP_optic_HensoldtZO_low_desert = 1;
        CUP_optic_HensoldtZO_low_desert_PIP = 1;
        CUP_optic_HensoldtZO_low_desert_3D = 1;
        CUP_optic_HensoldtZO_low_RDS_desert = 1;
        CUP_optic_HensoldtZO_low_RDS_desert_PIP = 1;
        CUP_optic_HensoldtZO_low_RDS_desert_3D = 1;
        CUP_optic_HensoldtZO_low_hex = 1;
        CUP_optic_HensoldtZO_low_hex_PIP = 1;
        CUP_optic_HensoldtZO_low_hex_3D = 1;
        CUP_optic_HensoldtZO_low_RDS_hex = 1;
        CUP_optic_HensoldtZO_low_RDS_hex_PIP = 1;
        CUP_optic_HensoldtZO_low_RDS_hex_3D = 1;
        CUP_optic_HensoldtZO_low_od = 1;
        CUP_optic_HensoldtZO_low_od_PIP = 1;
        CUP_optic_HensoldtZO_low_od_3D = 1;
        CUP_optic_HensoldtZO_low_RDS_od = 1;
        CUP_optic_HensoldtZO_low_RDS_od_PIP = 1;
        CUP_optic_HensoldtZO_low_RDS_od_3D = 1;
        CUP_optic_HensoldtZO_low_coyote = 1;
        CUP_optic_HensoldtZO_low_coyote_PIP = 1;
        CUP_optic_HensoldtZO_low_coyote_3D = 1;
        CUP_optic_HensoldtZO_low_RDS_coyote = 1;
        CUP_optic_HensoldtZO_low_RDS_coyote_PIP = 1;
        CUP_optic_HensoldtZO_low_RDS_coyote_3D = 1;
        CUP_optic_G33_HWS_BLK = 1;
        CUP_optic_G33_HWS_BLK_DWN = 1;
        CUP_optic_G33_HWS_TAN = 1;
        CUP_optic_G33_HWS_TAN_DWN = 1;
        CUP_optic_G33_HWS_OD = 1;
        CUP_optic_G33_HWS_OD_DWN = 1;
        CUP_optic_G33_HWS_COYOTE = 1;
        CUP_optic_G33_HWS_COYOTE_DWN = 1;
        CUP_optic_AIMM_COMPM4_BLK = 1;
        CUP_optic_AIMM_COMPM4_BLK_DWN = 1;
        CUP_optic_AIMM_COMPM2_BLK = 1;
        CUP_optic_AIMM_COMPM2_BLK_DWN = 1;
        CUP_optic_AIMM_COMPM2_TAN = 1;
        CUP_optic_AIMM_COMPM2_TAN_DWN = 1;
        CUP_optic_AIMM_COMPM2_OD = 1;
        CUP_optic_AIMM_COMPM2_OD_DWN = 1;
        CUP_optic_AIMM_MICROT1_BLK = 1;
        CUP_optic_AIMM_MICROT1_BLK_DWN = 1;
        CUP_optic_AIMM_MICROT1_TAN = 1;
        CUP_optic_AIMM_MICROT1_TAN_DWN = 1;
        CUP_optic_AIMM_MICROT1_OD = 1;
        CUP_optic_AIMM_MICROT1_OD_DWN = 1;
        CUP_optic_AIMM_ZDDOT_BLK = 1;
        CUP_optic_AIMM_ZDDOT_BLK_DWN = 1;
        CUP_optic_AIMM_MARS_BLK = 1;
        CUP_optic_AIMM_MARS_BLK_DWN = 1;
        CUP_optic_AIMM_MARS_TAN = 1;
        CUP_optic_AIMM_MARS_TAN_DWN = 1;
        CUP_optic_AIMM_MARS_OD = 1;
        CUP_optic_AIMM_MARS_OD_DWN = 1;
        CUP_optic_AIMM_M68_BLK = 1;
        CUP_optic_AIMM_M68_BLK_DWN = 1;
        CUP_optic_AIMM_M68_TAN = 1;
        CUP_optic_AIMM_M68_TAN_DWN = 1;
        CUP_optic_AIMM_M68_OD = 1;
        CUP_optic_AIMM_M68_OD_DWN = 1;
        CUP_optic_AC11704_Black = 1;
        CUP_optic_AC11704_Tan = 1;
        CUP_optic_AC11704_Coyote = 1;
        CUP_optic_AC11704_OD = 1;
        CUP_optic_AC11704_Jungle = 1;
        CUP_optic_VortexRazor_UH1_Black = 1;
        CUP_optic_VortexRazor_UH1_Coyote = 1;
        CUP_optic_VortexRazor_UH1_Khaki = 1;
        CUP_optic_VortexRazor_UH1_OD = 1;
        CUP_optic_VortexRazor_UH1_Tan = 1;
        CUP_optic_Aimpoint_5000 = 1;
        CUP_optic_SERedDot = 1;
    };
};
