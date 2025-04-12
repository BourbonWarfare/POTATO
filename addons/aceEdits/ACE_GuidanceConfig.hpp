class ACEGVAR(missileGuidance,SeekerTypes) {
    class GPS;
    class MULTI: GPS {
        functionName = QFUNC(seekerType_multi); // didn't want to prep functions here
        hudInfo = QACEFUNC(missile_hud,info_salh); // SALH more important than GPS info
    };
};