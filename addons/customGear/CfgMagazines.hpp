class CfgMagazines {
    // LV 40x46mm grenade magazines (M203, EGLM)
    class 1Rnd_HE_Grenade_shell;
    class MAGAZINE(1Rnd_40mm_M433_HEDP): 1Rnd_HE_Grenade_shell {
        ammo = QAMMO(40x46mm_HEDP_M433);
        count = 1;
        displayNameshort = "M433 HEDP";
        displayName = "40x46mm M433 (HEDP) Grenade";
    };

    // HV 40x53mm grenade launcher
    class 200Rnd_40mm_G_belt;
    class MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HEDP_M430A1);
        count = 96;
        displayNameshort = "M430A1 HEDP";
        displayName = "40x53mm M430A1 HEDP";
        initSpeed = 241;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M430A1_HEDP): MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP) {
        count = 48;
    };
    class MAGAZINE(96Rnd_40mm_MK19_M384_HE): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HE_M384);
        count = 96;
        displayNameshort = "M384 HE";
        displayName = "40x53mm M384 HE";
        initSpeed = 241;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M384_HE): MAGAZINE(96Rnd_40mm_MK19_M384_HE) {
        count = 48;
    };
};