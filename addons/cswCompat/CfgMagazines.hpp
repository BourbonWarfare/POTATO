class CfgMagazines {
	class 100Rnd_127x99_mag;
	class 40Rnd_20mm_G_belt;
	class CUP_AT13_M;
	class CUP_16Rnd_PG9_AT_M;
	class CUP_16Rnd_OG9_HE_M;
    class GVAR(HMG_Dummy_200Rnd_127x108_mag): 100Rnd_127x99_mag {
        author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 200;
        mass = 40;
    };
	
	class GVAR(20Rnd_30mm_G_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = "30mm GMG Belt";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 30;
        mass = 40;
        picture = QPATHTOEF(csw,UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(GMG_Dummy_120Rnd_30mm_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 120;
        mass = 40;
    };
	
	class GVAR(20Rnd_40mm_G_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = "40mm GMG Belt";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 20;
        mass = 40;
        picture = QPATHTOEF(csw,UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };
    class GVAR(GMG_Dummy_120Rnd_40mm_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 120;
        mass = 40;
    };
	
	class GVAR(cup_at13_dummy): CUP_AT13_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 110;
	};
	
	class GVAR(cup_spg9_at): CUP_16Rnd_PG9_AT_M {
		author = "Brandon";
        displayName = "SPG-9 AT Round";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 110;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(cup_spg9_dummy_at): CUP_16Rnd_PG9_AT_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 110;
	};
	
	class GVAR(cup_spg9_he): CUP_16Rnd_OG9_HE_M {
		author = "Brandon";
        displayName = "SPG-9 HE Round";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 110;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_tbg32v_rocket_ca.paa";
	};
	
	class GVAR(cup_spg9_dummy_he): CUP_16Rnd_OG9_HE_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 110;
	};
	
	class CUP_6Rnd_TOW2_M;
	class GVAR(cup_tow_at): CUP_6Rnd_TOW2_M {
		author = "Brandon";
        displayName = "BGM-71 TOW Round";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 440;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_tbg32v_rocket_ca.paa";
	};
	
	class GVAR(cup_tow_at_dummy): CUP_6Rnd_TOW2_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 440;
	};
};

