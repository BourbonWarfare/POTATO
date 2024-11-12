class CfgAmmo {
    /// Bomblets
    class gm_bomblet_base;
    class gm_bomblet_HE_base: gm_bomblet_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
    };
    class gm_bomblet_HEAT_base: gm_bomblet_HE_base {};
    class gm_bomblet_heat_m77: gm_bomblet_HEAT_base {
        ACEGVAR(frag,charge) = 0.044;
        ACEGVAR(frag,metal) = 0.248;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,fragCount) = 800;

    };
    class gm_bomblet_heat_dm1348: gm_bomblet_HEAT_base {
        ACEGVAR(frag,charge) = 0.032;
        ACEGVAR(frag,metal) = 0.178;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,fragCount) = 600;
    };
    class gm_bomblet_heat_3b30: gm_bomblet_HEAT_base {
        ACEGVAR(frag,charge) = 0.046;
        ACEGVAR(frag,metal) = 0.194;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,fragCount) = 600;
    };

    class UXO1_Ammo_Base_F;
    class gm_uxo_base: UXO1_Ammo_Base_F {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = "1/3";
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
    };
    class gm_uxo_m77: gm_uxo_base {
        ACEGVAR(frag,charge) = 0.044;
        ACEGVAR(frag,metal) = 0.248;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,fragCount) = 800;

    };
    class gm_uxo_dm1348: gm_uxo_base {
        ACEGVAR(frag,charge) = 0.032;
        ACEGVAR(frag,metal) = 0.178;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,fragCount) = 600;
    };
    class gm_uxo_3b30: gm_uxo_base {
        ACEGVAR(frag,charge) = 0.046;
        ACEGVAR(frag,metal) = 0.194;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,fragCount) = 600;
    };


    /// Bullets
    class gm_bullet_base;
    class gm_bullet_large_base: gm_bullet_base {};
    class gm_bullet_145x114mm_base: gm_bullet_large_base {
        ACEGVAR(frag,skip) = 1;
    };

    class gm_bullet_20x139mm_base: gm_bullet_large_base {
        ACEGVAR(frag,skip) = 0;
    };
    class gm_bullet_20x139mm_HE_T_DM51: gm_bullet_20x139mm_base {
        ACEGVAR(frag,charge) = 0.0065;
        ACEGVAR(frag,metal) = 0.1155;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 150;
    };
    class gm_bullet_20x139mm_HEI_T_DM81: gm_bullet_20x139mm_base {
        ACEGVAR(frag,charge) = 0.0065;
        ACEGVAR(frag,metal) = 0.1155;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 120;
    };
    class gm_bullet_20x139mm_HEI_T_DM111: gm_bullet_20x139mm_base {
        ACEGVAR(frag,skip) = 1;
    };

    class gm_bullet_23x115mm_base: gm_bullet_large_base {
        ACEGVAR(frag,skip) = 0;
    };
    class gm_bullet_23x115mm_HEI_OFZ: gm_bullet_23x115mm_base {
        ACEGVAR(frag,charge) = 0.0163;
        ACEGVAR(frag,metal) = 0.1577;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 150;
    };
    class gm_bullet_23x115mm_HEI_T_OFZT: gm_bullet_23x115mm_HEI_OFZ {
        ACEGVAR(frag,charge) = 0.0155;
        ACEGVAR(frag,metal) = 0.1745;
        ACEGVAR(frag,fragCount) = 120;
    };

    class gm_bullet_23x152mm_base: gm_bullet_large_base {};
    class gm_bullet_23x152mm_HEI_OFZ: gm_bullet_23x152mm_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.0173;
        ACEGVAR(frag,metal) = 0.186;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_bullet_23x152mm_HEI_T_OFZT: gm_bullet_23x152mm_HEI_OFZ {
        ACEGVAR(frag,charge) = 0.0132;
        ACEGVAR(frag,metal) = 0.1885;
        ACEGVAR(frag,fragCount) = 350;
    };

    class gm_bullet_25x137mm_base: gm_bullet_large_base {};
    class gm_bullet_25x137mm_HEI_T_M792: gm_bullet_25x137mm_base {
        ACEGVAR(frag,charge) = 0.0302;
        ACEGVAR(frag,metal) = 0.1554;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 200;
    };

    class gm_bullet_35x228mm_base: gm_bullet_large_base {};
    class gm_bullet_35x228mm_HEI_T_dm21: gm_bullet_35x228mm_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.098;
        ACEGVAR(frag,metal) = 0.437;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 300;
    };
    class gm_bullet_35x228mm_FAPDS_T_dm33: gm_bullet_35x228mm_base {
        ACEGVAR(frag,skip) = 1;
    };

    /// Hand Grenades
    class gm_HandGrenade_base;
    class gm_HandGrenade_prac_base: gm_HandGrenade_base {
        ACEGVAR(frag,skip) = 1;
    };
    class gm_HandGrenade_conc_base: gm_HandGrenade_base {
        ACEGVAR(frag,skip) = 1;
        ACEGVAR(frag,charge) = 0.06;
        ACEGVAR(frag,metal) = 0.085;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2930;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 300;
    };
    class gm_HandGrenade_frag_base: gm_HandGrenade_base {
        ACEGVAR(frag,skip) = 0;
    };
    class gm_HandGrenade_frag_dm51: gm_HandGrenade_base {
        ACEGVAR(frag,charge) = 0.06;
        ACEGVAR(frag,metal) = 0.276;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2930;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 6500;
    };
    class gm_HandGrenade_frag_dm41: gm_HandGrenade_frag_base {
        ACEGVAR(frag,charge) = 0.165;
        ACEGVAR(frag,metal) = 0.21812;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 1200;
    };
    class gm_HandGrenade_frag_m26: gm_HandGrenade_frag_base {
        ACEGVAR(frag,charge) = 0.165;
        ACEGVAR(frag,metal) = 0.21812;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 1200;
    };
    class gm_HandGrenade_frag_rgd5: gm_HandGrenade_frag_base {
        ACEGVAR(frag,charge) = 0.11;
        ACEGVAR(frag,metal) = 0.2;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 350;
    };

    /// Mines
    class gm_mine_base;
    class gm_mine_at_base: gm_mine_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = "1/3";
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 200;
    };
    class gm_mine_at_dm21: gm_mine_at_base { // PARM-1
        ACEGVAR(frag,skip) = 1;
    };
    class gm_mine_at_dm1233: gm_mine_at_base {
        ACEGVAR(frag,charge) = 0.907;
        ACEGVAR(frag,metal) = 1;
        ACEGVAR(frag,gurney_c) = 2700;
    };
    class gm_mine_at_tm46: gm_mine_at_base {
        ACEGVAR(frag,charge) = 2.9;
        ACEGVAR(frag,metal) = 2.8;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,fragCount) = 1800;
    };
    class gm_mine_at_ptm3: gm_mine_at_base {
        ACEGVAR(frag,charge) = 1.8;
        ACEGVAR(frag,metal) = 2;
        ACEGVAR(frag,gurney_c) = 2670;
    };
    class gm_mine_at_mn111: gm_mine_at_base {
        ACEGVAR(frag,charge) = 0.8;
        ACEGVAR(frag,metal) = 1;
        ACEGVAR(frag,gurney_c) = 2800;
        ACEGVAR(frag,fragCount) = 600;
    };

    class gm_mine_ap_base: gm_mine_base {};
    class gm_mine_ap_pfm1: gm_mine_ap_base { // Butterfly mines
        ACEGVAR(frag,skip) = 1;
    };

    class BoundingMineBase;
    class gm_mine_bounce_base: BoundingMineBase {};
    class gm_mine_ap_dm31: gm_mine_bounce_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.53;
        ACEGVAR(frag,metal) = 1.28;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,small_HD), QACEGVAR(frag,medium_HD), QACEGVAR(frag,medium_HD)};
        ACEGVAR(frag,fragCount) = 360;
    };

    /// Missiles
    class gm_missile_base;
    class gm_missile_saclos_base: gm_missile_base {
        ACEGVAR(frag,skip) = 1;
    };
    class gm_rocket_70mm_HE_m585_base: gm_missile_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.36;
        ACEGVAR(frag,metal) = 0.7;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2970;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 1000;
    };
    class gm_rocket_72mm_HE_9m32m_base: gm_missile_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.37;
        ACEGVAR(frag,metal) = 0.78;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2970;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 1100;
    };

    /// Rocket
    class gm_rocket_base;
    class gm_rocket_HE_Base: gm_rocket_base {
        ACEGVAR(frag,skip) = 0;
    };
    class gm_rocket_55mm_HE_base: gm_rocket_HE_Base {};
    class gm_rocket_55mm_HE_s5: gm_rocket_55mm_HE_base {
        ACEGVAR(frag,charge) = 0.285;
        ACEGVAR(frag,metal) = 0.53;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 750;
    };
    class gm_rocket_HEAT_Base: gm_rocket_HE_Base {
        ACEGVAR(frag,skip) = 1;
    };
    class gm_rocket_55mm_HEAT_base: gm_rocket_HEAT_Base {};
    class gm_rocket_55mm_heat_s5k: gm_rocket_55mm_HEAT_base {
        ACEGVAR(frag,charge) = 0.4;
        ACEGVAR(frag,metal) = 0.6;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_rocket_66mm_HEAT_m72_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.45;
        ACEGVAR(frag,metal) = 0.55;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 200;
    };
    class gm_rocket_60mm_HEAT_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 1.5;
        ACEGVAR(frag,metal) = 2.4;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_rocket_44x537mm_HEAT_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.305;
        ACEGVAR(frag,metal) = 1.195;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 300;
    };
    class gm_rocket_64mm_HEAT_pg18_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.6;
        ACEGVAR(frag,metal) = 0.4;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2822;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 200;
    };
    class gm_rocket_40mm_HEAT_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.6;
        ACEGVAR(frag,gurney_c) = 2896;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
    };
    class gm_rocket_40mm_HEAT_pg7v: gm_rocket_40mm_HEAT_base {
        ACEGVAR(frag,metal) = 0.39;
        ACEGVAR(frag,charge) = 0.6;
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_rocket_40mm_HEAT_pg7vl: gm_rocket_40mm_HEAT_base {
        ACEGVAR(frag,metal) = 1.03;
        ACEGVAR(frag,charge) = 1.57;
        ACEGVAR(frag,fragCount) = 700;
    };
    class gm_rocket_84x245mm_HEAT_base: gm_rocket_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2970;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
    };
    class gm_rocket_84x245mm_HEAT_T_DM22: gm_rocket_84x245mm_HEAT_base {
        ACEGVAR(frag,charge) = 0.635;
        ACEGVAR(frag,metal) = 2.265;
        ACEGVAR(frag,fragCount) = 500;
    };
    class gm_rocket_84x245mm_HEAT_T_DM32: gm_rocket_84x245mm_HEAT_base {
        ACEGVAR(frag,charge) = 0.55;
        ACEGVAR(frag,metal) = 1.8;
        ACEGVAR(frag,fragCount) = 300;

    };

    /// Shell
    class gm_shell_base;
    class gm_rocket_luna_he_3r9_warhead: gm_shell_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 78;
        ACEGVAR(frag,metal) = 280;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,medium), QACEGVAR(frag,large)};
        ACEGVAR(frag,fragCount) = 160000;
    };
    class gm_rocket_luna_nuc_3r10_warhead: gm_rocket_luna_he_3r9_warhead {
        ACEGVAR(frag,skip) = 1;
    };

    class gm_warhead_base: gm_shell_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,medium)};
    };
    class gm_warhead_mlrs_110mm_he_dm21: gm_warhead_base {
        ACEGVAR(frag,charge) = 1.5;
        ACEGVAR(frag,metal) = 6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,fragCount) = 6000;
    };
    class gm_warhead_122mm_he_9m22u: gm_warhead_base {
        ACEGVAR(frag,charge) = 6.58;
        ACEGVAR(frag,metal) = 11.82;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,fragCount) = 5580;
    };
    class gm_warhead_122x447mm_he_of462: gm_warhead_base {
        ACEGVAR(frag,charge) = 3.675;
        ACEGVAR(frag,metal) = 18.085;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,fragCount) = 5500;
    };
    class gm_warhead_122x447mm_he_3of56: gm_warhead_base {
        ACEGVAR(frag,charge) = 4.05;
        ACEGVAR(frag,metal) = 17.71;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,fragCount) = 7500;
    };
    class gm_warhead_155mm_he_m107: gm_warhead_base {
        ACEGVAR(frag,charge) = 6.86;
        ACEGVAR(frag,metal) = 36.34;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,fragCount) = 8000;
    };
    class gm_warhead_155mm_he_m795: gm_warhead_base {
        ACEGVAR(frag,charge) = 10.796;
        ACEGVAR(frag,metal) = 35.924;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,fragCount) = 8000;
    };
    class gm_warhead_155mm_he_dm111: gm_warhead_155mm_he_m795 {
        ACEGVAR(frag,charge) = 11.3;
        ACEGVAR(frag,metal) = 32.2;
        ACEGVAR(frag,gurney_c) = 2830;
        ACEGVAR(frag,fragCount) = 10000;
    };

    class gm_shell_HE_Base: gm_shell_base {
        ACEGVAR(frag,skip) = 0;
    };
    class gm_shell_73mm_HE_base: gm_shell_HE_Base {};
    class gm_shell_73mm_HE_og15v: gm_shell_73mm_HE_base {
        ACEGVAR(frag,charge) = 0.73;
        ACEGVAR(frag,metal) = 3.84;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,medium)};
        ACEGVAR(frag,fragCount) = 2400;
    };
    class gm_shell_76x385mm_HE_of350: gm_shell_HE_Base {
        ACEGVAR(frag,charge) = 0.64;
        ACEGVAR(frag,metal) = 6.21;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,medium_HD)};
        ACEGVAR(frag,fragCount) = 2000;
    };
    class gm_shell_100x695mm_HE_base: gm_shell_HE_Base {};
    class gm_shell_100x695mm_APHE_T_br412d: gm_shell_100x695mm_HE_base {
        ACEGVAR(frag,skip) = 1;
        ACEGVAR(frag,charge) = 0.061;
        ACEGVAR(frag,metal) = 15.88;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2570;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,tiny)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_shell_100x695mm_HE_of412: gm_shell_100x695mm_HE_base {
        ACEGVAR(frag,charge) = 1.46;
        ACEGVAR(frag,metal) = 15.6;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small), QACEGVAR(frag,small), QACEGVAR(frag,medium), QACEGVAR(frag,medium)};
        ACEGVAR(frag,fragCount) = 4000;
    };

    class gm_shell_HEAT_Base: gm_shell_HE_Base {
        ACEGVAR(frag,skip) = 1;
    };
    class gm_shell_76x385mm_HEAT_T_bk350m: gm_shell_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.518;
        ACEGVAR(frag,metal) = 3.432;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 22830;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_shell_73mm_HEAT_base: gm_shell_HEAT_Base {};
    class gm_shell_73mm_HEAT_pg15v: gm_shell_73mm_HEAT_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.322;
        ACEGVAR(frag,metal) = 2.278;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 300;
    };
    class gm_shell_105x617mm_HEAT_base: gm_shell_HEAT_Base {};
    class gm_shell_105x617mm_HEAT_MP_T_dm12: gm_shell_105x617mm_HEAT_base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 0.97;
        ACEGVAR(frag,metal) = 9.33;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2700;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 400;
    };
    class gm_shell_122x447mm_HEAT_base: gm_shell_HEAT_Base {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny), QACEGVAR(frag,small)};
        ACEGVAR(frag,fragCount) = 600;
    };
    class gm_shell_122x447mm_heat_bk6m: gm_shell_122x447mm_HEAT_base {
        ACEGVAR(frag,charge) = 2.159;
        ACEGVAR(frag,metal) = 19.401;
        ACEGVAR(frag,gurney_c) = 2822;
    };
    class gm_shell_122x447mm_heat_t_bk13: gm_shell_122x447mm_HEAT_base {
        ACEGVAR(frag,charge) = 1.698;
        ACEGVAR(frag,metal) = 16.502;
        ACEGVAR(frag,gurney_c) = 2570;
    };

};