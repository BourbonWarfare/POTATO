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
    class launch_NLAW_F;
    class potato_nlaw_dumb: launch_NLAW_F {
        author = "POTATO";
        canLock = 0;
        displayname = "NLAW (Dumb)";
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
};
