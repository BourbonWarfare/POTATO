class CfgAmmo {
    // Base Classes
    class ammo_Penetrator_Base;
    class RocketCore;
    class RocketBase: RocketCore{};

    // CUP Inheritances
    class CUP_R_M72A6_AT: RocketBase {};

    // M72A9 HEDP Rocket
    class AMMO(R_M72A9_HEDP): CUP_R_M72A6_AT {
        hit = 150;
        indirectHit = 30;
        indirectHitRange = 5;
        warheadName = "HE";
        submunitionAmmo = "CUP_P_M72A6_AT";
        cost = 100;
        explosionEffects = "ATMissileExplosion";
        airLock = 0; // maybe 1? determines if AI use against air vehicles
        allowAgainstInfantry = 1;
    };
};