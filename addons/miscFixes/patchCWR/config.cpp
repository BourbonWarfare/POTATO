#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCWR

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "potato_customGear", "cwr3_intro", "cwr3_vehicle_m41", "cwr3_soldiers_us", "cwr3_vehicle_m113", "cwr3_weapon_config" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMain {
        cwr3_intro = ""; // CWR gets rid of the editor/multiplayer/campaign buttons for some reason
    };
};

class CfgMagazines {
    class cwr3_12rnd_mm1_m;
    class potato_12Rnd_40mm_M433_HEDP: cwr3_12rnd_mm1_m {
        ammo = "potato_40x46mm_HEDP_M433";
        descriptionShort = "Type: High Explosive Dual Purpose<br/>Rounds: 6<br/>Used in: M32 grenade launcher";
        displayName = "40x46mm 12Rnd M433 (HEDP) Grenade";
        displayNameshort = "M433 HEDP";
    };
    class cwr3_500rnd_vickers_m;
    class GVARMAIN(cwr3_500rnd_vickers_t): cwr3_500rnd_vickers_m {
        tracersEvery = 1;
    };
};

class CfgMagazineWells {
    class CBA_Carl_Gustaf { // Default parameter is thrust = 0.1, thrustTime = 0.1, CWR does not do this
        cwr3_mags[] = {};
    };
    class CWR3_CARLGUSTAF {
        cup_magazines[] = {"CUP_MAAWS_HEAT_M","CUP_MAAWS_HEDP_M"};
    };
    class potato_CUP_Carl_Gustaf {
        cwr3_mags[] = {"cwr3_carlgustaf_hedp_m","cwr3_carlgustaf_heat_m"};
    };
};


class CfgWeapons {
    class Rifle_Base_F;
    class cwr3_glaunch_mm1: Rifle_Base_F {
        magazines[] += {"potato_12Rnd_40mm_M433_HEDP"};
    };
    class MGun;
    class cwr3_hmg_vickers_veh: MGun {
        magazines[] += {QGVARMAIN(cwr3_500rnd_vickers_t)};
    };
    class CUP_launch_MAAWS;
    class cwr3_launch_m67_rcl: CUP_launch_MAAWS {
        ACEGVAR(overpressure,angle) = 60;
        ACEGVAR(overpressure,offset) = 1.35;
        ACEGVAR(overpressure,range) = 28;
    };
    class Launcher_Base_F;
    class cwr3_launch_rpg75_loaded: Launcher_Base_F {
        ACEGVAR(overpressure,angle) = 33.7; // based on czech wikipedia backblast zone
        ACEGVAR(overpressure,offset) = 0.8;
        ACEGVAR(overpressure,range) = 20;
    };
};

class CfgVehicles {
    class Tank_F;
    class cwr3_m41_base: Tank_F {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.5;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.2;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.5;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 1;
    };
    class CUP_M113New_Base: Tank_F {
        class Turrets;
    };
    class CUP_M163New_Base: CUP_M113New_Base {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class cwr3_m901_itv_base: CUP_M163New_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"cwr3_2rnd_tow2","cwr3_2rnd_tow2","cwr3_2rnd_tow2","cwr3_2rnd_tow2","cwr3_2rnd_tow2","cwr3_2rnd_tow2"};
                weapons[] = {"cwr3_vmlauncher_tow_veh_m901"};
            };
        };
    };
    // HMD for ESS UH-60 - move to potato_hmd on introduction
    #define HMD_SIZE 0.1
    class cwr3_uh60_4xesss_dynamic_base;
    class cwr3_b_uh60_x4_esss: cwr3_uh60_4xesss_dynamic_base {
        class MFD {
            helmetMountedDisplay = 1;
            class ADDON {
                helmetMountedDisplay = 1;
                class Bones {
                    class ImpactPoint {
                        type = "vector";
                        source = "impactpointtoview";
                        pos0[] = {0.5, 0.5};
						pos10[]= {0.774, 0.77};
                    };
                    class ImpactPoint1 {
                        type = "vector";
                        source = "impactpointtoview";
                        pos0[] = {0.5, 0.5};
						pos10[]= {0.774, 0.77};
                    };
                    class WeaponAim {
                        type = "vector";
                        source = "weapontoview";
                        pos0[] = {0.5, 0.5};
						pos10[]= {0.774, 0.77};
                    };
                };
                color[] = {0,1,0,0.2};
                turret[] = {-1};
                alpha = "51 - (nvg * 15)";
                topLeft = "";
                topRight = "";
                bottomLeft = "";
                borderLeft = 0;
                borderRight = 0;
                borderTop = 0;
                borderBottom = 0;
                helmetPosition[] = {-HMD_SIZE/2, HMD_SIZE/2, 0.1};
                helmetRight[] = {HMD_SIZE, 0.0, 0.0};
                helmetDown[] = {0.0, -HMD_SIZE, 0.0};
                class Draw {
                    class MGun {
                        type = "group";
                        condition = "mgun";
                        class Target {
                            type = "line";
                            width = 0.5;
                            points[] = {
                                {"ImpactPoint",{0.005,0},1},
                                {"ImpactPoint",{-0.005,0},1},
                                {},
                                {"ImpactPoint",{0,0.005},1},
                                {"ImpactPoint",{0,-0.005},1},
                            };
                        };
                    };
                    class Rocket {
                        type = "group";
                        condition = "rocket";
                        class Target {
                            type = "line";
                            width = 1;
                            points[] = {
                                {"ImpactPoint1",{0.01,0},1},
                                {"ImpactPoint1",{-0.01,0},1},
                                {},
                                {"ImpactPoint1",{0,0.01},1},
                                {"ImpactPoint1",{0,-0.01},1},
                            };
                        };
                    };
                    class Missile { // From our CUP A10 MFD, may be from CUP
                        type = "group";
                        condition = "missile";
                        class Circle {
                            type = "line";
                            points[] = {
                                {"WeaponAim",{0,-0.198},1},
                                {"WeaponAim",{0.09,-0.17226},1},
                                {"WeaponAim",{0.1566,-0.099},1},
                                {"WeaponAim",{0.18,0},1},
                                {"WeaponAim",{0.1566,0.099},1},
                                {"WeaponAim",{0.09,0.17226},1},
                                {"WeaponAim",{0,0.198},1},
                                {"WeaponAim",{-0.09,0.17226},1},
                                {"WeaponAim",{-0.1566,0.099},1},
                                {"WeaponAim",{-0.18,0},1},
                                {"WeaponAim",{-0.1566,-0.099},1},
                                {"WeaponAim",{-0.09,-0.17226},1},
                                {"WeaponAim",{0,-0.198},1}
                            };
                        };
                    };
                };
            };
        };
    };
};

class CfgWorlds {
    class CAWorld;
    class Malden: CAWorld {
        cutscenes[] = {"Malden_intro"};
    };
};
