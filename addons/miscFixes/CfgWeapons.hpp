class CfgWeapons {
    // Add invisible NVGs for AI purposes
    class NVGoggles;
    class potato_fakeNVG: NVGoggles {
        author = "PabstMirror";
        modelOptics = QPATHTOF(models\plotNVGs);
        model = "\A3\weapons_f\empty";
        displayName = "Fake NVGs (AI Only)";
        descriptionShort = "[Plot Googles] Do not attempt to use as a player, only to allow AI to have better vision";
        class ItemInfo {
            type = 616;
            hmdType = 0;
            uniformModel = "\A3\weapons_f\empty";
            modelOff = "\A3\weapons_f\empty";
            mass = 20;
        };
    };

    // add predator NVGs
    class O_NVGoggles_hex_F;
    class potato_predatorHex: O_NVGoggles_hex_F {
        author = "POTATO";
        displayName = "Predator Vision (Hex)";
        thermalMode[] = {7};
        visionMode[] = {"Normal","NVG","TI"};
    };
    class O_NVGoggles_ghex_F;
    class potato_predatorGHex: O_NVGoggles_ghex_F {
        author = "POTATO";
        displayName = "Predator Vision (Green Hex)";
        thermalMode[] = {7};
        visionMode[] = {"Normal","NVG","TI"};
    };
    class O_NVGoggles_urb_F;
    class potato_predatorUrban: O_NVGoggles_urb_F {
        author = "POTATO";
        displayName = "Predator Vision (Urban)";
        thermalMode[] = {7};
        visionMode[] = {"Normal","NVG","TI"};
    };

    // create lighter SMAWs for playability
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };
    class rhs_weap_smaw: Launcher_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 70;
        };
    };

    // add zeroing to iron sighted G36es
    class hlc_rifle_G36E1;
    class hlc_rifle_G36V : hlc_rifle_G36E1 {
        class OpticsModes {
            class Kolimator {
                distancezoommax = 100;
                distancezoommin = 500;
                discreteDistance[] = {100, 200, 300, 400, 500};
                discreteDistanceInitIndex = 1;
            };
        };
    };
    class hlc_rifle_G36KE1;
    class hlc_rifle_G36KV : hlc_rifle_G36KE1 {
        class OpticsModes {
            class Kolimator {
                distancezoommax = 100;
                distancezoommin = 500;
                discreteDistance[] = {100, 200, 300, 400, 500};
                discreteDistanceInitIndex = 1;
            };
        };
    };

    // Create RPK from CUP RPK-74, just need to fill a gap
    class CUP_arifle_RPK74;
    class potato_arifle_RPK: CUP_arifle_RPK74 {
        author = "POTATO";
        displayname = "RPK";
        magazines[] = {
            "potato_75Rnd_762x39mm_tracer", "rhs_30Rnd_762x39mm",
            "rhs_30Rnd_762x39mm_tracer", "rhs_30Rnd_762x39mm_89",
            "rhs_30Rnd_762x39mm_U", "CUP_30Rnd_762x39_AK47_M"
        };
    };

    // disable M70's rifle grenades until RHS decides to add rifle grenades
    class rhs_weap_m70_base;
    class rhs_weap_m70ab2: rhs_weap_m70_base {
        muzzles[] = {"this", "SAFE"};
    };


    // Add "plot armor" to some vests
    class Vest_Camo_Base;
    class rhs_6b23: Vest_Camo_Base {
        class ItemInfo;
    };
    class rhsgref_alice_webbing: rhs_6b23 {
        class ItemInfo: ItemInfo {};
    };
    class rhsgref_alice_webbing_armorMod: rhsgref_alice_webbing {
        displayName = "ALICE Webbing [plot armor]";
        descriptionShort = "Armor Level IV";
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo { // From V_PlateCarrier2_rgr
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
};
