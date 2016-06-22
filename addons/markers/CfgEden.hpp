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
        class GVAR(groupMarkerEdit): Toolbox {
            //attributeLoad = "(_this controlsGroupCtrl 100) lbsetcursel (['wedge','vee','line','column','file','stag_column','ech_left','ech_right','diamond'] find _value);";
            //attributeSave = "['wedge','vee','line','column','file','stag_column','ech_left','ech_right','diamond'] select (missionnamespace getvariable ['FormationGroup_value',0]);";
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
                    h = "2 * 5 * (pixelH * 1.25 * 4)";
                    colorBackground[] = {0,0,0,0};

                    rows = 2;
                    columns = 6;
                    strings[] = {
                        "\A3\ui_f\data\map\markers\nato\b_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_hq.paa",
                        "\A3\ui_f\data\map\markers\nato\b_support.paa",
                        "\A3\ui_f\data\map\markers\nato\b_motor_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_recon.paa",
                        "\A3\ui_f\data\map\markers\nato\b_mortar.paa",
                        "\A3\ui_f\data\map\markers\nato\b_maint.paa",
                        "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_armor.paa",
                        "\A3\ui_f\data\map\markers\nato\b_air.paa",
                        "\A3\ui_f\data\map\markers\nato\b_plane.paa",
                        "\A3\ui_f\data\map\markers\nato\b_art.paa"
                    };
                    values[] = {
                        "\A3\ui_f\data\map\markers\nato\b_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_hq.paa",
                        "\A3\ui_f\data\map\markers\nato\b_support.paa",
                        "\A3\ui_f\data\map\markers\nato\b_motor_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_recon.paa",
                        "\A3\ui_f\data\map\markers\nato\b_mortar.paa",
                        "\A3\ui_f\data\map\markers\nato\b_maint.paa",
                        "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa",
                        "\A3\ui_f\data\map\markers\nato\b_armor.paa",
                        "\A3\ui_f\data\map\markers\nato\b_air.paa",
                        "\A3\ui_f\data\map\markers\nato\b_plane.paa",
                        "\A3\ui_f\data\map\markers\nato\b_art.paa"
                    };
                    tooltips[] = {
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
                        "Artillery"
                    };
                    onToolboxSelChanged = QUOTE(missionnamespace setVariable [ARR_2(QUOTE(QGVAR(selectedGroupMarkerIcon)),_this select 1)];);
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
                    class GVAR(marker) {
                        displayName = "Group Marker Icon";
                        defaultValue = "''";
                        tooltip = "Group Marker Icon";
                        data = QGVAR(groupMarkerEditIcon);
                        control = QGVAR(groupMarkerEdit);
                        typeName = "STRING";
                        expression = "";
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
                class Attributes {
                    class GVAR(marker) {
                        displayName = "Unit Marker";
                        tooltip = "";
                        property = QGVAR(marker);
                        control = QGVAR(groupMarkerEdit);

                        typeName = "STRING";
                        expression = "";
                    };
                };
            };
        };
    };
};
