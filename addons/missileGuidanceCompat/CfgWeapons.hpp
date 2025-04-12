class CfgWeapons {
    class ACEGVAR(missile_sdb,sdb);
    class GVAR(lsdb): ACEGVAR(missile_sdb,sdb) {
        displayName = "GBU-39B/B [POT]";
        magazines[] = {
            QGVAR(magazine_bomb_LSDB_x1),
            QGVAR(PylonRack_bomb_LSDB_x4)
        };
    };
};
