class CfgMagazines {
    class ACEGVAR(missile_sdb,magazine_bomb_SDB_x1);
    class ACEGVAR(missile_sdb,PylonRack_bomb_SDB_x4);
    class GVAR(magazine_bomb_LSDB_x1): ACEGVAR(missile_sdb,magazine_bomb_SDB_x1) {
        displayName = "1x GBU-39B/B LSDB [POT]";
        ammo = QGVAR(lsdb);
    };

    class GVAR(PylonRack_bomb_LSDB_x4): ACEGVAR(missile_sdb,PylonRack_bomb_SDB_x4) {
        displayName = "4x GBU-39B/B LSDB [POT]";
        ammo = QGVAR(lsdb);
        pylonWeapon = QGVAR(lsdb);
    };
};
