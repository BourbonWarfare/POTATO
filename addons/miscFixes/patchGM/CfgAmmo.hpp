class CfgAmmo {
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
    class gm_HandGrenade_frag_dm51: gm_HandGrenade_frag_base {
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
    class gm_HandGrenade_frag_m56: gm_HandGrenade_frag_base {
        ACEGVAR(frag,charge) = 0.19;
        ACEGVAR(frag,metal) = 0.39;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
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
    class gm_shell_artillery_HE_Base;
    class gm_shell_120mm_he_of843: gm_shell_artillery_HE_Base {
        ACEGVAR(frag,charge) = 1.4;
        ACEGVAR(frag,metal) = 15;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small), QACEGVAR(frag,medium_HD)};
        ACEGVAR(frag,fragCount) = 3000;
    };
    class gm_shell_120mm_he_dm51: gm_shell_artillery_HE_Base {
        ACEGVAR(frag,charge) = 2;
        ACEGVAR(frag,metal) = 11;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small), QACEGVAR(frag,medium_HD)};
        ACEGVAR(frag,fragCount) = 2800;
    };

    // Make the missiles aimable by returning old smoke effects
    class gm_missile_saclos_base;
    class gm_missile_fagot_base: gm_missile_saclos_base {
        effectsMissile = "missile2_vanilla";
    };
    class gm_missile_milan_base: gm_missile_saclos_base {
        effectsMissile = "missile2_vanilla";
    };
    class gm_missile_bastion_base: gm_missile_saclos_base {
        effectsMissile = "missile2_vanilla";
    };
    class gm_missile_maljutka_base: gm_missile_saclos_base {
        effectsMissile = "missile2_vanilla";
    };

    class gm_Submunition_base;
    class gm_shell_artillery_Base: gm_Submunition_base {
        effectFly = "ArtilleryTrails_vanilla";
    };

    class ShellBase;
    class gm_warhead_base: ShellBase {
        effectFly = "ArtilleryTrails_vanilla";
    };

};
