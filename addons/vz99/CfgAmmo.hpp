class CfgAmmo {
    class SmokeShellArty;
    class ShotDeployBase;
    class Sh_82mm_AMOS;
    class Flare_82mm_AMOS_White;

    //Smokes:
    class GVAR(deploy_smokeWhite): SmokeShellArty {
        smokeColor[] = {1,1,1,1};
        effectsSmoke = QEGVAR(filledSmoke,bigSmoke);
    };
    class GVAR(deploy_smokeRed): SmokeShellArty {
        smokeColor[] = {1,0,0,1};
        effectsSmoke = QEGVAR(filledSmoke,bigSmoke);
    };
    class GVAR(ammo_smokeWhite): ShotDeployBase {
        model = "\A3\weapons_f\ammo\shell";
        submunitionAmmo = QGVAR(deploy_smokeWhite);
    };
    class GVAR(ammo_smokeRed): ShotDeployBase {
        model = "\A3\weapons_f\ammo\shell";
        submunitionAmmo = QGVAR(deploy_smokeRed);
    };

    //Flare:
    class GVAR(ammo_flare): Flare_82mm_AMOS_White {
        // timeToLive = 45;
        // model = "\A3\weapons_f\ammo\shell";
        // effectFlare = "CounterMeasureFlare";
        // aimAboveTarget[] = {30,60,120,180,240,300,360};
        // aimAboveDefault = 4;
        // triggerTime = -1;
        // triggerSpeedCoef = 1;
        // lightColor[] = {0.95,0.95,1,0.5};
        // smokeColor[] = {1,1,1,0.5};
        // intensity = 10000;
    };



    //HE:
    class GVAR(ammo_he): Sh_82mm_AMOS {
        SoundSetExplosion[] = {"Mortar_Exp_SoundSet","Mortar_Tail_SoundSet","Explosion_Debris_SoundSet"};
        hit = 120;
        indirectHit = 24;
        indirectHitRange = 12;
        cost = 200;
        muzzleEffect = "";
        class CamShakeExplode {
            power = "(82*0.2)";
            duration = "((round (82^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = "((18 + 82^0.5)*8)";
        };
        class CamShakeHit {
            power = 82;
            duration = "((round (82^0.25))*0.2 max 0.2)";
            frequency = 20;
            distance = 1;
        };
        class CamShakeFire {
            power = "(82^0.25)";
            duration = "((round (82^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = "((82^0.5)*8)";
        };
        class CamShakePlayerFire {
            power = 0.01;
            duration = 0.1;
            frequency = 20;
            distance = 1;
        };
    };
};
