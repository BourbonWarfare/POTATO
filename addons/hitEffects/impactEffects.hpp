class ImpactEffectsSmall {
    class ImpactDust1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcrete {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(lingeringDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(impactDustDust) {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactEffectsSmall06 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustDirt);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactEffectsRed {
    class ImpactDust1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDust_Red);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcrete {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(lingeringDust_Red);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(impactDustDust) {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustDust_Red);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactEffectsSmall06 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustDirt_Red);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactEffectsHardGround {
    class ImpactDust1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcrete {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(lingeringDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactConcrete {
    class ImpactDust {
        qualityLevel = -1;
        type = QGVAR(impactDust);
    };
    class GVAR(lingeringDust) {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(lingeringDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactPlaster {
    class GVAR(lingeringDust) {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(lingeringDust);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactGlass {
    class ImpactDust1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustGlass1);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactDust2 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustGlass2);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactGlassThin {
    class ImpactDust1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustGlass1);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactDust2 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustGlass2);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactWood {
    class ImpactDustOut {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactDustWoodOut);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class WoodChippingsOut1 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(woodChippingsOut1);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class WoodChippingsOut2 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(woodChippingsOut2);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
class ImpactMetal {
    class SparksLight {
        simulation = "light";
        type = "SparksLight";
        position[] = {0,0,0};
        intensity = 0.001;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactSmoke {
		simulation = "particles";
        qualityLevel = -1;
		type = "ImpactSmoke";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
    };
    class ImpactSparks1 {
        simulation = "particles";
        qualityLevel = -1;
        type = "ImpactSparks1";
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.5;
    };
    class ImpactSparks2 {
        simulation = "particles";
        qualityLevel = -1;
        type = QGVAR(impactSpark);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.5;
    };
};
class GVAR(impactMetal_API) {
    class SparksLight1 {
      position[] = {0,0,0};
      simulation = "light";
      type = "SparksLight";
      intensity = 0.001;
      interval = 1;
      lifeTime = 0.5;
    };
    class SparksLight2 {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class ImpactSparks {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSparks2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactSmoke {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSmoke2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ExplosionAmmoFlash {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ExplosionAmmoSmoke {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
    class ExplosionSparks1 {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.3;
    };
    class ExplosionSparks2 {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 0.001;
        lifeTime = 0.3;
    };
};
class GVAR(impactGlass_API) {
    class GlassShard {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassShard1";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GlassShard2 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassShard2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GlassDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassDust";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
    class GVAR(explosionSparks1) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.3;
    };
    class GVAR(explosionSparks2) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 0.001;
        lifeTime = 0.3;
    };
};
class GVAR(impactGlassThin_API) {
    class GlassShard1 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassShard1";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GlassShard2 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassShard2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GlassDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "GlassDust";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(impactWood_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactDustWood";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class WoodChippings1 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "WoodChippings1";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class WoodChippings2 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "WoodChippings2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(impactPlaster_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactDustPlaster";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcrete {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactConcrete";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
    class GVAR(explosionSparks1) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.3;
    };
    class GVAR(explosionSparks2) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 0.001;
        lifeTime = 0.3;
    };
};
class GVAR(impactRubber_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSmoke";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(impactBlood_API) {
    class Blood {
        position[] = {0,0,0};
        simulation = "particles";
        type = "Blood";
        intensity = 1;
        interval = 1;
        lifeTime = 2;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(impactConcrete_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactDustConcrete";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactDust2 {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactDustConcrete2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcrete {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactConcrete";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactConcreteWall {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactConcreteWall1";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
    class GVAR(explosionSparks1) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.3;
    };
    class GVAR(explosionSparks2) {
        simulation = "particles";
        type = QGVAR(explosionSparks);
        position[] = {0,0,0};
        intensity = 1;
        interval = 0.001;
        lifeTime = 0.3;
    };
};
class GVAR(impactHay_API) {
    class HayChippings1 {
        simulation = "particles";
        type = "HayChippings1";
        position[] = {0,0,0};
        qualityLevel = 2;
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSmoke";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
    class Sound {
        simulation = "sound";
        type = "SFX_ImpactHay";
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 10;
    };
};
class GVAR(impactPlastic_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSmoke2";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(impactTyre_API) {
    class ImpactDust {
        position[] = {0,0,0};
        simulation = "particles";
        type = "ImpactSmoke";
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.1;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 2;
    };
};
class GVAR(empty) {
    class nothing {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(noFX);
        intensity = 0;
        interval = 1;
        lifeTime = 0;
    };
};
class GVAR(explosionAmmoExplosion_API) {
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 0.1;
        interval = 1;
        lifeTime = 0.3;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.2;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 0.4;
    };
};
class GVAR(explosionAmmoCrater_API) {
    class GVAR(explosionAmmoStones) {
        position[] = {0,0,0};
        simulation = "particles";
        type = "DirtSmall";
        intensity = 0.5;
        interval = 1;
        lifeTime = 1;
    };
    class GVAR(explosionAmmoFlash) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(explosionAmmoFlash);
        intensity = 0.1;
        interval = 1;
        lifeTime = 0.3;
    };
    class GVAR(sparksLight) {
        position[] = {0,0,0};
        simulation = "light";
        type = "GrenadeExploLight";
        intensity = 0.01;
        interval = 1;
        lifeTime = 0.2;
    };
    class GVAR(explosionAmmoSmoke) {
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVAR(impactSmoke);
        intensity = 2;
        interval = 1;
        lifeTime = 0.4;
    };
};
