class CfgAmmo {
    class BulletBase;
    class AMMO_CLASS(556x45): BulletBase {
        airLock = 1;
        indirectHit = 0;
        indirectHitRange = 0;
        cost = 1;
        typicalSpeed = 920;
        airFriction = -0.0012;
        waterFriction = -0.3;
        tracerScale = 1;
        tracerStartTime = 0.05;
        tracerEndTime = 1;

        SMALL_AMMO_CONFIG;

        class CamShakeExplode {
            power = 2.24;
            duration = 0.4;
            frequency = 20;
            distance = 6.7;
        };
        class CamShakeHit {
            power = 5;
            duration = 0.2;
            frequency = 20;
            distance = 1;
        };
    };
    TRACER_CLASSES(556x45);
};