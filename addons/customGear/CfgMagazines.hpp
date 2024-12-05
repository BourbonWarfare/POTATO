class CfgMagazines {
    // LV 40x46mm grenade magazines (M203, EGLM)
    class 1Rnd_HE_Grenade_shell;
    class MAGAZINE(1Rnd_40mm_M433_HEDP): 1Rnd_HE_Grenade_shell {
        ammo = QAMMO(40x46mm_HE_M433);
        count = 1;
        displayNameshort = "M433 HEDP";
        displayName = "M433 40x46mm HEDP";
    };

    // HV 40x53mm grenade launcher
    class 200Rnd_40mm_G_belt;
    class MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HEDP_M430A1);
        count = 96;
        displayNameshort = "M430A1 HEDP";
        displayName = "M430A1 40x53mm HEDP";
        initSpeed = 241;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M430A1_HEDP): MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP) {
        count = 48;
    };
    class MAGAZINE(96Rnd_40mm_MK19_M384_HE): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HE_M384);
        count = 96;
        displayNameshort = "M384 HE";
        displayName = "M384 40x53mm HE";
        initSpeed = 241;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M384_HE): MAGAZINE(96Rnd_40mm_MK19_M384_HE) {
        count = 48;
    };
};