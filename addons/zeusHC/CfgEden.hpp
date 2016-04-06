class Cfg3DEN {
    class ADDON {
        class Group {
            class AttributeCategories {
                class GVAR(hcAttributeGroup) {
                    displayName = "POTATO: HC";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(move_to_hc) {
                            displayName = "Move Group to HC";
                            tooltip = "";
                            property = QGVAR(move_to_hc);
                            control = "Checkbox";
                            defaultValue = "false";
                            typeName = "BOOL";
                            expression = QUOTE([ARR_2(_this,_value)] call FUNC(transferSetVar));
                        };
                    };
                };
            };
        };
    };
};
