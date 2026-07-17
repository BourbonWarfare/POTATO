class CfgAmmo {
    // CUP Inheritances
    class CUP_R_M136_AT;
    class CUP_R_M72A6_AT;
    class CUP_P_M136_AT;
    class CUP_P_M72A6_AT;

    //// M136
    // AT4CS-RS
    class AMMO(R_AT4CS_RS_HEAT): CUP_R_M136_AT {
        submunitionAmmo = QAMMO(P_AT4CS_RS_AT);
        typicalSpeed = 220;
    };
    // AT4CS LMAW
    class AMMO(R_AT4CS_LMAW_HEDP): CUP_R_M136_AT {
        explosionEffects = "ATMissileExplosion";
        airLock = 1;
        allowAgainstInfantry = 1;
        aiAmmoUsageFlags = 448;
        cost = 80;
        explosive = 0.9;
        indirectHitRange = 3;
        submunitionAmmo = QAMMO(P_AT4CS_LMAW_AT);
        typicalSpeed = 235;

    };
    // AT4CS HP
    class AMMO(R_AT4CS_HP_HEAT): CUP_R_M136_AT {
        airLock = 1;
        allowAgainstInfantry = 0;
        aiAmmoUsageFlags = 768;
        cost = 400;
        submunitionAmmo = QAMMO(P_AT4CS_HP_AT);
        typicalSpeed = 220;
    };

    //// M72 Law Variants
    // M72A7 HEDP Rocket
    class AMMO(R_M72A7_HEDP): CUP_R_M72A6_AT {
        EGVAR(frag,metal) = 1060;
        EGVAR(frag,charge) = 300;
        EGVAR(frag,gurney_c) = 2806;
        EGVAR(frag,gurney_k) = 3/5;
        EGVAR(frag,classes)[] = {"ACE_frag_tiny_HD","ACE_frag_small_HD","ACE_frag_small_HD","ACE_frag_medium_HD"};
        EGVAR(frag,skip) = 0;
        EGVAR(frag,force) = 0;
        allowAgainstInfantry = 1;
        aiAmmoUsageFlags = 192;
        cost = 100;
        hit = 200;
        explosive = 0.9;
        indirectHit = 4;
        indirectHitRange = 4;
        submunitionAmmo = QAMMO(P_M72A7_AT);
        typicalSpeed = 200;
        warheadName = "HEAT";
    };
    // M72A8 HEDP Rocket FFE
    class AMMO(R_M72A8_HEDP): AMMO(R_M72A7_HEDP) {
        typicalSpeed = 166;
    };
    // M72A9 LASM Rocket
    class AMMO(R_M72A9_HEDP): CUP_R_M72A6_AT {
        EGVAR(frag,metal) = 1150;
        EGVAR(frag,charge) = 1000;
        EGVAR(frag,gurney_c) = 2578;
        EGVAR(frag,gurney_k) = 3/5;
        EGVAR(frag,classes)[] = {"ACE_frag_tiny_HD","ACE_frag_small_HD","ACE_frag_small_HD","ACE_frag_medium_HD"};
        EGVAR(frag,skip) = 0;
        EGVAR(frag,force) = 0;
        airLock = 0; // maybe 1? determines if AI use against air vehicles
        allowAgainstInfantry = 1;
        aiAmmoUsageFlags = 192; // if airLock = 1, set to 448
        cost = 100;
        hit = 300;
        explosive = 1;
        indirectHit = 5;
        indirectHitRange = 8;
        submunitionAmmo = "";
        typicalSpeed = 130;
        warheadName = "HE";
        explosionEffects = "ATMissileExplosion";
    };
    // M72A10 FFE
    class AMMO(R_M72A10_HEDP): AMMO(R_M72A9_HEDP) {
        typicalSpeed = 108;
        explosionEffects = "ATRocketExplosion";
    };

    //// Submunitions
    class AMMO(P_M72A7_AT): CUP_P_M72A6_AT {
        caliber = 10;
        hit = 235;
    };
    class AMMO(P_AT4CS_RS_AT): CUP_P_M136_AT {
        caliber = 23.333;
    };
    class AMMO(P_AT4CS_LMAW_AT): CUP_P_M136_AT {
        caliber = 10;
        hit = 225;
    };
    class AMMO(P_AT4CS_HP_AT): CUP_P_M136_AT {
        caliber = 40;
        hit = 400;
    };

    // Custom Anti-Air Capable RPG rounds
    class CUP_R_PG7VL_AT;
    class CUP_R_PG7VM_AT;
    class CUP_R_PG7V_AT;
    class potato_R_PG7VL_AA: CUP_R_PG7VL_AT {
        airLock = 1;
    };
    class potato_R_PG7VM_AA: CUP_R_PG7VM_AT {
        airLock = 1;
    };
    class potato_R_PG7V_AA: CUP_R_PG7V_AT {
        airLock = 1;
    };

    // Carl Gustaf time
    class RocketBase;
    class R_MRAAWS_HEAT_F: RocketBase {
        class EventHandlers;
    };
    class R_MRAAWS_HE_F: R_MRAAWS_HEAT_F {
        class EventHandlers;
    };
    class GVARMAIN(R_FFV448_he): R_MRAAWS_HE_F {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,charge) = 400; // unpublished, 2.7 kg total
        ACEGVAR(frag,metal) = 400; // unpublished, shell casing approx
        ACEGVAR(frag,gurney_c) = 2800;
        ACEGVAR(frag,gurney_k) = 0.5;
        ACEGVAR(frag,fragCount) = 5000; // ACE FRAG, when implemented reduce explosion PFX
        ACEGVAR(frag,classes)[] = {QACEGVAR(frag,small),QACEGVAR(frag,small),QACEGVAR(frag,small),QACEGVAR(frag,medium),QACEGVAR(frag,tiny)};
        explosionEffects = "ATMissileExplosion";
        hit = 100;
        indirectHit = 40;
        indirectHitRange = 5;
        class EventHandlers: EventHandlers {
            class ADDON {
                fired = QUOTE(_this call FUNC(carlGAB_DetonateLaser));
            };
        };
    };
    class GVARMAIN(R_ASM509_tb): R_MRAAWS_HE_F {
        ACEGVAR(frag,skip) = 1; // thermobaric, no real details
        ACEGVAR(frag,gurney_c) = 2745; // idk, PAX-42 or something
        hit = 500;
        indirectHit = 40;
        indirectHitRange = 8;
        model = "\A3\Weapons_F_Tank\Launchers\MRAWS\rocket_MRAWS_HEAT55_F.p3d";
    };
    class GVARMAIN(R_FFV469C_smoke): R_MRAAWS_HEAT_F {
        ACEGVAR(frag,skip) = 1;
        caliber = 0.1;
        craterEffects = "ATRocketCrater";
        explosive = 0.5;
        explosionEffects = "";
        explosionSoundEffect = "";
        hit = 20;
        indirectHit = 0.5;
        indirectHitRange = 1;
        model = "\A3\Weapons_F_Tank\Launchers\MRAWS\rocket_MRAWS_HEAT55_F.p3d";
        class EventHandlers: EventHandlers {
            class ADDON {
                init = QUOTE(_this call FUNC(carlGSmoke));
            };
        };
    };
    // Smoke submunition
    class SmokeShellArty;
    class GVARMAIN(carlg_SmokeShell): SmokeShellArty {
        effectsSmoke = "potato_filledSmoke_bigSmoke";
        timeToLive = 30;
    };
};
