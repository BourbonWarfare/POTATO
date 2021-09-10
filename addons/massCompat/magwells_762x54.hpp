    class CBA_762x54R_DPM {};           // DP-27, DP-28, DPM, Degtyaryov LMG
    class CBA_762x54R_DT {};            // DT, DTM LMG

    class CBA_762x54R_LINKS {           // Links for PK, PKM, and similar
        GVAR(mags)[] = {
            MAGAZINE_WELL_BOX(762x54,100),
            MAGAZINE_WELL_BOX(762x54,150)
        };
        GVAR(oldMissionsCompat)[] = {
            "150Rnd_762x54_Box_Tracer_Red", // these are from potato_miscFixes for some reason
            "150Rnd_762x54_Box_Tracer_Yellow", 
            "100Rnd_762x54_Box_Tracer_Green", 
            "100Rnd_762x54_Box_Tracer_Red", 
            "100Rnd_762x54_Box_Tracer_Yellow"
        };
    };

    class CBA_762x54R_Maxim {};         // Maxim gun in 7.62x54R
    class CBA_762x54R_Mosin {
        GVAR(mags)[] = {
            MAGAZINE_WELL_MAG(762x54,5),
        };
    };         // M91/30, M38, M44 Mosin

    class CBA_762x54R_RP46 {};          // RP-46

    class CBA_762x54R_SVD {             // SVD
        GVAR(mags)[] = {
            MAGAZINE_WELL_MAG(762x54,10),
        };
    };

    class CBA_762x54R_SVT {};           // SVT-38, SVT-40

    class CBA_762x54R_Vz59_LINKS {
        GVAR(mags)[] = {
            MAGAZINE_WELL_MAG(762x54,50),
        };
        GVAR(oldMissionsCompat)[] = {
            "100rnd_762x54_box_tracer_red",
            "100Rnd_762x54_Box_Tracer_Green",
            "cup_100rnd_te4_lrt4_762x54_pk_tracer_green_m"
        };
    };    //Uk vz. 59, UK59, vz 59
