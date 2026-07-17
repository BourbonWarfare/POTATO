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
};

class CfgWorlds {
    class CAWorld;
    class Malden: CAWorld {
        cutscenes[] = {"Malden_intro"};
    };
};
