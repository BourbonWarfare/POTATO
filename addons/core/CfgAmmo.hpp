class CfgAmmo {
    class SmokeShell;
    class GVAR(potato): SmokeShell {
        hit = 1;
        cost = 30;
        aiAmmoUsageFlags = "64 + 128 + 256 + 512";
        model = QPATHTOF(data\potato_ammo.p3d);
        effectsSmoke = "EmptyEffect";
        grenadeFireSound[] = {};
        grenadeBurningSound[] = {};
    };
};
