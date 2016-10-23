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
        displayName = "Side Marker";
        icon = QUOTE(PATHTOF(UI\sideMarker_ca.paa));
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(sideMarker);

        class Attributes {
            class east {
                displayName = "Show to east:";
                control = "Checkbox";
                property = QGVAR(east);
                defaultValue = "(false)";
            };
            class west: east {
                displayName = "Show to west:";
                property = QGVAR(west);
            };
            class independent: east {
                displayName = "Show to independent:";
                property = QGVAR(independent);
            };
            class civilian: east {
                displayName = "Show to civilians:";
                property = QGVAR(civilian);
            };
            class text {
                displayName = "Marker text:";
                control = "Edit";
                property = QGVAR(text);
                defaultValue = "''";
            };
            class color {
                control = QGVAR(sideMarkerColor);
                property = QGVAR(color);
                defaultValue = "'ColorBlack'";
            };
            class icon {
                control = QGVAR(sideMarkerIcon);
                property = QGVAR(icon);
                defaultValue = "'mil_dot_noShadow'";
            };
        };
        /*
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
                displayName = "Color";
                typeName = "NUMBER";
                class values {
                    class black { name = "black"; value = 0; default = 1; };
                    class red { name = "red"; value = 1; };
                    class green { name = "green"; value = 2; };
                    class blue { name = "blue"; value = 3; };
                };
            };
            class icon {
                displayName = "Icon";
                typeName = "String";
                control = QGVAR(sideMarkerIcon);
            };
        };
        class ModuleDescription: ModuleDescription {
            position = 1;
            description = "Adds a marker for only one side";
            sync[] = {};
        }
        */;
    };

    class GVAR(zeus_missionHint): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 1;
        displayName = "Mission Hint";
        function = QFUNC(zeus_missionHint);
        curatorInfoType = QGVAR(RscDisplayAttributes_missionHint);
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(zeus_globalSetSkill): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 1;
        displayName = "Global Set AI Skill";
        function = QFUNC(zeus_globalSetSkill);
        curatorInfoType = QGVAR(RscDisplayAttributes_globalSetSkill);
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };
};
