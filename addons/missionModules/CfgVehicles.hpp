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
    class GVAR(moveHcsToModule): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        displayName = "Move headless clients to module";
        category = QEGVAR(core,util);
        function = QFUNC(moveHcsToModule);
        isTriggerActivated = 0;
        isGlobal = 0;
        curatorCost = 0;
        function = QFUNC(createEntityZeus);
        class Arguments {};
        class Attributes {};
    };

    class GVAR(sideMarker): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);;
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
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "(false)";
            };
            class west: east {
                displayName = "Show to west:";
                property = QGVAR(west);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class independent: east {
                displayName = "Show to independent:";
                property = QGVAR(independent);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class civilian: east {
                displayName = "Show to civilians:";
                property = QGVAR(civilian);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class text {
                displayName = "Marker text:";
                control = "Edit";
                property = QGVAR(text);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "''";
            };
            class direction {
                displayName = "Marker direction:";
                control = QGVAR(sideMarkerDir);
                property = QGVAR(direction);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "0";
            };
            class color {
                control = QGVAR(sideMarkerColor);
                property = QGVAR(color);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'ColorBlack'";
            };
            class icon {
                control = QGVAR(sideMarkerIcon);
                property = QGVAR(icon);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'mil_dot_noShadow'";
            };
        };
    };

    class GVAR(zeus_missionHint): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);;
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
        category = QEGVAR(core,util);
        scope = 1;
        scopeCurator = 2;
        isGlobal = 1;
        displayName = "Global Set AI Skill";
        function = QFUNC(setSkillsModule);
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(zeus_banziCharge): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX); // TODO: AI Behvaiors cleanup
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 0;
        isGlobal = 2;
        displayName = "Banzi Attack!";
        function = QFUNC(zeus_banziCharge);
        curatorCanAttach = 1;
    };
};
