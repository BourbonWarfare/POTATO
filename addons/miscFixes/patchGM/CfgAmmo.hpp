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
    class gm_HandGrenade_frag_rgd5: gm_HandGrenade_frag_base {
        ACEGVAR(frag,charge) = 0.11;
        ACEGVAR(frag,metal) = 0.2;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD)};
        ACEGVAR(frag,fragCount) = 350;
    };
};