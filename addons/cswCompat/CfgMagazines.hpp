class CfgMagazines {
    class CUP_16Rnd_PG9_AT_M;
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

    class CUP_16Rnd_OG9_HE_M;
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
    class 40Rnd_20mm_G_belt;
    class GVAR(20Rnd_30mm_G_belt): 40Rnd_20mm_G_belt {
        author = "Brandon";
        displayName = "[CUP] 30mm GMG Belt";
        model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
        scope = 2;
        type = 256;
        count = 30;
        mass = 40;
        picture = ACE_CSW_PATH(UI\ammoBox_50bmg_ca.paa);
        ACE_isBelt = 1;
    };


    // reloadable m119
    class ACE_1Rnd_82mm_Mo_HE;
    class GVAR(105mm_m119_he): ACE_1Rnd_82mm_Mo_HE {
        author = "Potato";
        displayName = "[CUP] 105mm HE";
        mass = 120;
    };
    class GVAR(105mm_m119_smoke): GVAR(105mm_m119_he) {
        displayName = "[CUP] 105mm Smoke";
    };
    class GVAR(105mm_m119_wp): GVAR(105mm_m119_he) {
        displayName = "[CUP] 105mm WP";
    };
    class GVAR(105mm_m119_laser): GVAR(105mm_m119_he) {
        displayName = "[CUP] 105mm Laser";
    };
    class GVAR(105mm_m119_illum): GVAR(105mm_m119_he) {
        displayName = "[CUP] 105mm Illum";
    };
};

