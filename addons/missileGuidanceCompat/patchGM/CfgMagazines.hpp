class CfgMagazines {
    class gm_1Rnd_milan_heat_dm82;
    class gm_1Rnd_milan_heat_dm82_ace_mg: gm_1Rnd_milan_heat_dm82 {
        ammo = "gm_missile_milan_heat_dm82_ace_mg";
    };
    class gm_1Rnd_milan_heat_dm92;
    class gm_1Rnd_milan_heat_dm92_ace_mg: gm_1Rnd_milan_heat_dm92 {
        ammo = "gm_missile_milan_heat_dm92_ace_mg";
    };
    class gm_6Rnd_maljutka_heat_9m14m;
    class GVARMAIN(gm_6Rnd_maljutka_heat_9m14p): gm_6Rnd_maljutka_heat_9m14m {
        ammo = QGVARMAIN(gm_missile_maljutka_heat_9m14p);
    };
};

class CfgMagazineWells {
    class gm_magazineWell_maljutka_9k14 {
        GVARMAIN(magazines)[] = {QGVARMAIN(gm_6Rnd_maljutka_heat_9m14p)};
    };
};
