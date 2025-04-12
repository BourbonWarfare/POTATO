class CfgAmmo {
    class ShellBase;
    class ace_dragon_serviceCharge: ShellBase {
        soundSetExplosion[] = {}; // for JSRS
    };
    class ammo_Bomb_SDB;
    class ACEGVAR(missile_sdb,sdb): ammo_Bomb_SDB {
        class ace_missileguidance;
    };
    class GVAR(lsdb): ACEGVAR(missile_sdb,sdb) {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            defaultSeekerType = "LSDB";
            seekerTypes[] = { "LSDB", "SALH", "GPS" };

        };
    };
};

