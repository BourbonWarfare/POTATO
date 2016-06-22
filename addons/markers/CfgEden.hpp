class ctrlStatic;

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class Toolbox: Title {
            class Controls: Controls {
                class Title: Title {};
                class Value;
            };
        };
        class GVAR(markerIconSelect): Toolbox {
            attributeLoad = QUOTE((_this controlsGroupCtrl GROUP_MARKER_ICON_IDC) lbsetcursel ([UNIT_MARKERS] find _value););
            attributeSave = QUOTE([UNIT_MARKERS] select (GETMVAR(GVAR(selectedIcon),0)););
            h = "2 * 5 * (pixelH * 1.25 * 4)";
            class Controls: Controls {
                class Title: Title {
                    h = "2 * 5 * (pixelH * 1.25 * 4)";
                };
                class Background: ctrlStatic {
                    x = "48 * (pixelW * 1.25 * 4)";
                    w = "82 * (pixelW * 1.25 * 4)";
                    h = "2 * 5 * (pixelH * 1.25 * 4)";
                    colorBackground[] = {0,0,0,0.5};
                };
                class Value: Value {
                    idc = GROUP_MARKER_ICON_IDC;
                    style = "0x02 + 0x30 + 0x800";
                    h = "2 * 10 * (pixelH * 1.25 * 4)";
                    colorBackground[] = {0,0,0,0};

                    rows = 2;
                    columns = 7;
                    strings[] = {UNIT_MARKERS};
                    values[] = {UNIT_MARKERS};
                    tooltips[] = {
                        "Unkown",
                        "Infantry",
                        "HQ",
                        "MMG",
                        "MAT",
                        "Recon",
                        "Mortar",
                        "Engineers",
                        "APC/IFV",
                        "Tank",
                        "Helicopter",
                        "Plane",
                        "Artillery",
                        "Medic"
                    };
                    onToolboxSelChanged = QUOTE(SETMVAR(GVAR(selectedIcon),_this select 1););
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Group Marker";
                collapsed = 1;
                class Attributes {
                    class GVAR(addGroupMarker) {
                        control = "Checkbox";
                        displayName = "Add Marker";
                        tooltip = "Add marker to group";
                        property = QGVAR(addMarker);
                        expression = QUOTE(SETVAR(_this,GVAR(addMarker),_value););
                        typeName = "BOOL";
                        defaultValue = false;
                    };
                    class GVAR(groupMarkerText) {
                        control = "Edit";
                        displayName = "Marker Text";
                        tooltip = "Group marker text";
                        property = QGVAR(markerText);
                        expression = QUOTE(SETVAR(_this,GVAR(markerText),_value););
                        typeName = "STRING";
                        defaultValue = "";
                    };
                    class GVAR(groupMarkerSize) {
                        control = "Combo";
                        displayName = "Marker Size";
                        tooltip = "Group marker size";
                        property = QGVAR(markerSize);
                        expression = QUOTE(SETVAR(_this,GVAR(markerSize),_value););
                        typeName = "NUMBER";
                        class values {
                            class 1 { name = "small"; value = 16; };
                            class 2 { name = "medium"; value = 24; default = 1; };
                            class 3 { name = "large"; value = 32; };
                        };
                    };
                    class GVAR(groupMarkerColor) {
                        control = "Combo";
                        displayName = "Marker Color";
                        tooltip = "Group marker color";
                        property = QGVAR(markerColor);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setMarkerColor););
                        typeName = "STRING";
                        class values {
                            class 1 { name = "white"; value = "white"; default = 1; };
                            class 2 { name = "red"; value = "red"; };
                            class 3 { name = "blue"; value = "blue"; };
                            class 4 { name = "green"; value = "green"; };
                            class 5 { name = "orange"; value = "orange"; };
                            class 6 { name = "yellow"; value = "yellow"; };
                            class 7 { name = "pink"; value = "pink"; };
                            class 8 { name = "black"; value = "black"; };
                        };
                    };
                    class GVAR(groupMarkerTexture) {
                        control = QGVAR(markerIconSelect);
                        displayName = "Marker Icon";
                        tooltip = "Group Marker Icon";
                        property = QGVAR(markerTexture);
                        expression = QUOTE(SETVAR(_this,GVAR(markerTexture),_value););
                        typeName = "STRING";
                        defaultValue = "\A3\ui_f\data\map\markers\nato\b_unknown.paa";
                    };
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Unit Marker";
                collapsed = 1;
                condition = "objectBrain";
                class Attributes {
                    class GVAR(addUnitMarker) {
                        control = "Checkbox";
                        displayName = "Add Marker";
                        tooltip = "Add marker to unit";
                        property = QGVAR(addMarker);
                        expression = QUOTE(SETVAR(_this,GVAR(addMarker),_value););
                        typeName = "BOOL";
                        //condition = "objectBrain";
                        defaultValue = false;
                    };
                    class GVAR(unitMarkerText) {
                        control = "Edit";
                        displayName = "Marker Text";
                        tooltip = "Unit marker text";
                        property = QGVAR(markerText);
                        expression = QUOTE(SETVAR(_this,GVAR(markerText),_value););
                        typeName = "STRING";
                        //condition = "objectBrain";
                        defaultValue = "";
                    };
                    class GVAR(unitMarkerSize) {
                        control = "Combo";
                        displayName = "Marker Size";
                        tooltip = "Unit marker size";
                        property = QGVAR(markerSize);
                        expression = QUOTE(SETVAR(_this,GVAR(markerSize),_value););
                        typeName = "NUMBER";
                        //condition = "objectBrain";
                        class values {
                            class 1 { name = "small"; value = 16; };
                            class 2 { name = "medium"; value = 24; default = 1; };
                            class 3 { name = "large"; value = 32; };
                        };
                    };
                    class GVAR(unitMarkerColor) {
                        control = "Combo";
                        displayName = "Marker Color";
                        tooltip = "Unit marker color";
                        property = QGVAR(markerColor);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setMarkerColor););
                        typeName = "STRING";
                        //condition = "objectBrain";
                        class values {
                            class 1 { name = "white"; value = "white"; default = 1; };
                            class 2 { name = "red"; value = "red"; };
                            class 3 { name = "blue"; value = "blue"; };
                            class 4 { name = "green"; value = "green"; };
                            class 5 { name = "orange"; value = "orange"; };
                            class 6 { name = "yellow"; value = "yellow"; };
                            class 7 { name = "pink"; value = "pink"; };
                            class 8 { name = "black"; value = "black"; };
                        };
                    };
                    class GVAR(unitMarkerTexture) {
                        control = QGVAR(markerIconSelect);
                        displayName = "Marker Icon";
                        tooltip = "Unit Marker Icon";
                        property = QGVAR(markerTexture);
                        expression = QUOTE(SETVAR(_this,GVAR(markerTexture),_value););
                        typeName = "STRING";
                        //condition = "objectBrain";
                        defaultValue = "\A3\ui_f\data\map\markers\nato\b_unknown.paa";
                    };
                };
            };
        };
    };
};
