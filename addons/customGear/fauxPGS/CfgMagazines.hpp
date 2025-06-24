class CfgMagazines {
    class CUP_5Rnd_127x99_as50_M;
    class GVAR(5rnd_HE): CUP_5Rnd_127x99_as50_M {
        author = "Potato";
        scope = 2;
        count = 5;
        initSpeed = 210;
        displayName = "30mm 5Rnd HE";
        displayNameShort = "HE";
        descriptionShort = "30mm 5Rnd HE";
        ammo = QGVAR(he);
        // picture = "\z\potato\addons\customGear\fauxPGS\data\ui\pgs_5rnd_he_ca.paa";
    };
    class GVAR(5rnd_HEDP): GVAR(5rnd_HE) {
        displayName = "30mm 5Rnd HEDP";
        displayNameShort = "HEDP";
        descriptionShort = "30mm 5Rnd HEDP";
        ammo = QGVAR(hedp);
    };
    class GVAR(5rnd_airburst): GVAR(5rnd_HE) {
        displayName = "30mm 5Rnd Airburst";
        displayNameShort = "Airburst";
        descriptionShort = "30mm 5Rnd Airburst";
        ammo = QGVAR(airburst);
    };
    class GVAR(5rnd_smoke_white): GVAR(5rnd_HE) {
        displayName = "30mm 5Rnd Smoke-White";
        displayNameShort = "Smoke-White";
        descriptionShort = "30mm 5Rnd Smoke-White";
        ammo = "SmokeShell";
    };
    class GVAR(5rnd_smoke_red): GVAR(5rnd_HE) {
        displayName = "30mm 5Rnd Smoke-Red";
        displayNameShort = "Smoke-Red";
        descriptionShort = "30mm 5Rnd Smoke-Red";
        ammo = "SmokeShellRed";
    };
    class GVAR(5rnd_00buckshot): GVAR(5rnd_HE) {
        displayName = "30mm 5Rnd Buckshot";
        displayNameShort = "Buckshot";
        descriptionShort = "30mm 5Rnd #00 Buckshot";
        initSpeed = 365;
        ammo = QGVAR(00buckshot);
    };
};
