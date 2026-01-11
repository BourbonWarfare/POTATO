class CfgMagazines {
    // LV 40x46mm grenade magazines (M203, EGLM)
    class 1Rnd_HE_Grenade_shell;
    class MAGAZINE(1Rnd_40mm_M433_HEDP): 1Rnd_HE_Grenade_shell {
        ammo = QAMMO(40x46mm_HEDP_M433);
        count = 1;
        displayNameShort = "M433 HEDP";
        displayName = "40x46mm M433 (HEDP) Grenade";
    };

    class MAGAZINE(1Rnd_40mm_M576_MP): 1Rnd_HE_Grenade_shell {
        ammo = QAMMO(40x46mm_MP_M576);
        count = 1;
        displayNameShort = "M576 MP";
        displayName = "40x46mm M576 (MP) Canister";
        initSpeed = 269;
        mass = 2.4;
    };

    /// HV 40x53mm grenade launcher
    class 200Rnd_40mm_G_belt;
    class MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HEDP_M430A1);
        count = 96;
        displayNameShort = "M430A1 HEDP";
        displayName = "40x53mm M430A1 HEDP";
        initSpeed = 242;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M430A1_HEDP): MAGAZINE(96Rnd_40mm_MK19_M430A1_HEDP) {
        count = 48;
    };
    class MAGAZINE(96Rnd_40mm_MK19_M384_HE): 200Rnd_40mm_G_belt {
        ammo = QAMMO(40x53mm_HE_M384);
        count = 96;
        displayNameShort = "M384 HE";
        displayName = "40x53mm M384 HE";
        initSpeed = 241;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M384_HE): MAGAZINE(96Rnd_40mm_MK19_M384_HE) {
        count = 48;
    };
    // HV 40x53mm grenade CSW
    class MAGAZINE(48Rnd_40mm_MK19_M430A1_HEDP_csw): MAGAZINE(48Rnd_40mm_MK19_M430A1_HEDP) {
        displayName = "[CSW] 48Rnd 40x53mm M430A1 HEDP (Mk19)";
        displayNameShort = "[CSW] 48Rnd M430A1 HEDP (Mk19)";
        scope = 2;
        scopeArsenal = 2;
        type = 256;
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        picture = "\z\ace\addons\csw\UI\ammoBox_50bmg_ca.paa";
        ACE_isBelt = 1;
        mass = 40;
    };
    class MAGAZINE(48Rnd_40mm_MK19_M384_HE_csw): MAGAZINE(48Rnd_40mm_MK19_M384_HE) {
        displayName = "[CSW] 48Rnd 40x53mm M384 HE (Mk19)";
        displayNameShort = "[CSW] 48Rnd M384 HE (Mk19)";
        scope = 2;
        scopeArsenal = 2;
        type = 256;
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        picture = "\z\ace\addons\csw\UI\ammoBox_50bmg_ca.paa";
        ACE_isBelt = 1;
        mass = 40;
    };
};
