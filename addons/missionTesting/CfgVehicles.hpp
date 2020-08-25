class CfgVehicles {
    class Module_F;
    class GVAR(MissionTesting): Module_F {
        author = QUOTE(PREFIX);
        category = QGVAR(missionTestingFaction);
        scope = 1;
        scopeCurator = 2;
        isGlobal = 0;
        isTriggerActivated = 0;
        displayName = "Mission Testing";
        function = QFUNC(displayMenu);
    };
};
