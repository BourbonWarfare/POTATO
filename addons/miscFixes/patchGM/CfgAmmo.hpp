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
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 1.4;
        ACEGVAR(frag,metal) = 15;
        ACEGVAR(frag,gurney_k) = 0.6;
        ACEGVAR(frag,gurney_c) = 2440;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small), QACEGVAR(frag,medium_HD)};
        ACEGVAR(frag,fragCount) = 3000;
    };
    class gm_shell_120mm_he_dm51: gm_shell_artillery_HE_Base {
        ACEGVAR(frag,skip) = 0;
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
    class gm_shell_artillery_submunition_Base: gm_Submunition_base {
        effectFly = "ArtilleryTrails_vanilla";
    };

    class ShellBase;
    class gm_warhead_base: ShellBase {
        effectFly = "ArtilleryTrails_vanilla";
    };
    class gm_shell_base: ShellBase {};
    class gm_shell_artillery_Base: gm_shell_base {
        effectFly = "";
    };
    class gm_shell_HE_Base: gm_shell_base {};
    class gm_shell_73mm_HE_og15v: gm_shell_HE_Base {
        model = "\a3\Weapons_F_Tank\Ammo\rocket_spg9.p3d";
        airfriction = 0.644966 / 2; // originally -0.000644966;
        effectsMissile = "Missile3_vanilla";
        deleteParentWhenTriggered = 0;
        maxSpeed = 500;
        fuseDistance = 12;
        initTime = 0.15;
        visibleFireTime = 20;
        sideAirFriction = 0.01;
        simulation = "shotRocket";
        timeToLive = 8;
        thrustTime = 0.35;
        thrust = 0.0001;
        deflecting = 5;
        soundFly[] = {"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\rocket_fly",1.1,0.7,250};
    };
    class gm_shell_HEAT_Base: gm_shell_HE_Base {};
    class gm_shell_73mm_HEAT_pg15v: gm_shell_HEAT_Base {
        airfriction = 0.515649 / 2; // originally -0.000515649;
        model = "\a3\Weapons_F_Tank\Ammo\rocket_spg9.p3d";
        effectsMissile = "Missile3_vanilla";
        deleteParentWhenTriggered = 0;
        maxSpeed = 500;
        fuseDistance = 12;
        initTime = 0.15;
        visibleFireTime = 20;
        sideAirFriction = 0.01;
        simulation = "shotRocket";
        timeToLive = 8;
        thrustTime = 0.35;
        thrust = 0.0001;
        deflecting = 5;
        soundFly[] = {"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\rocket_fly",1.1,0.7,250};
    };

    // what if there were colors
    class gm_bullet_762x51mm_B_T_DM21;
    class gm_bullet_762x51mm_B_T_DM21_white: gm_bullet_762x51mm_B_T_DM21 {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    };
    class gm_bullet_762x51mm_B_T_DM21_green: gm_bullet_762x51mm_B_T_DM21 {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class gm_bullet_762x51mm_B_T_DM21_yellow: gm_bullet_762x51mm_B_T_DM21 {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
};
