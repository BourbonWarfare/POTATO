class CfgMagazines {
    class CA_Magazine;
    class CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M: CA_Magazine {
        modelSpecial = "\gm\gm_weapons\gm_machineguns\gm_pk\gm_100rnd_762x54mm_pk_modelspecial";
        modelSpecialIsProxy = 1;
    };
    class rhs_30Rnd_545x39_AK: CA_Magazine {};
    class rhs_30Rnd_545x39_7N6_AK: rhs_30Rnd_545x39_AK {};
    class rhs_100Rnd_762x54mmR: rhs_30Rnd_545x39_7N6_AK {
        modelSpecial = "\gm\gm_weapons\gm_machineguns\gm_pk\gm_100rnd_762x54mm_pk_modelspecial";
        modelSpecialIsProxy = 1;
    };
    class vn_magazine: CA_Magazine {};
    class vn_lmgmag_base: vn_magazine {};
    class vn_pk_100_mag: vn_lmgmag_base {
        modelSpecial = "\gm\gm_weapons\gm_machineguns\gm_pk\gm_100rnd_762x54mm_pk_modelspecial";
        modelSpecialIsProxy = 1;
    };
    class 150Rnd_762x51_Box;
    class 150Rnd_762x54_box: 150Rnd_762x51_Box {
        modelSpecial = "\gm\gm_weapons\gm_machineguns\gm_pk\gm_100rnd_762x54mm_pk_modelspecial";
        modelSpecialIsProxy = 1;
    };
    class gm_120Rnd_762x51mm_B_T_DM21_mg3_grn;
    class gm_120Rnd_762x51mm_B_T_DM21_mg3_grn_wht: gm_120Rnd_762x51mm_B_T_DM21_mg3_grn {
        ammo = "gm_bullet_762x51mm_B_T_DM21_white";
        displayName = "7.62mm 120Rnd MG3 Ball-T DM21 Green Mag (White)";
    };
    class gm_120Rnd_762x51mm_B_T_DM21_mg3_grn_grn: gm_120Rnd_762x51mm_B_T_DM21_mg3_grn {
        ammo = "gm_bullet_762x51mm_B_T_DM21_green";
        displayName = "7.62mm 120Rnd MG3 Ball-T DM21 Green Mag (Green)";
    };
    class gm_120Rnd_762x51mm_B_T_DM21_mg3_grn_ylw: gm_120Rnd_762x51mm_B_T_DM21_mg3_grn {
        ammo = "gm_bullet_762x51mm_B_T_DM21_yellow";
        displayName = "7.62mm 120Rnd MG3 Ball-T DM21 Green Mag (Yellow)";
    };
};
