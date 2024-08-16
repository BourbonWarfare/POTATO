#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder", "CUP_Vehicles_LoadOrder", "CUP_Creatures_People_LoadOrder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class DefaultEventHandlers;
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
};
