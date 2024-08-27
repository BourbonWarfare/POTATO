class CfgWeapons {
    class MMG_01_tan_F;
    class GVAR(MG5): MMG_01_tan_F {
        author = "Potato";
        displayName = "H&K MG5";
        descriptionShort = "General Purpose Machine Gun<br />Caliber: 7.62x51 mm";
        baseWeapon = QGVAR(MG5);
        recoil = "CUP_MG3_recoil";
        magazineWell[] = {"CBA_762x51_LINKS"};
        magazines[] = {
            "CUP_120Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M"
        };
    };
};