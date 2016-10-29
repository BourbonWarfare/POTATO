class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(briefings)};
                };
                class GVAR(briefings) {
                    text = "Mission Briefings";
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
            attributeSave = QUOTE(_this call FUNC(briefingAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(briefingAttributeLoad));

            h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
            class Controls: Controls {
                class Title: Title {
                    h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
                };
                class Value: Value {
                    idc = TEXT_IDC;
                    style = 16; //multi line
                    h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Group Briefing";
                collapsed = 1;
                class Attributes {
                    class GVAR(brief) {
                        displayName = "Group Briefing";
                        tooltip = "";
                        property = QGVAR(brief);
                        control = QGVAR(bigEdit);
                        defaultValue = "''";
                        typeName = "STRING";
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setBriefingVar));
                    };
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Unit Briefing";
                collapsed = 1;
                class Attributes {
                    class GVAR(brief) {
                        condition = "objectBrain";
                        displayName = "Unit Briefing";
                        tooltip = "";
                        property = QGVAR(brief);
                        control = QGVAR(bigEdit);
                        defaultValue = "''";
                        typeName = "STRING";
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setBriefingVar));
                    };
                };
            };
        };
    };

    class Mission {
        class GVAR(briefings) {// Custom section class, everything inside will be opened in one window
            displayName = "Side Briefings (SHIFT + Enter to add a new line)"; // Text visible in the window title as "Edit <displayName>"
            display = "Display3DENEditAttributes"; // Optional - display for attributes window. Must have the same structure and IDCs as the default Display3DENEditAttributes
            class AttributeCategories {
                class WestBriefing {
                    displayName = "West Briefing"; // Category name visible in Edit Attributes window
                    collapsed = 0; // When 1, the category is collapsed by default
                    class Attributes {
                        class GVAR(briefWestSituation) {
                            displayName = "West Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefWestSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
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
                    };
                };
                class EastBriefing {
                    displayName = "East Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefEastSituation) {
                            displayName = "East Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefEastSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
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
                    };
                };
                class IndependentBriefing {
                    displayName = "Independent Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefIndependentSituation) {
                            displayName = "Independent Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefIndependentSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
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
                    };
                };
                class CivilianBriefing {
                    displayName = "Civilian Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(briefCivilianSituation) {
                            displayName = "Civilian Situation";
                            tooltip = "Insert general information about the situation here";
                            property = QGVAR(briefCivilianSituation);
                            control = QGVAR(bigEdit);
                            defaultValue = "''";
                            typeName = "STRING";
                        };
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
                    };
                };
                class ZeusBriefing {
                    displayName = "Zeus Briefing";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(zeusIntent) {
                            displayName = "Zeus Intent";
                            tooltip = "Basic overview of what the Zeus GM should do / units they should use (OPTIONAL)";
                            property = QGVAR(zeusIntent);
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
