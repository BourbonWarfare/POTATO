class ctrlToolbox;

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class GVAR(fireTeamControl): Title {
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(teamAttributeLoad));
            attributeSave = QUOTE(_this call FUNC(teamAttributeSave));
            class Controls: Controls {
                class Title: Title{};
                class Value: ctrlToolbox {
                    idc = TEAM_COLOR_IDC;
                    style = "0x02";
                    x = "48 * (pixelW * pixelGrid * 0.50)";
                    w = "82 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                    rows = 1;
                    columns = 5;
                    strings[] = {TEAM_COLOR_STRINGS};
                    values[] = {TEAM_COLORS};
                    onToolboxSelChanged = QUOTE(_this call FUNC(teamColorChange));
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Team Color";
                collapsed = 1;
                class Attributes {
                    class GVAR(unitMarkerColor) {
                        control = QGVAR(fireTeamControl);
                        displayName = "Team Color";
                        tooltip = "Team Color";
                        property = QGVAR(teamColor);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setColor));
                        typeName = "STRING";
                        condition = "objectBrain";
                        class values {
                            class 1 { name = "white"; value = "MAIN";};
                            class 2 { name = "red"; value = "RED"; };
                            class 3 { name = "green"; value = "GREEN"; };
                            class 4 { name = "blue"; value = "BLUE"; };
                            class 5 { name = "yellow"; value = "YELLOW"; };
                        };
                        defaultValue = "'MAIN'";
                    };
                };
            };
        };
    };
};
