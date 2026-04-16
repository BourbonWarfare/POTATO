class CfgMagazines {
    //// LV 40x46mm grenade magazines (M203, EGLM)
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

    //// HV 40x53mm grenade launcher
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
    //// HV 40x53mm grenade CSW
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
    //// GP-25 magazines
    // HE rounds
    class MAGAZINE(1Rnd_HE_VOG25_shell): 1Rnd_HE_Grenade_shell {
        descriptionShort = "Type: High Explosive Grenade Round<br />Caliber: 40 mm<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "VOG-25 40mm HE Grenade";
        displayNameShort = "HE Grenade";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    // Smoke Rounds
    class 1Rnd_Smoke_Grenade_shell;
    class MAGAZINE(1Rnd_Smoke_GRD40_shell): 1Rnd_Smoke_Grenade_shell {
        descriptionShort = "Type: Smoke Round - White<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (White)";
        displayNameShort = "White Smoke (White)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokeBlue_Grenade_shell;
    class MAGAZINE(1Rnd_SmokeBlue_GRD40_shell): 1Rnd_SmokeBlue_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Blue<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Blue)";
        displayNameShort = "Smoke Round (Blue)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokeGreen_Grenade_shell;
    class MAGAZINE(1Rnd_SmokeGreen_GRD40_shell): 1Rnd_SmokeGreen_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Green<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Green)";
        displayNameShort = "Smoke Round (Green)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokeOrange_Grenade_shell;
    class MAGAZINE(1Rnd_SmokeOrange_GRD40_shell): 1Rnd_SmokeOrange_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Orange<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Orange)";
        displayNameShort = "Smoke Round (Orange)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokePurple_Grenade_shell;
    class MAGAZINE(1Rnd_SmokePurple_GRD40_shell): 1Rnd_SmokePurple_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Purple<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Purple)";
        displayNameShort = "Smoke Round (Purple)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokeRed_Grenade_shell;
    class MAGAZINE(1Rnd_SmokeRed_GRD40_shell): 1Rnd_SmokeRed_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Red<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Red)";
        displayNameShort = "Smoke Round (Red)";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class 1Rnd_SmokeYellow_Grenade_shell;
    class MAGAZINE(1Rnd_SmokeYellow_GRD40_shell): 1Rnd_SmokeYellow_Grenade_shell {
        descriptionShort = "Type: Smoke Round - Yellow<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "GRD-40 Smoke Round (Yellow)";
        displayNameShort = "Smoke Round (Yellow )";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    // Flare rounds
    class UGL_FlareWhite_Illumination_F;
    class MAGAZINE(1Rnd_Flare_Illum_VG40OP_shell): UGL_FlareWhite_Illumination_F {
        count = 1;
        descriptionShort = "Type: Illumination Rounds - White<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "VG-40OP Illumination (White)";
        displayNameShort = "White Illumination";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class UGL_FlareRed_Illumination_F;
    class MAGAZINE(1Rnd_FlareRed_Illum_VG40OP_shell): UGL_FlareRed_Illumination_F {
        count = 1;
        descriptionShort = "Type: Illumination Rounds - Red<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "VG-40OP Illumination (Red)";
        displayNameShort = "Red Illumination";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class UGL_FlareGreen_Illumination_F;
    class MAGAZINE(1Rnd_FlareGreen_Illum_VG40OP_shell): UGL_FlareGreen_Illumination_F {
        count = 1;
        descriptionShort = "Type: Illumination Rounds - Green<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "VG-40OP Illumination (Green)";
        displayNameShort = "Green Illumination";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };
    class UGL_FlareYellow_Illumination_F;
    class MAGAZINE(1Rnd_FlareYellow_Illum_VG40OP_shell): UGL_FlareYellow_Illumination_F {
        count = 1;
        descriptionShort = "Type: Illumination Rounds - Yellow<br />Rounds: 1<br />Used in: GP-25, GP-30, GP-34";
        displayName = "VG-40OP Illumination (Yellow)";
        displayNameShort = "Yellow Illumination";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
    };

};
