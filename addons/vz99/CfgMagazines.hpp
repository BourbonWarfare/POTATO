class CfgMagazines {
    class 8Rnd_82mm_Mo_shells;

    class GVAR(HE): 8Rnd_82mm_Mo_shells {
        picture = "\A3\weapons_F\data\UI\m_30stanag_CA.paa";
        author = "Pab";
        count = 1;
        mass = 20;
        
        
        displayName = "vz99 HE Shell";
        displayNameShort = "HE";
        GVAR(base) = QGVAR(HE);
        initSpeed = 110;
        ammo = QGVAR(ammo_he);
    };
    class GVAR(HE_charge0): GVAR(HE) {
        initSpeed = 70;
    };

    class GVAR(smokeWhite): GVAR(HE) {
        GVAR(base) = QGVAR(smokeWhite);
        displayName = "Smoke Mortar Shell (White)";
        displayNameShort = "SMOKE (White)";
        ammo = QGVAR(ammo_smokeWhite);
        initSpeed = 110;
    };
    class GVAR(smokeWhite_charge0): GVAR(smokeWhite) {
        initSpeed = 70;
    };

    class GVAR(smokeRed): GVAR(HE) {
        GVAR(base) = QGVAR(smokeRed);
        displayName = "Smoke Mortar Shell (Red)";
        displayNameShort = "SMOKE (Red)";
        ammo = QGVAR(ammo_smokeRed);
        initSpeed = 110;
    };
    class GVAR(smokeRed_charge0): GVAR(smokeWhite) {
        initSpeed = 70;
    };
};
