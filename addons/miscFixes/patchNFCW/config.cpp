#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchNFCW

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            QGVARMAIN(NFCW_122_RSKES_APILAS),
            QGVARMAIN(NFCW_122_RSKES_APILAS_used),
            QGVARMAIN(NFCW_122_RSKES_APILAS_loaded)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "NFCW_weapons_cfg",
            "NFCW_Cfg_Factions",
            "NFCW_cfg_sound"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
    class NFCW_Extras_GM {
        requiredAddons[] += {
            "gm_vehicles_land_tracked_bmp1_gc_army_bmp1",
            "gm_vehicles_land_wheeled_brdm2",
            "gm_vehicles_land_tracked_t55",
            "gm_vehicles_land_wheeled_uaz469",
            "gm_vehicles_land_wheeled_typ2_ge_army_typ2"
        };
    };
};

class CfgAmmo {
    class B_9x21_Ball;
    class B_NFCW_9x19: B_9x21_Ball {
        caliber = 0.4;
        hit = 6;
    };
};

class CBA_DisposableLaunchers {
    GVARMAIN(NFCW_122_RSKES_APILAS_loaded)[] = {QGVARMAIN(NFCW_122_RSKES_APILAS),QGVARMAIN(NFCW_122_RSKES_APILAS_used)};
};

class CfgMagazines {
    class CA_LauncherMagazine;
    class NFCW_122_RSKES_APILAS_RAK: CA_LauncherMagazine {
        mass = 72;
    };
};

#define ATTENUATE_3DB(initial) initial*10^0.15
#define ATTENUATE_6DB(initial) initial*0.5
class CfgSoundSets {
    class NFCW_kvkk_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(1.5);
    };
    class NFCW_kvkk_Tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_m91_Shot_soundSet {
        volumeFactor = ATTENUATE_3DB(2);
    };
    class NFCW_mosin_Tail_soundSet {
        volumeFactor = ATTENUATE_3DB(1);
    };
    class NFCW_LS26_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(2);
    };
    class NFCW_ls26_tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_rk62_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(1.5);
    };
    class NFCW_rk_Tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_rk_TailDistant_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_rk_TailDistantInt_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_kp31_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(1.5);
    };
    class NFCW_kp31_Tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1.5);
    };
    class NFCW_DP27_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(2);
    };
    class NFCW_DP27_Tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
    class NFCW_apilas_Shot_soundSet {
        volumeFactor = ATTENUATE_3DB(1);
    };
    class NFCW_apilas_Tail_soundSet {
        volumeFactor = ATTENUATE_3DB(1);
    };
    class NFCW_55s55_Shot_soundSet {
        volumeFactor = ATTENUATE_3DB(1);
    };
    class NFCW_55s55_Tail_soundSet {
        volumeFactor = ATTENUATE_3DB(1);
    };
    class NFCW_sten_Shot_soundSet {
        volumeFactor = ATTENUATE_6DB(1.5);
    };
    class NFCW_sten_Tail_soundSet {
        volumeFactor = ATTENUATE_6DB(1);
    };
};

class CfgVehicles {
    class NFCW_FIN_SA150;
    class NFCW_FIN_80_SA150: NFCW_FIN_SA150 {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_80_UN_SA150: NFCW_FIN_SA150 {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_80_W_SA150: NFCW_FIN_SA150 {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_Maxim_SOV_Medium;
    class I_NFCW_FIN_80_Maxim_SOV_Medium: NFCW_FIN_Maxim_SOV_Medium {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_80_W_Maxim_SOV_Medium: NFCW_FIN_Maxim_SOV_Medium {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_Maxim_SOV_High;
    class I_NFCW_FIN_80_Maxim_SOV_High: NFCW_FIN_Maxim_SOV_High {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_FIN_80_W_Maxim_SOV_High: NFCW_FIN_Maxim_SOV_High {
        scope = 1;
        scopeArsenal = 1;
    };
};

// Attachments base class fixing
class CowsSlot;
class CowsSlot_NFCW_RK62: CowsSlot {
    iconScale = 0.25;
};
class CowsSlot_NFCW_RK62_Early: CowsSlot {
    iconScale = 0.25;
};
class CowsSlot_NFCW_RK62M: CowsSlot {
    iconScale = 0.25;
};
class MuzzleSlot;
class MuzzleSlot_NFCW_RK62M: MuzzleSlot {
    iconScale = 0.25;
};

class UnderBarrelSlot;
class UnderBarrelSlot_NFCW_RK62: UnderBarrelSlot {
    iconScale = 0.25;
};
class UnderBarrelSlot_NFCW_RK62M: UnderBarrelSlot {
    iconScale = 0.25;
};

class InventoryUnderItem_Base_F;
class InventoryOpticsItem_Base_F;
class InventoryMuzzleItem_Base_F;
class Mode_FullAuto;
class Mode_SemiAuto;
class CfgWeapons {
    // Hide the LAWs
    class Launcher_Base_F;
    class NFCW_66_KES_75: Launcher_Base_F {
        scope = 1;
        scopeArsenal = 1;
    };
    class NFCW_66_KES_88: Launcher_Base_F {
        scope = 1;
        scopeArsenal = 1;
    };
    // Disposable APILAS
    class NFCW_122_RSKES_APILAS: Launcher_Base_F {
        scope = 1;
        scopeArsenal = 1;
        class EventHandlers;
        class WeaponSlotsInfo;
    };
    class GVARMAIN(NFCW_122_RSKES_APILAS_loaded): NFCW_122_RSKES_APILAS {
        baseWeapon = QGVARMAIN(NFCW_122_RSKES_APILAS);
        magazineReloadTime = 0;
        class EventHandlers: EventHandlers {
            fired = "_this call CBA_fnc_firedDisposable";
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
    };
    class GVARMAIN(NFCW_122_RSKES_APILAS): GVARMAIN(NFCW_122_RSKES_APILAS_loaded) {
        baseWeapon = QGVARMAIN(NFCW_122_RSKES_APILAS);
        magazines[] = {"CBA_FakeLauncherMagazine"};
        model = "\nf\NFCW\addons\nfcw_weapons\122_RSKES_APILAS\122_RSKES_APILAS.p3d";
        scope = 2;
        scopeArsenal = 2;
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108 + 72;
        };
    };
    class GVARMAIN(NFCW_122_RSKES_APILAS_used): GVARMAIN(NFCW_122_RSKES_APILAS_loaded) {
        baseWeapon = QGVARMAIN(NFCW_122_RSKES_APILAS);
        displayName = "$STR_NFCW_NAME122RSKESAPILAS_USED";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        model = "\nf\NFCW\addons\nfcw_weapons\122_RSKES_APILAS\122_RSKES_APILAS_usedWpn.p3d";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
    };
    // Fix weapon items
    class ItemCore;
    class NFCW_RK_62_Bayonet: ItemCore {
        IMS_Bayonet_Item = "True";
        class ItemInfo: InventoryUnderItem_Base_F {
            alternativeFire = "Zasleh2";
            muzzleEnd = "ZaslehPoint";
            class AmmoCoef {
                airFriction = 1;
                audibleFire = 1;
                audibleFireTime = 1;
                cost = 1;
                hit = 1;
                typicalSpeed = 1;
                visibleFire = 1;
                visibleFireTime = 1;
            };
            class MuzzleCoef {
                artilleryDispersionCoef = "1.0f";
                dispersionCoef = "1.0f";
                fireLightCoef = "1.0f";
                maxRangeCoef = "1.0f";
                maxRangeProbabCoef = "1.0f";
                midRangeCoef = "1.0f";
                midRangeProbabCoef = "1.0f";
                minRangeCoef = "1.0f";
                minRangeProbabCoef = "1.0f";
                recoilCoef = "1.0f";
                recoilProneCoef = "1.0f";
            };
        };
    };
    class NFCW_RK_62_VV2000: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class NVS {
                    visionMode[] = {"NVG"};
                };
            };
        };
    };
    class NFCW_RK_62M_CoverLug: ItemCore {
        class ItemInfo: InventoryMuzzleItem_Base_F {
            alternativeFire = "Zasleh2";
            muzzleEnd = "ZaslehPoint";
            soundTypeIndex = 0;
            class AmmoCoef {
                airFriction = 1;
                audibleFire = 1;
                audibleFireTime = 1;
                cost = 1;
                hit = 1;
                typicalSpeed = 1;
                visibleFire = 1;
                visibleFireTime = 1;
            };
            class MuzzleCoef {
                artilleryDispersionCoef = "1.0f";
                dispersionCoef = "1.0f";
                fireLightCoef = "1.0f";
                maxRangeCoef = "1.0f";
                maxRangeProbabCoef = "1.0f";
                midRangeCoef = "1.0f";
                midRangeProbabCoef = "1.0f";
                minRangeCoef = "1.0f";
                minRangeProbabCoef = "1.0f";
                recoilCoef = "1.0f";
                recoilProneCoef = "1.0f";
            };
        };
    };
    class NFCW_RK_62M_MuzzleBrake: ItemCore {
        class ItemInfo: InventoryMuzzleItem_Base_F {
            alternativeFire = "Zasleh2";
            muzzleEnd = "ZaslehPoint";
            soundTypeIndex = 0;
            class AmmoCoef {
                airFriction = 1;
                audibleFire = 0.9;
                audibleFireTime = 1;
                cost = 1;
                hit = 1;
                typicalSpeed = 1;
                visibleFire = 0.5;
                visibleFireTime = 0.5;
            };
            class MuzzleCoef {
                artilleryDispersionCoef = "1.0f";
                dispersionCoef = "1.0f";
                fireLightCoef = "0.5f";
                maxRangeCoef = "1.0f";
                maxRangeProbabCoef = "1.0f";
                midRangeCoef = "1.0f";
                midRangeProbabCoef = "1.0f";
                minRangeCoef = "1.0f";
                minRangeProbabCoef = "1.0f";
                recoilCoef = "0.85f";
                recoilProneCoef = "0.85f";
            };
        };
    };
    class NFCW_RK_62M_Supressor: ItemCore {
        class ItemInfo: InventoryMuzzleItem_Base_F {
            alternativeFire = "Zasleh2";
            muzzleEnd = "ZaslehPoint";
            soundTypeIndex = 1;
            class AmmoCoef {
                airFriction = 1;
                audibleFire = 0.07;
                audibleFireTime = 0.5;
                cost = 1;
                hit = 1;
                typicalSpeed = 1;
                visibleFire = 0.5;
                visibleFireTime = 0.5;
            };
            class MagazineCoef {
                initSpeed = 1.05;
            };
            class MuzzleCoef {
                artilleryDispersionCoef = "1.0f";
                dispersionCoef = "0.85f";
                fireLightCoef = "0.15f";
                maxRangeCoef = "1.0f";
                maxRangeProbabCoef = "1.0f";
                midRangeCoef = "1.0f";
                midRangeProbabCoef = "1.0f";
                minRangeCoef = "1.0f";
                minRangeProbabCoef = "1.0f";
                recoilCoef = "0.9f";
                recoilProneCoef = "0.5f";
            };
        };
    };
    // Fix silencer and icons
    class Rifle_Base_F;
    class NFCW_762_RK_62: Rifle_Base_F {
        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound", "SilencedSound"};
            class SilencedSound {
                // JSRS - REPLACE FOR JSRS2025
                soundSetShot[] = {"jsrs_ak12_shot_silenced_soundset", "jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound", "SilencedSound"};
            class SilencedSound {
                // JSRS - REPLACE FOR JSRS2025
                soundSetShot[] = {"jsrs_ak12_shot_silenced_soundset", "jsrs_7x62mm_sd_reverb_soundset"};
            };
        };
        class WeaponSlotsInfo {
            class CowsSlot: CowsSlot_NFCW_RK62 {
                iconScale = 0.25;
            };
            class UnderBarrelSlot: UnderBarrelSlot_NFCW_RK62 {
                iconScale = 0.25;
            };
        };
    };
    class NFCW_762_RK_62_M1: NFCW_762_RK_62 {
        class WeaponSlotsInfo {
            class CowsSlot: CowsSlot_NFCW_RK62M {
                iconScale = 0.25;
            };
            class MuzzleSlot: MuzzleSlot_NFCW_RK62M {
                iconScale = 0.25;
            };
            class UnderBarrelSlot: UnderBarrelSlot_NFCW_RK62M {
                iconScale = 0.25;
            };
        };
    };
};

