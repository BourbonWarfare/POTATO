class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

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

    // add zeroing to iron sighted G36es
    class hlc_G36_base;
    class hlc_rifle_G36V : hlc_G36_base {
        discreteDistance[] = {100, 200, 300, 400, 500};
        discreteDistanceInitIndex = 1;
    };

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
    class rhsgref_alice_webbing_bwArmorMod: CUP_V_B_Alice { // must keep old classname, but this is now based on CUP
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
    class Vest_Camo_Base: ItemCore {
        class ItemInfo;
    };
    class CUP_V_CDF_CrewBelt: Vest_Camo_Base {
        class ItemInfo: ItemInfo {};
    };
    class CUP_V_CDF_CrewBelt_bwArmorMod: CUP_V_CDF_CrewBelt {
        displayName = "Vydra-3M [coop plot armor]";
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

    class mgun;
    class cup_vlmg_m134_veh: mgun {
        class lowrof: mode_fullauto {
            class standardsound {
                // JSRS uses 
                // soundsetshot[] = {"jsrs_m134_shot_soundset","jsrs_5x56mm_reverb_soundset"};
                // but you cannot hear at range?? Just revert back to cup's
                soundSetShot[] = {"CUP_M134_Shot_SoundSet","CUP_mmg1_Tail_SoundSet"};
            };
        };
    };
};
