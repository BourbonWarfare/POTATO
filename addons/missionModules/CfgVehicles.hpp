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

    class GVAR(sideMarker): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 2;
        displayName = "Side Only Marker";
        icon = QUOTE(PATHTOF(UI\sideMarker_ca.paa));
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(sideMarker);
        class Arguments {
            class side {
                displayName = "Side";
                typeName = "NUMBER";
                class values {
                    class west { name = "West"; value = 0; default = 1; };
                    class east { name = "East"; value = 1; };
                    class resistance { name = "Independent/Resistance"; value = 2; };
                    class civilian { name = "Civilian"; value = 3; };
                    class all { name = "All"; value = 4; };
                };
            };
            class text {
                displayName = "Text";
                description = "Marker text (can be blank)";
                defaultValue = "";
                typeName = "STRING";
            };
            class color {
                displayName = "Side";
                typeName = "NUMBER";
                class values {
                    class black { name = "black"; value = 0; default = 1; };
                    class red { name = "red"; value = 1; };
                    class green { name = "green"; value = 2; };
                    class blue { name = "blue"; value = 3; };
                };
            };
        };
        class ModuleDescription: ModuleDescription {
            position = 1;
            description = "Adds a marker for only one side";
            sync[] = {};
        };
    };


    class GVAR(test): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 2;
        scopeCurator = 2;
        isTriggerActivated = 1;
        displayName = "TEST ";
        icon = "\a3\Modules_F_Curator\Data\iconEndMission_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitEndMission_ca.paa";
        function = QFUNC(test);
        curatorInfoType = QGVAR(RscDisplayAttributes_missionHint);
        curatorCost = 0;
        class Arguments {};
        class Attributes: AttributesBase {
            class asdasd: Edit {
                displayName = "asdfdasfdgsfv Zeus";
                tooltip = "Variable name of 'Zeus' modules. Works together with synchronized Zeus modules.";
                property = "fsdfds";
            };
            class Type: Combo {
                displayName = "AAA";
                property = "asdf";
                typeName = "BOOL";
                defaultValue = 1;
                class values {
                    class Whitelist {
                        name = "Inside areas";
                        value = 1;
                        default = 1;
                    };
                    class Blacklist {
                        name = "Outside areas";
                        value = 0;
                    };
                };
            };
            class ModuleDescription: ModuleDescription {
            };
        };
    };
};

