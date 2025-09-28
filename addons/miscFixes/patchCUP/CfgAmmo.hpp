class CfgAmmo {
    class MissileBase;
    class cup_m_9k11_at3_sagger_at: MissileBase {
        effectsMissile = "Missile4_vanilla";
    };
    class CUP_M_9K121_Vikhr_AT16_Scallion_AT: MissileBase {
        effectsMissile = "Missile2_vanilla";
    };

    // CUP MLRS Fix
    // Credit to martin509 via the CUP discord for the fix
    // Fixed by Lambda.Tiger
    class R_230mm_fly;
    class GVARMAIN(R_GRAD_HE_fly): R_230mm_fly { // based on RHS and GM 122mm rounds
        indirectHit = 400;
        indirectHitRange = 25;
        hit = 600;
        effectFly = "";
    };
    class GVARMAIN(R_Techical_HE_fly): R_230mm_fly { // uses Hydra rounds
        hit = 150;
        indirectHit = 40;
        indirectHitRange = 8;
        effectFly = "";
    };
    class GVARMAIN(R_S5_techical_HE_fly): R_230mm_fly { // Based on GM S5
        indirectHit = 27;
        indirectHitRange = 10;
        hit = 30;
        suppressionRadiusHit = 30;
        model = "\A3\Weapons_F\Ammo\Rocket_02_fly_F";
        proxyShape = "\A3\Weapons_F\Ammo\Rocket_02_fly_F";
        CraterEffects = "HERocketCrater";
        explosioneffects = "HERocketExplosion";
        explosionSoundEffect = "DefaultExplosion";
        effectFly = "";
    };
    class R_230mm_HE;
    class CUP_R_GRAD_HE : R_230mm_HE {
        submunitionAmmo = QGVARMAIN(R_GRAD_HE_fly);
    };
    class CUP_R_Techical_HE : CUP_R_GRAD_HE {
        submunitionAmmo = QGVARMAIN(R_Techical_HE_fly);
    };
    class CUP_R_S8_techical_HE : CUP_R_GRAD_HE { // Actually an S5 missile / launcher
        submunitionAmmo = QGVARMAIN(R_S5_techical_HE_fly);
        model = "\A3\Weapons_F\Ammo\Rocket_02_fly_F";
        proxyShape = "\A3\Weapons_F\Ammo\Rocket_02_fly_F";
    };
};
