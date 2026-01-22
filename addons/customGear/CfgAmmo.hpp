class CfgAmmo {
    // Base classes
    class ammo_Penetrator_Base;


    // Updatin 40x46mm LV (M203) & 40x53mm HV grenades (Mk19)
    class G_40mm_HE;
    class AMMO(40x53mm_HE_M384): G_40mm_HE {
        airFriction = -0.00045;
        aiAmmoUsageFlags = 64 + 128;
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

    class G_40mm_HEDP: G_40mm_HE {
        class EventHandlers;
    };
    class AMMO(40x46mm_HEDP_M433): G_40mm_HEDP { // Amtec corp datasheet
        aiAmmoUsageFlags = 64 + 128 + 512;
        cost = 12;
        fuseDistance = 15;
        displayNameshort = "M433 HEDP";
        displayName = "M433 40x46mm HEDP";
        ACEGVAR(frag,charge) = 0.045;
        ACEGVAR(frag,metal) = 0.2;
        ACEGVAR(frag,gurney_k) = 1/2;
        ACEGVAR(frag,gurney_c) = 2769; // comp A-5
        ACEGVAR(frag,fragCount) = 270;
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        // Damage - reduced for smaller one
        hit = 65;
        indirectHitRange = 3;
        maxSpeed = 250;
        typicalSpeed = 241;
        timeToLive = 25;
        // Penetrator
        deleteParentWhenTriggered = 0;
        submunitionAmmo = QAMMO(40x46mm_HEDP_M433_penetrator);
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0, 0, -0.2};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        triggerOnImpact = 1;
        class EventHandlers: EventHandlers {
            class ADDON {
                init = QUOTE(call FUNC(fixSubmunitDir));
            };
        };
    };
    class AMMO(40x53mm_HEDP_M430A1): G_40mm_HEDP { // based on  NDC M430A1 HEDP
        airFriction = -0.00045;
        aiAmmoUsageFlags = 64 + 128 + 512;
        cost = 12;
        displayNameshort = "M430A1 HEDP";
        displayName = "M430A1 40x53mm HEDP";
        ACEGVAR(frag,gurney_c) = 2769; // comp A-5
        ACEGVAR(frag,fragCount) = 750; // based on Rheinmetal comparison of new AB round
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,tiny_HD), QACEGVAR(frag,tiny_HD), QACEGVAR(frag,small_HD)};
        // Damage
        hit = 80; // reduce to match HEDP
        maxSpeed = 250;
        typicalSpeed = 242;
        timeToLive = 25;
        // Penetrator
        deleteParentWhenTriggered = 0;
        submunitionAmmo = QAMMO(40x53mm_HEDP_M430A1_penetrator);
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0, 0, -0.2};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        triggerOnImpact = 1;
        class EventHandlers: EventHandlers {
            class ADDON {
                init = QUOTE(call FUNC(fixSubmunitDir));
            };
        };
    };

    class AMMO(40x46mm_HEDP_M433_penetrator): ammo_Penetrator_Base {
        hit = 90; // a guess
        caliber = 4.467; // 67mm steel (should be 4.2 for 63mm, but it was under performing)
        timeToLive = 0.1;
        // fix double explosion
        soundsetexplosion[] = {};
    };
    class AMMO(40x53mm_HEDP_M430A1_penetrator): ammo_Penetrator_Base {
        hit = 90;
        caliber = 5.067; // 76mm steel
        timeToLive = 0.1;
        soundsetexplosion[] = {};
    };

    // M576 Buckshot
    // derived from ACE_12Gauge_Pellets_Submunition_No4_Buck_Deploy
    class B_12Gauge_Pellets_Submunition_Deploy;
    class AMMO(40x46mm_MP_M576_shot): B_12Gauge_Pellets_Submunition_Deploy {
        airFriction = -0.0085;
        caliber = 0.4;
        hit = 2;
        typicalSpeed = 269;
    };
    class B_12Gauge_Pellets_Submunition;
    class AMMO(40x46mm_MP_M576): B_12Gauge_Pellets_Submunition {
        submunitionAmmo = QAMMO(40x46mm_MP_M576_shot);
        submunitionConeAngle = 1.4;
        submunitionConeType[] = {"poissondisccenter",20};
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 0;
        triggerSpeedCoef[] = {0.99, 1.02};
    };
};
