class CfgAmmo {
    class BulletBase;

    CREATE_TINY_AMMO(22_lr);
    CREATE_TINY_AMMO(762x25);
    CREATE_TINY_AMMO(9x18);
    CREATE_TINY_AMMO(9x19);
    CREATE_TINY_AMMO(9x21);
    CREATE_TINY_AMMO(32_acp);
    CREATE_TINY_AMMO(45_acp);
    CREATE_TINY_AMMO(10x25);

    CREATE_SMALL_AMMO(50ae);
    CREATE_SMALL_AMMO(46x30);
    CREATE_SMALL_AMMO(545x39);
    CREATE_SMALL_AMMO(556x45);
    CREATE_SMALL_AMMO(57x28);
    CREATE_SMALL_AMMO(580x42);
    CREATE_SMALL_AMMO(65x39);
    CREATE_SMALL_AMMO(68_spc);
    CREATE_SMALL_AMMO(75x55);
    CREATE_SMALL_AMMO(9x39);
    CREATE_SMALL_AMMO(762x39);

    CREATE_MEDIUM_AMMO(762x51);
    CREATE_MEDIUM_AMMO(762x54);
    CREATE_MEDIUM_AMMO(792x57);
    CREATE_MEDIUM_AMMO(300_wm);
    CREATE_MEDIUM_AMMO(303_b);
    CREATE_MEDIUM_AMMO(338_lm);
    CREATE_MEDIUM_AMMO(338_nm);
    CREATE_MEDIUM_AMMO(408);
    CREATE_MEDIUM_AMMO(127x54);

    CREATE_LARGE_AMMO(93x64);
    CREATE_LARGE_AMMO(50_bmg);
    CREATE_LARGE_AMMO(127x108);
    CREATE_LARGE_AMMO(127x108_slap);

    // Updating 40x53mm HV grenades (Mk19)
    class G_40mm_HE;
    class AMMO(40x53mm_HE_M384): G_40mm_HE {
        airFriction = -0.00045;
        aiAmmoUsageFlags = "64 + 128";
        displayNameshort = "M384 HE";
        displayName = "M384 40x53mm HE";
        ACEGVAR(frag,charge) = 54.5;
        ACEGVAR(frag,metal) = 205;
        ACEGVAR(frag,gurney_c) = 2769; // comp A-5
        ACEGVAR(frag,fragCount) = 1050; // based on Rheinmetal comparison of new AB round
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD), QACEGVAR(frag,small_HD)};
        maxSpeed = 250;
        typicalSpeed = 240;
        timeToLive = 25;
    };

    class G_40mm_HEDP;
    class AMMO(40x53mm_HEDP_M430A1): G_40mm_HEDP { // based on  NDC M430A1 HEDP
        airFriction = -0.00045;
        aiAmmoUsageFlags = "64 + 128 + 512";
        cost = 12;
        displayNameshort = "M430A1 HEDP";
        displayName = "M430A1 40x53mm HEDP";
        ACEGVAR(frag,gurney_c) = 2769; // comp A-5
        ACEGVAR(frag,fragCount) = 750; // based on Rheinmetal comparison of new AB round
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        // Damage
        hit = 80; // reduce to match HEDP
        maxSpeed = 250;
        typicalSpeed = 241;
        timeToLive = 25;
        // Penetrator
        deleteParentWhenTriggered = 0;
        submunitionAmmo = QAMMO(40x53mm_HEDP_M430A1_penetrator);
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0, 0, -0.2};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        triggerOnImpact = 1;
    };
    class ammo_Penetrator_Base;
    class AMMO(40x53mm_HEDP_M430A1_penetrator): ammo_Penetrator_Base {
        hit = 80; // a guess
        caliber = 5.067; // 76mm steel
        submunitionAmmo = ""; // override RHS spalling
        submunitionConeType[] = {};
        timeToLive = 0.1;
    };
};