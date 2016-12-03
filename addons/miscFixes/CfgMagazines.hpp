class CfgMagazines {
    class CA_LauncherMagazine;
    class rhs_mag_smaw_HEAA: CA_LauncherMagazine {
        mass = 80;
    };
    class rhs_mag_smaw_HEDP: CA_LauncherMagazine {
        mass = 65;
    };

    class rhs_30Rnd_762x39mm_tracer;
    class potato_75Rnd_762x39mm_tracer: rhs_30Rnd_762x39mm_tracer {
        author = "POTATO";
        count = 75;
        descriptionShort = "Caliber: 7.62x39mm<br/>Rounds: 75<br/>Used in: RPK";
        displayName = "57-N-231P 75 round Drum Mag";
        mass = 25;
        picture = "\CUP\Weapons\CUP_Weapons_Ammunition\data\ui\M_RPK_74_CA.paa";
    };

    // shim framework HLC mags
    class hlc_75Rnd_762x39_m_rpk: POTATO_75Rnd_762x39mm_tracer {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
    };
    class CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M;
    class hlc_60Rnd_545x39_t_rpk: CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
    };
    class CUP_1Rnd_HE_GP25_M;
    class hlc_VOG25_AK: CUP_1Rnd_HE_GP25_M {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
    };
    class CUP_1Rnd_SMOKE_GP25_M;
    class hlc_GRD_White: CUP_1Rnd_SMOKE_GP25_M {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
    };
    class CUP_1Rnd_SmokeRed_GP25_M;
    class hlc_GRD_Red: CUP_1Rnd_SmokeRed_GP25_M {
        scope = 1;
        scopeArsenal = 1;
        scopeCurator = 1;
    };
};
