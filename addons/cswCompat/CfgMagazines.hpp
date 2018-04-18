class CfgMagazines {
	class 100Rnd_127x99_mag;
	class 40Rnd_20mm_G_belt;
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
};

