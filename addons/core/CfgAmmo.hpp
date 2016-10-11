class CfgAmmo {
    class SmokeShell;
    class GVAR(potato): SmokeShell {
        hit = 1;
        model = QPATHTOF(data\potato_ammo.p3d);
        effectsSmoke = "EmptyEffect";
        grenadeFireSound[] = {};
        grenadeBurningSound[] = {};
    };
};
