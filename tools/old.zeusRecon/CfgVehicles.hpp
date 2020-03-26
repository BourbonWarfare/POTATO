class CfgVehicles {
    class ACE_Module;
    class GVAR(module): ACE_Module {
        author = "Pabst Mirror";
        category = QUOTE(PREFIX);
        displayName = "Use Zeus Recon";
        function = QFUNC(moduleInit);
        scope = 2;
        isGlobal = 1;
        // icon = QPATHTOF(UI\Icon_Module_Respawn_ca.paa);
        class Arguments {
            class addPrePlacedUnits {
                displayName = "Add pre-placed units";
                description = "Auto add non-playable units to zeus";
                typeName = "BOOL";
                defaultValue = 0;
            };
        };
    };
};
