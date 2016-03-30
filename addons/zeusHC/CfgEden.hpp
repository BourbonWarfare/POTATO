class Cfg3DEN {
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Move Group to HC";
                collapsed = 0;
                class Attributes {
                    class GVAR(move_to_hc) {
                        displayName = "Move Group to HC";
                        tooltip = "";
                        property = QGVAR(move_to_hc);
                        control = "Checkbox";
                        defaultValue = "false";
                        typeName = "BOOL";
                        expression = QUOTE(_this setVariable [ARR_3(QUOTE(QGVAR(addGroupToHC)), _value, true)];);
                    };
                };
            };
        };
    };
};
