class CfgAmmo {
    class BulletBase;
    class AMMO_CLASS(22_lr): BulletBase {
        TYPICAL_CONFIG;
        dangerRadiusBulletClose = HIT_DANGER_SMALL;
        dangerRadiusHit = FLYBY_DANGER_SMALL;
        suppressionRadiusBulletClose = FLYBY_SUPPRESSION_SMALL;
        suppressionRadiusHit = HIT_SUPPRESSION_SMALL;
        hit = 6;
        audibleFire = AUDIBLE_FIRE_SMALL;
        caliber = 0.7;
        aiAmmoUsageFlags = AI_AMMO_USAGE_FLAGS_SMALL;
        ACE_damageType = "bullet";
        ace_vehicle_damage_incendiary = 0;
        typicalSpeed = TYPICAL_SPEED_SMALL;
        airFriction = AIR_FRICTION_SMALL;
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
    TRACER_CLASSES(22_lr);

    CREATE_SMALL_AMMO(32_acp);
    CREATE_SMALL_AMMO(45_acp);
    CREATE_SMALL_AMMO(10x25);
    CREATE_SMALL_AMMO(46x30);
    CREATE_SMALL_AMMO(545x39);
    CREATE_SMALL_AMMO(556x45);
    CREATE_SMALL_AMMO(57x28);
    CREATE_SMALL_AMMO(580x42);
    CREATE_SMALL_AMMO(65x39);
    CREATE_SMALL_AMMO(75x55);
    CREATE_SMALL_AMMO(762x25);
    CREATE_SMALL_AMMO(9x18);
    CREATE_SMALL_AMMO(9x19);
    CREATE_SMALL_AMMO(9x21);
    CREATE_SMALL_AMMO(9x39);

    CREATE_MEDIUM_AMMO(762x39);
    CREATE_MEDIUM_AMMO(762x51);
    CREATE_MEDIUM_AMMO(762x54);
    CREATE_MEDIUM_AMMO(792x57);
    CREATE_MEDIUM_AMMO(300_wm);
    CREATE_MEDIUM_AMMO(303_b);
    CREATE_MEDIUM_AMMO(338_lm);
    CREATE_MEDIUM_AMMO(338_nm);
    CREATE_MEDIUM_AMMO(408);

    CREATE_LARGE_AMMO(93x64);
    CREATE_LARGE_AMMO(50_bmg);
    CREATE_LARGE_AMMO(127x108);
    CREATE_LARGE_AMMO(127x108_slap);
};