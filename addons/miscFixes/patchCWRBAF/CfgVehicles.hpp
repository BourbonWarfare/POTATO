class CfgVehicles {
    // Base classes
    class Tank;
    class Tank_F: Tank {
        class AnimationSources;
    };
    class Car_F;
    class Wheeled_APC_F: Car_F {
        class ACRE;
    };

    /// Unstabalize the vehicles
    // FV107
    class CUP_MCV80_Base: Tank_F {
        class Turrets;
    };
    class cwr3_b_uk_fv107: CUP_MCV80_Base {
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class POTFIX(cwr3_b_uk_fv107): cwr3_b_uk_fv107 {
        displayName = "FV107 Scimitar (6Rnd)";
        scope = 1;
        scopeCurator = 1;
        class AnimationSources: AnimationSources {
            class recoil_source {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_rot_ctws {
                source = "ammorandom";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_hide_ctws {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                discreteDistance[] = {100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100,2400};
                weapons[] = {
                    QPOTFIX(CUP_Rarden_CTWS_veh),
                    "CUP_Vlmg_L94A1_Coax"
                };
                magazines[] = {
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M)),
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M)),
                    MAG_2(QUOTE(CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M))
                };
            };
        };
    };
    class POTFIX(cwr3_b_uk_fv107_unstab): cwr3_b_uk_fv107 {
        displayName = "FV107 Scimitar (6Rnd, Unstab)";
        scope = 2;
        scopeCurator = 2;
        class AnimationSources: AnimationSources {
            class recoil_source {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_rot_ctws {
                source = "ammorandom";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_hide_ctws {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                discreteDistance[] = {100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100,2400};
                weapons[] = {
                    QPOTFIX(CUP_Rarden_CTWS_veh),
                    "CUP_Vlmg_L94A1_Coax"
                };
                magazines[] = {
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M)),
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M)),
                    MAG_2(QUOTE(CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M))
                };
                stabilizedInAxes = 0;
            };
        };
    };

    // FV101
    class cwr3_b_uk_fv101: cwr3_b_uk_fv107 {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };
    class POTFIX(cwr3_b_uk_fv101_unstab): cwr3_b_uk_fv101 {
        displayName = "FV101 Scorpion (Unstab)";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                stabilizedInAxes = 0;
            };
        };
    };
    // FV432
    class CUP_B_FV432_GB_GPMG;
    class cwr3_fv432_gpmg_base: CUP_B_FV432_GB_GPMG {
        class Turrets;
        class UserActions;
    };
    class cwr3_b_uk_fv432_gpmg: cwr3_fv432_gpmg_base {
        class Turrets: Turrets {
            class MainTurret;
            class Commander;
            class CargoTurret_04;
            class CargoTurret_05;
            class CargoTurret_07;
        };
        class UserActions: UserActions {
            class stow_gpmg;
        };
    };
    class GVARMAIN(cwr3_b_uk_fv432_gpmg_unstab): cwr3_b_uk_fv432_gpmg {
        displayName = "FV432 (GPMG, Unstab)";
        magazines[] = {"SmokeLauncherMag"};
        weapons[] = {"SmokeLauncher"};
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                forceHideGunner = 0;
                gunnerAction = "CUP_FV432_GunnerOut";
                gunnerInAction = "CUP_FV432_GunnerIn";
                gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
                gunnerDoor = "";
                inGunnerMayFire = 0;
                outGunnerMayFire = 1;
                magazines[] = {
                    "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                    "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                    "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                    "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                    "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"
                };
                memoryPointGunnerOptics = "gunnerviewin";
                memoryPointGunnerOutOptics = "gunnerview";
                stabilizedInAxes = 0;
                weapons[] = {"CUP_Vlmg_L7A2_veh"};
            };
            class Commander: Commander {
                stabilizedInAxes = 0;
            };
            class CargoTurret_04: CargoTurret_04 {};
            class CargoTurret_05: CargoTurret_05 {};
            class CargoTurret_07: CargoTurret_07 {};
        };
        class UserActions: UserActions {
            class stow_gpmg: stow_gpmg {
                condition = "this turretUnit [0] == player";
            };
        };
    };
    // Peak Turret
    class cwr3_b_uk_fv432_peak: cwr3_fv432_gpmg_base {
        class Turrets: Turrets {
            class Commander;
            class MainTurret;
        };
    };
    class GVARMAIN(cwr3_b_uk_fv432_peak_unstab): cwr3_b_uk_fv432_peak {
        displayName = "FV432 (Peak Turret, Unstab)";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                stabilizedInAxes = 0;
            };
            class Commander: Commander {};
        };
    };
    // FV510
    class cwr3_fv510_base;
    class cwr3_b_uk_fv510: cwr3_fv510_base {
        class Turrets;
    };
    class GVARMAIN(cwr3_b_uk_fv510_inbetween_unstab): cwr3_b_uk_fv510 {
        scope = 1;
        scopeCurator = 1;
        class AnimationSources;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(cwr3_b_uk_fv510_unstab): GVARMAIN(cwr3_b_uk_fv510_inbetween_unstab) {
        scope = 2;
        scopeCurator = 2;
        displayName = "FV510 Warrior (6Rnd, Unstab)";
        class AnimationSources: AnimationSources {
            class recoil_source {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_rot_ctws {
                source = "ammorandom";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
            class muzzle_hide_ctws {
                source = "reload";
                weapon = QPOTFIX(CUP_Rarden_CTWS_veh);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class OpticsIn {
                    class Wide {
                        gunnerOpticsEffect[] = {};
                        gunnerOpticsModel = "\cwr3\expansions\cwr3_expansion_uk\weapons\optic_scimitar.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.2;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.2;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.2;
                        thermalMode[] = {0};
                        visionMode[] = {"Normal","NVG"};
                    };
                    class Narrow {
                        gunnerOpticsModel = "\cwr3\expansions\cwr3_expansion_uk\weapons\optic_scimitar.p3d";
                        initFov = 0.039;
                        maxFov = 0.039;
                        minFov = 0.039;
                        gunnerOpticsEffect[] = {};
                        initAngleX = 0;
                        initAngleY = 0;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        minAngleX = -30;
                        minAngleY = -100;
                        thermalMode[] = {0};
                        visionMode[] = {"Normal","NVG"};
                    };
                };
                discreteDistance[] = {100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100,2400};
                weapons[] = {
                    QPOTFIX(CUP_Rarden_CTWS_veh),
                    "CUP_Vlmg_L94A1_Coax"
                };
                magazines[] = {
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M)),
                    MAG_20(QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M)),
                    MAG_2(QUOTE(CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M))
                };
                stabilizedInAxes = 0;
            };
        };
    };

    /// Fix Turret Compartments
    class CUP_LR_Base;
    class CUP_LR_Transport_Base: CUP_LR_Base {
        class Turrets;
    };
    class cwr3_landrover_base: CUP_LR_Transport_Base {
        class Turrets: Turrets {
            class CargoTurret_01;
            class CargoTurret_02;
        };
    };
    class cwr3_b_uk_landrover: cwr3_landrover_base {
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {
                gunnerCompartments = "Compartment1";
            };
            class CargoTurret_02: CargoTurret_02 {
                gunnerCompartments = "Compartment1";
            };
        };
    };

    /// ACRE Tweaks
    class CUP_GAZ_Vodnik_Base: Wheeled_APC_F {
        class ACRE: ACRE {
            class attenuation;
            class attenuationTurnedOut;
        };
    };
    class cwr3_b_uk_fv620_base: CUP_GAZ_Vodnik_Base {
        class ACRE: ACRE {
            class attenuation: attenuation {
                class Compartment1;
                class Compartment2;
            };
            class attenuationTurnedOut: attenuationTurnedOut {
                class Compartment1;
            };
        };
    };
    class cwr3_b_uk_fv620_transport: cwr3_b_uk_fv620_base {
        class ACRE: ACRE {
            class attenuation: attenuation {
                class Compartment1: Compartment1 {
                    Compartment1 = 0;
                    Compartment2 = 0.4;
                };
                class Compartment2: Compartment2 {
                    Compartment1 = 0.4;
                    Compartment2 = 0;
                };
            };
            class attenuationTurnedOut: attenuationTurnedOut {
                class Compartment1: Compartment1 {
                    Compartment1 = 0.25;
                    Compartment2 = 0.2;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
            };
        };
    };
};
