class CfgMagazines {
    class 8Rnd_82mm_Mo_shells;

    //HE w/ impact fuze
    class GVAR(HE): 8Rnd_82mm_Mo_shells {
        picture = QUOTE(PATHTOF(ui\shell_ca.paa));
        author = "PabstMirror";
        count = 1;
        mass = 30;

        GVAR(base) = QGVAR(HE);
        displayName = "vz99 60mm HE Impact Fuze";
        descriptionShort = "60mm HE Shell<br/>For use in the vz99 mortar<br/>With a basic impact fuze";
        displayNameShort = "HE-IMP";
        ammo = QGVAR(ammo_he);
        initSpeed = 110;
        scope = 2;
        type = 2 * 256;
    };
    class GVAR(HE_charge0): GVAR(HE) {
        initSpeed = 70;
        scope = 1;
        type = 0;
    };

    //HE w/ multi fuze
    class GVAR(HE_multi): GVAR(HE) {
        GVAR(base) = QGVAR(HE_multi);
        displayName = "vz99 60mm HE Multi Fuze";
        descriptionShort = "60mm HE Shell<br/>For use in the vz99 mortar<br/>With a multi-option fuze (Impact, Near Surface, Proximity)";
        displayNameShort = "HE-MULTI";
        initSpeed = 110;
        GVAR(fuze) = "";
    };
    class GVAR(HE_multi_charge0): GVAR(HE_multi) {
        initSpeed = 70;
        type = 0;
    };

    //HE w/ proxy fuze
    class GVAR(HE_PRX): GVAR(HE_multi) {
        GVAR(base) = QGVAR(HE_multi);
        displayName = "vz99 60mm HE Proximity Fuze";
        descriptionShort = "60mm HE Shell<br/>For use in the vz99 mortar<br/>With a proximity fuze";
        displayNameShort = "HE-PRX";
        initSpeed = 110;
        GVAR(fuze) = "prx";
    };
    class GVAR(HE_PRX_charge0): GVAR(HE_PRX) {
        initSpeed = 70;
        type = 0;
    };

    //Smokes
    class GVAR(smokeWhite): GVAR(HE) {
        GVAR(base) = QGVAR(smokeWhite);
        displayName = "vz99 60mm Smoke (White)";
        descriptionShort = "60mm HE White Smoke Shell<br/>For use in the vz99 mortar";
        displayNameShort = "SMOKE (White)";
        ammo = QGVAR(ammo_smokeWhite);
        initSpeed = 110;
    };
    class GVAR(smokeWhite_charge0): GVAR(smokeWhite) {
        initSpeed = 70;
        type = 0;
    };

    class GVAR(smokeRed): GVAR(HE) {
        GVAR(base) = QGVAR(smokeRed);
        displayName = "vz99 60mm Smoke (Red)";
        descriptionShort = "60mm HE Red Smoke Shell<br/>For use in the vz99 mortar";
        displayNameShort = "SMOKE (Red)";
        ammo = QGVAR(ammo_smokeRed);
        initSpeed = 110;
    };
    class GVAR(smokeRed_charge0): GVAR(smokeRed) {
        initSpeed = 70;
        type = 0;
    };

    //Flare
    class GVAR(flare): GVAR(HE) {
        GVAR(base) = QGVAR(flare);
        displayName = "vz99 60mm Flare (White)";
        descriptionShort = "60mm HE Flare Shell<br/>For use in the vz99 mortar";
        displayNameShort = "FLARE";
        ammo = QGVAR(ammo_flare);
        initSpeed = 110;
    };
    class GVAR(flare_charge0): GVAR(flare) {
        initSpeed = 70;
        type = 0;
    };
};
