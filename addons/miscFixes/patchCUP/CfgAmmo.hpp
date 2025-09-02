class CfgAmmo {
    class MissileBase;
    class cup_m_9k11_at3_sagger_at: MissileBase {
        effectsMissile = "Missile4_vanilla";
    };
    class CUP_M_9K121_Vikhr_AT16_Scallion_AT: MissileBase {
        effectsMissile = "Missile2_vanilla";
    };
    
    // CUP MLRS Fix
    class R_230mm_HE;
	class CUP_R_GRAD_HE : R_230mm_HE {
		submunitionAmmo = "";
		simulation = "shotShell";
		indirectHitRange = 5;
	};
	class CUP_R_Techical_HE : CUP_R_GRAD_HE {
		indirectHitRange = 5;
	};
	class CUP_R_S8_techical_HE : CUP_R_GRAD_HE{
		hit = 150;
		indirectHit = 40;
		indirectHitRange = 12;
		suppressionRadiusHit = 30;
		
		model = "\CUP\Weapons\CUP_Weapons_Ammunition\Generic_70mm_Rocket\CUP_70mmRocket.p3d";
		proxyShape = "\CUP\Weapons\CUP_Weapons_Ammunition\Generic_70mm_Rocket\CUP_70mmRocket.p3d";
		CraterEffects = "HERocketCrater";
		effectsMissile = "missile1";
		explosioneffects = "HERocketExplosion";
		explosionSoundEffect = "DefaultExplosion";
	};
};
