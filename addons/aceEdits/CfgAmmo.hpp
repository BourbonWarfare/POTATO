class CfgAmmo {
    class ShellBase;
    class ace_dragon_serviceCharge: ShellBase {
        soundSetExplosion[] = {}; // for JSRS
    };
    class ammo_Bomb_SDB;
    class ACEGVAR(missile_sdb,sdb): ammo_Bomb_SDB {
        ACEGVAR(frag,skip) = 0;
        ACEGVAR(frag,force) = 1;
        ACEGVAR(frag,charge) = 70; // kg guess - 93 kg total
        ACEGVAR(frag,metal) = 16; // kg
        // Wild guess, they slow det velocity to reduce increase deltaP
        ACEGVAR(frag,gurney_c) = 2600;
        ACEGVAR(frag,gurney_k) = 3/5;
        class ace_missileguidance;
        indirectHit = 300; // 10m probably kills from docs
        indirectHitRange = 5;
    };
    class GVAR(lsdb): ACEGVAR(missile_sdb,sdb) {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            defaultSeekerType = "MULTI";
            seekerTypes[] = {"MULTI", "SALH", "GPS"};
            lineGainD = 10;
        };
    };
};
