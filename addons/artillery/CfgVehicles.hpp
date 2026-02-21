class CfgVehicles {
    class Module_F;
    class GVAR(addArtilleryAmmo): Module_F {
        author = QUOTE(PREFIX);
        scope = 2;
        scopeCurator = 0;
        displayName = "Add Artillery Magazines";
        category = QGVAR(modules);
        function = "";
        isTriggerActivated = 0;
        isGlobal = 2;
        class Attributes {
            class magazineListBox {
                displayName = "Artillery Magazines";
                control = QGVAR(attribute);
                property = QGVAR(attribute);
                expression = QUOTE(call FUNC(moduleArtyMagInit));
                defaultValue = "[]";
                validate = "none";
                value = 0;
            };
        };
    };
    class GVAR(registerArtillery): Module_F {
        author = QUOTE(PREFIX);
        scope = 2;
        scopeCurator = 2;
        displayName = "Register Nearby Artillery (50m)";
        category = QGVAR(modules);
        function = QFUNC(moduleRegisterArty);
        isTriggerActivated = 0;
        isGlobal = 2;
        class Attributes {};
    };
    class GVAR(openMissionDialog): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        displayName = "Open Artillery Interface";
        category = QGVAR(modules);
        function = QFUNC(moduleOpenDialog);
        isTriggerActivated = 0;
        isGlobal = 2;
        class Attributes {};
    };
    class GVAR(clearMission): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        displayName = "Clear Active Mission (50m)";
        category = QGVAR(modules);
        function = QFUNC(moduleClearMission);
        isGlobal = 2;
        class Attributes {};
    };

};
