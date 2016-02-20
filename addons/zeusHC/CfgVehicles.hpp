class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits;
        class ModuleDescription;
        class AttributesBase {
            class Edit;
            class Combo;
        };
    };
    class GVAR(create_fireteam): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 0;
        displayName = "HC: Spawn Fireteam";
        // icon = "\a3\Modules_F_Curator\Data\iconEndMission_ca.paa";
        // portrait = "\a3\Modules_F_Curator\Data\portraitEndMission_ca.paa";
        function = QFUNC(createEntityZeus);
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };
};
