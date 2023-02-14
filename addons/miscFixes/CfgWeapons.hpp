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
};
