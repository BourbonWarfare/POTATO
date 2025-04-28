#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCWRBAF

#define POTFIX(var1) DOUBLES(PREFIX,var1)
#define QPOTFIX(var1) QUOTE(POTFIX(var1))

#define MAG_2(mag) mag,mag
#define MAG_4(mag) MAG_2(mag),MAG_2(mag)
#define MAG_8(mag) MAG_4(mag),MAG_4(mag)
#define MAG_16(mag) MAG_8(mag),MAG_8(mag)
#define MAG_20(mag) MAG_16(mag),MAG_4(mag)

class CfgPatches {
    class ADDON {
        units[] = {
            QPOTFIX(cwr3_b_uk_fv107),
            QPOTFIX(cwr3_b_uk_fv107_unstab)
        };
        weapons[] = {
            QPOTFIX(CUP_Rarden_CTWS_veh)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "cwr3_vehicle_fv101_uk", "cwr3_javelin_uk" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgMagazines {
    class CUP_200Rnd_TE1_Red_Tracer_30mmGPR_M;
    class POTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M): CUP_200Rnd_TE1_Red_Tracer_30mmGPR_M {
        displayName = "6Rnd 40mm (GPR-T)";
        count = 6;
        displayNameShort = "30mm GPR-T";
    };

    class CUP_200Rnd_TE1_Red_Tracer_30mmAPFSDS_M;
    class POTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M): CUP_200Rnd_TE1_Red_Tracer_30mmAPFSDS_M {
        displayName = "6Rnd 30mm (APFSDS-T)";
        displayNameShort = "30mm APFSDS-T";
        count = 6;
    };
    class cwr3_javelin_m;
    class GVAR(blowpipe_m): cwr3_javelin_m {
        displayName = "Blowpipe";
        displayNameShort = "Blowpipe";
        descriptionShort = "Range : 3500 m<br/>Type : ground-air<br/>Used in : Blowpipe";
        author = "CWR III (BW Config)";
        ammo = QGVAR(blowpipe_a);
    };
};
#include "\z\potato\addons\missileGuidanceCompat\CfgMissileTypesNato.hpp"
class CfgAmmo {
    class CUP_M_Stinger_AA;
    class GVAR(blowpipe_a): CUP_M_Stinger_AA {
        class ace_missileguidance: ACEGVAR(missileguidance,type_Blowpipe) {
            enabled = 1;
        };
    };
};

class CfgVehicles {
    class Tank;
    class Tank_F: Tank {
        class AnimationSources;
    };
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
        scope = 2;
        curatorScope = 2;
        displayName = "FV107 Scimitar (6Rnd)";
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
                class Components;
                class GunClouds;
                class GunFire;
                class HitPoints;
                class MGunClouds;
                class OpticsIn;
                class Reflectors;
                class TurnIn;
                class TurnOut;
                class Turrets;
                class TurretSpec;
                class ViewGunner;
                class ViewOptics;
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
                class Components;
                class GunClouds;
                class GunFire;
                class HitPoints;
                class MGunClouds;
                class OpticsIn;
                class Reflectors;
                class TurnIn;
                class TurnOut;
                class Turrets;
                class TurretSpec;
                class ViewGunner;
                class ViewOptics;
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

};

class CfgWeapons {
    class autocannon_40mm_CTWS;
    class CUP_Rarden_CTWS_veh: autocannon_40mm_CTWS {
        class AP;
        class HE;
    };
    class POTFIX(CUP_Rarden_CTWS_veh): CUP_Rarden_CTWS_veh {
        magazineReloadTime = 20;
        autoReload = 1;
        class AP: AP {
            magazineReloadTime = 3;
            magazines[] = {QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M)};
        };
        class HE: HE {
            magazineReloadTime = 3;
            magazines[] = {QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M)};
        };
    };
    class cwr3_launch_javelin;
    class GVAR(blowpipe): cwr3_launch_javelin {
        displayName = "Blowpipe";
        descriptionShort = "Blowpipe<br/>MCLOS Guided";
        author = "CWR III (BW Config)";
        baseWeapon = QGVAR(blowpipe);
        scope = 2;
        canLock = 0;
        magazines[] = {QGVAR(blowpipe_m)};
    };
};
