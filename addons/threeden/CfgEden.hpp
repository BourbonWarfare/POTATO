class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class Attributes {
                    items[] += {QGVAR(briefings)};
                };
                class GVAR(briefings) {
                    text = "Mission Side Briefings";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(briefings)););
                };
            };
        };
    };
};
class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class Edit: Title {
            class Controls: Controls {
                class Title: Title {};
                class Value;
            };
        };
        class GVAR(bigEdit): Edit {
            h = "5 * 5 * (pixelH * 1.25 * 4)";
            class Controls: Controls {
                class Title: Title {
                    h = "5 * 5 * (pixelH * 1.25 * 4)";
                    w = "30 * (pixelW * 1.25 * 4)";
                };
                class Value: Value {
                    style = 16; //multi line
                    x = "30 * (pixelW * 1.25 * 4)";
                    w = "100 * (pixelW * 1.25 * 4)";
                    h = "5 * 5 * (pixelH * 1.25 * 4)";
                };
            };
        };
    };


    class Mission {
        class GVAR(briefings) {// Custom section class, everything inside will be opened in one window
            displayName = "Side Briefings (<br/> for newLine)"; // Text visible in the window title as "Edit <displayName>"
            display = "Display3DENEditAttributes"; // Optional - display for attributes window. Must have the same structure and IDCs as the default Display3DENEditAttributes
            class AttributeCategories {
                class WestBriefing {
                    displayName = "West Briefing"; // Category name visible in Edit Attributes window
                    collapsed = 0; // When 1, the category is collapsed by default
                    class Attributes {
                        class GVAR(briefWestMission) {
                            displayName = "West Mission"; // Name assigned to UI control class Title
                            tooltip = "Insert the mission here."; // Tooltip assigned to UI control class Title
                            property = QGVAR(briefWestMission); // Unique config property name saved in SQM
                            control = QGVAR(bigEdit); // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes
                            defaultValue = "''";
                            typeName = "STRING"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
                        };
                        class GVAR(briefWestAdministration) {
                            displayName = "West Administration";
                            tooltip = "Insert information on administration and logistics here";
                            property = QGVAR(briefWestAdministration);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefWestSituation) {
                            displayName = "West Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefWestSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                    };
                };
                class EastBriefing {
                    displayName = "East Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefEastMission) {
                            displayName = "East Mission";
                            tooltip = "Insert the mission here.";
                            property = QGVAR(briefEastMission);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefEastAdministration) {
                            displayName = "East Administration";
                            tooltip = "Insert information on administration and logistics here";
                            property = QGVAR(briefEastAdministration);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefEastSituation) {
                            displayName = "East Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefEastSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                    };
                };
                class IndependentBriefing {
                    displayName = "Independent Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefIndependentMission) {
                            displayName = "Independent Mission";
                            tooltip = "Insert the mission here.";
                            property = QGVAR(briefIndependentMission);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefIndependentAdministration) {
                            displayName = "Independent Administration";
                            tooltip = "Insert information on administration and logistics here";
                            property = QGVAR(briefIndependentAdministration);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefIndependentSituation) {
                            displayName = "Independent Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefIndependentSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                    };
                };
                class CivilianBriefing {
                    displayName = "Civilian Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefCivilianMission) {
                            displayName = "Civilian Mission";
                            tooltip = "Insert the mission here.";
                            property = QGVAR(briefCivilianMission);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefCivilianAdministration) {
                            displayName = "Civilian Administration";
                            tooltip = "Insert information on administration and logistics here";
                            property = QGVAR(briefCivilianAdministration);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                        class GVAR(briefCivilianSituation) {
                            displayName = "Civilian Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefCivilianSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
                    };
                };
            };
        };
    };
};
