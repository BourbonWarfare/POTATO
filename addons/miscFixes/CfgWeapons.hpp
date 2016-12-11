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
            "rhs_30Rnd_762x39mm_U", "CUP_30Rnd_762x39_AK47_M",
            "hlc_75Rnd_762x39_m_rpk" // shimmed mag, remve eventually
        };
    };

    // shim HLC framework weapons
    class hlc_rifle_rpk: POTATO_arifle_RPK {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "RPK (Shim)";
    };
    class hlc_rifle_rpk74n: CUP_arifle_RPK74 {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "RPK-74 (Shim)";
    };
    class CUP_arifle_AKS74U;
    class hlc_rifle_aks74u: CUP_arifle_AKS74U {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "AKS-74U (Shim)";
    };
    class CUP_arifle_AK74;
    class hlc_rifle_ak74_dirty: CUP_arifle_AK74 {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "AK-74 (Shim)";
    };
    class CUP_arifle_AK74_GL;
    class hlc_rifle_aks74_GL: CUP_arifle_AK74_GL {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "AK-74 GP-25 (Shim)";
    };
    class CUP_arifle_AKS74;
    class hlc_rifle_aks74: CUP_arifle_AKS74 {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
        author = "POTATO";
        displayname = "AKS-74 (Shim)";
    };
};
