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
        displayName = "[CUP] 30mm GMG Belt";
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
        displayName = "[CUP] 40mm GMG Belt";
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
        displayName = "[CUP] SPG-9 AT Round";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(cup_spg9_dummy_at): CUP_16Rnd_PG9_AT_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 80;
	};
	
	class GVAR(cup_spg9_he): CUP_16Rnd_OG9_HE_M {
		author = "Brandon";
        displayName = "[CUP] SPG-9 HE Round";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_tbg32v_rocket_ca.paa";
	};
	
	class GVAR(cup_spg9_dummy_he): CUP_16Rnd_OG9_HE_M {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 80;
	};
	
	class CUP_6Rnd_TOW2_M;
	class GVAR(cup_tow_at): CUP_6Rnd_TOW2_M {
		author = "Brandon";
        displayName = "[CUP] BGM-71 TOW Round";
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
	
	class rhs_mag_9m133;
	class rhs_mag_9m133f;
	class rhs_mag_9m1331;
	class rhs_mag_9m133m2;
	
	class GVAR(rhs_9m133): rhs_mag_9m133 {
		author = "Brandon";
        displayName = "[RHS] 9M133 (Kornet HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m133_dummy): rhs_mag_9m133 {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 300;
	};
	
	class GVAR(rhs_9m133f): rhs_mag_9m133f {
		author = "Brandon";
        displayName = "[RHS] 9M133F (Kornet Thermobaric)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m133f_dummy): rhs_mag_9m133f {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 300;
	};
	
	class GVAR(rhs_9m1331): rhs_mag_9m1331 {
		author = "Brandon";
        displayName = "[RHS] 9M133-1 (Kornet HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m1331_dummy): rhs_mag_9m1331 {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 300;
	};
	
	class GVAR(rhs_9m133m2): rhs_mag_9m133m2 {
		author = "Brandon";
        displayName = "[RHS] 9M133M-1 (Kornet HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m133m2_dummy): rhs_mag_9m133m2 {
		author = "Brandon";
        displayName = "Dummy magazine";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 1;
        type = 0;
        count = 1;
        mass = 300;
	};
	
	class rhs_mag_9M131M;
	class rhs_mag_9M131F;
	
	class GVAR(rhs_9m131m_dummy): rhs_mag_9m131M {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m131m): rhs_mag_9m131M {
		author = "Brandon";
        displayName = "[RHS] 9M131M (Metis HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m131f_dummy): rhs_mag_9m131F {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_9m131f): rhs_mag_9m131F {
		author = "Brandon";
        displayName = "[RHS] 9M131M (Metis Thermobaric)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 300;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class rhs_mag_PG9V;
	class rhs_mag_PG9N;
	class rhs_mag_PG9VNT;
	class rhs_mag_OG9VM;
	class rhs_mag_OG9V;
	
	class GVAR(rhs_PG9V_dummy): rhs_mag_PG9V {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_PG9V): rhs_mag_PG9V {
		author = "Brandon";
        displayName = "[RHS] PG-9V (SPG-9 HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_PG9N_dummy): rhs_mag_PG9N {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_PG9N): rhs_mag_PG9N {
		author = "Brandon";
        displayName = "[RHS] PG-9N (SPG-9 HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_PG9VNT_dummy): rhs_mag_PG9VNT {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_PG9VNT): rhs_mag_PG9VNT {
		author = "Brandon";
        displayName = "[RHS] PG-9VNT (SPG-9 Tandem HEAT)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_OG9VM_dummy): rhs_mag_OG9VM {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_OG9VM): rhs_mag_OG9VM {
		author = "Brandon";
        displayName = "[RHS] OG-9VM (SPG-9 Fragmentation)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_OG9V_dummy): rhs_mag_OG9V {
		author = "Brandon";
        displayName = "Dummy";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
	
	class GVAR(rhs_OG9V): rhs_mag_OG9V {
		author = "Brandon";
        displayName = "[RHS] OG-9V (SPG-9 Fragmentation)";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 1;
        mass = 80;
		picture = "\A3\weapons_f\launchers\rpg32\data\ui\gear_rpg32_rocket_ca.paa";
	};
};

