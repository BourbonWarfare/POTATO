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
};
