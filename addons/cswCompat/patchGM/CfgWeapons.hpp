class CfgWeapons {

    //// Carryable weapons
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };

    /// Milan
    class GVAR(gm_milan_backpack): Launcher_Base_F {
        class ACE_CSW {
            type = "mount";
            deployTime = 4;
            pickupTime = 4;
            deploy = "gm_ge_army_milan_launcher_tripod_csw";
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class MuzzleSlot {
                iconScale = 0.1;
            };
            mass = 362; // 16.4 kg
        };
        displayName = "[CSW] MILAN (GM)";
        author = "Lambda.Tiger";
        scope = 1;
        scopeArsenal = 1;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = "\gm\gm_weapons\gm_launchers\gm_milan\data\ui\picture_gm_milan_launcher_weaponBag_ca";
    };

    /// Fagot
    class GVAR(gm_fagot_backpack): Launcher_Base_F {
        class ACE_CSW {
            type = "mount";
            deployTime = 4;
            pickupTime = 4;
            deploy = "gm_gc_army_fagot_launcher_tripod_csw";
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class MuzzleSlot {
                iconScale = 0.1;
            };
            mass = 496; // 22.5 kg
        };
        displayName = "[CSW] Fagot (GM)";
        author = "Lambda.Tiger";
        scope = 1;
        scopeArsenal = 1;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = "\gm\gm_weapons\gm_launchers\gm_fagot\data\ui\picture_gm_fagot_launcher_weaponBag_ca";
    };

    /// MG3
    // Weapon
    class gm_mg3_base;
    class gm_mg3_blk: gm_mg3_base {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                GVAR(gm_MG3Tripod) = "gm_ge_army_mg3_aatripod_csw";
            };
        };
    };

    // Tripod
    class ace_csw_m3CarryTripod: Launcher_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {};
    };
    class GVAR(gm_MG3TripodCarry): ace_csw_m3CarryTripod {
        scope = 1;
        scopeArsenal = 1;
        class ACE_CSW {
            type = "mount";
            deployTime = 4;
            pickupTime = 4;
            deploy = QGVAR(gm_MG3Tripod);
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 256; // fun number
        };
        displayName = "[CSW] MG3 AA Tripod";
        icon = "\gm\gm_weapons\gm_machineguns\gm_mg3\data\ui\map_gm_mg3_aatripod_ca";
        picture = "\gm\gm_weapons\gm_machineguns\gm_mg3\data\ui\picture_gm_mg3_aatripod_weaponBag_ca";
    };

    //// Proxy Weapons
    class gm_milan_launcher;
    class GVAR(gm_milan_launcher_proxy): gm_milan_launcher {
        magazineReloadTime = 0.5;
    };

    class gm_fagot_launcher;
    class GVAR(gm_fagot_launcher_proxy): gm_fagot_launcher {
        magazineReloadTime = 0.5;
    };
};
