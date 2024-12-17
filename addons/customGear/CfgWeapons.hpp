class CfgWeapons {
    // Adds MG5 in 7.62x51mm
    class MMG_01_tan_F;
    class potato_fauxMG5_MG5: MMG_01_tan_F {
        author = "Potato";
        displayName = "H&K MG5";
        descriptionShort = "General Purpose Machine Gun<br />Caliber: 7.62x51 mm";
        baseWeapon = "potato_fauxMG5_MG5";
        recoil = "CUP_MG3_recoil";
        magazineWell[] = {"CBA_762x51_LINKS"};
        magazines[] = {
            "CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M"
        };
    };

    // Adds 40x53mm potato grenades
    class GMG_F;
    class GMG_40mm: GMG_F {
        magazineWell[] += {QMAGWELL(HV_40x53mm)};
    };
};
