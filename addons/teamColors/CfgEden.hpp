class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Team Color";
                collapsed = 1;
                class Attributes {
                    class GVAR(unitMarkerColor) {
                        control = "Combo";
                        displayName = "Team Color";
                        tooltip = "Team Color";
                        property = QGVAR(teamColor);
                        expression = QUOTE(SETPVAR(_this,QGVAR(teamColor),_value););
                        typeName = "STRING";
                        condition = "objectBrain";
                        class values {
                            class 1 { name = "white"; value = "MAIN"; default = 1; };
                            class 2 { name = "red"; value = "RED"; };
                            class 3 { name = "green"; value = "GREEN"; };
                            class 4 { name = "blue"; value = "BLUE"; };
                            class 5 { name = "yellow"; value = "YELLOW"; };
                        };
                    };
                };
            };
        };
    };
};
