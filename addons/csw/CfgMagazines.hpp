class CfgMagazines {
    class 500Rnd_127x99_mag;
    class 100Rnd_127x99_mag: 500Rnd_127x99_mag {};
    class 100Rnd_127x99_mag_Tracer_Red: 100Rnd_127x99_mag {};
    class 100Rnd_127x99_mag_Tracer_Green: 100Rnd_127x99_mag {};
    class 100Rnd_127x99_mag_Tracer_Yellow: 100Rnd_127x99_mag {};
    class 1Rnd_GAT_missiles;
    class 40Rnd_20mm_G_belt;
    class 1Rnd_GAA_missiles;
    
    class GVAR(100Rnd_127x99_mag): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(127x99_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 100;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    // The maximum amount of ammo the HMG can hold. Its a dummy since all this purpose is for is to allow for 200 bullets
    class GVAR(HMG_Dummy_200Rnd_mag): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 200;
        mass = 40;
    };
    
    class GVAR(100Rnd_127x99_mag_red): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(127x99_red_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 100;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(HMG_Dummy_200Rnd_mag_red): 100Rnd_127x99_mag_Tracer_Red {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 200;
        mass = 40;
        tracersEvery = 1;
    };
    
    class GVAR(100Rnd_127x99_mag_green): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(127x99_green_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 100;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(HMG_Dummy_200Rnd_mag_green): 100Rnd_127x99_mag_Tracer_Green {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 200;
        mass = 40;
        tracersEvery = 1;
    };
    
    class GVAR(100Rnd_127x99_mag_yellow): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(127x99_yellow_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 100;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(HMG_Dummy_200Rnd_mag_yellow): 100Rnd_127x99_mag_Tracer_Yellow {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 200;
        mass = 40;
        tracersEvery = 1;
    };
    
    class GVAR(50Rnd_127x108_mag) : 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = CSTRING(127x108_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 50;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    
    class GVAR(20Rnd_20mm_G_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = CSTRING(GMGBelt_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 20;
        mass = 40;
        picture = QPATHTOF(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(GMG_Dummy_120Rnd_mag): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 120;
        mass = 40;
    };
    class GVAR(TitanAT_Dummy_Missile): 1Rnd_GAT_missiles {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 125;
    };
    class GVAR(TitanAA_Dummy_Missile): 1Rnd_GAA_missiles {
        author = "Brandon";
        displayName = CSTRING(DummyMagazine_displayName);
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 125;
    };
    
};

