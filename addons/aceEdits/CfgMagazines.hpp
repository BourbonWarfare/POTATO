class CfgMagazines {
    class magazine_Bomb_SDB_x1;
    class ACEGVAR(missile_sdb,magazine_bomb_SDB_x1): magazine_Bomb_SDB_x1 {};
    class GVAR(magazine_bomb_LSDB_x1): ACEGVAR(missile_sdb,magazine_bomb_SDB_x1) {
        ammo = QGVAR(lsdb);
        author = "Lambda.Tiger";
        displayName = "1x GBU-39B/B LSDB [POT]";
        displayNameShort = "GBU-39B/B [POT]";
    };
    class GVAR(PylonRack_bomb_LSDB_x1): GVAR(magazine_bomb_LSDB_x1) {
        hardpoints[] = {"B_BOMB_PYLON", "B_SDB_QUAD_RAIL"};
        mass = 93;
        model = "\A3\Weapons_F\DynamicLoadout\PylonPod_1x_Missile_AGM_02_F.p3d";
    };

    class PylonRack_Bomb_SDB_x4: magazine_Bomb_SDB_x1 {
        hardpoints[] = {"B_BOMB_PYLON", "B_SDB_QUAD_RAIL"};
        mass = 422;
    };
    class ACEGVAR(missile_sdb,PylonRack_bomb_SDB_x4): PylonRack_Bomb_SDB_x4 {};
    class GVAR(PylonRack_bomb_LSDB_x4): ACEGVAR(missile_sdb,PylonRack_bomb_SDB_x4) {
        ammo = QGVAR(lsdb);
        author = "Lambda.Tiger";
        displayName = "4x GBU-39B/B LSDB [POT]";
        displayNameShort = "GBU-39B/B [POT]";
        pylonWeapon = QGVAR(lsdb);
    };
};
