class ACEGVAR(missileGuidance,SeekerTypes) {
    class GPS;
    class LSDB: GPS {
        functionName = QEFUNC(aceEdits,seekerType_LSDB); // didn't want to prep functions here
        hudInfo = QACEGVAR(missile_hud,info_salh); // SALH more important than GPS info
    };
};