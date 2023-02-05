#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define SIZE_XXS 1

class ctrlToolbox;

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls;
        };
        class TitleWide: Default {
            class Controls;
        };
        class GVAR(sideMarkerIcon): TitleWide {
            attributeSave = QUOTE([ARR_3(_this,ICON_IDC,[ICON_VALUES])] call FUNC(toolboxAttributeSave));
            attributeLoad = QUOTE([ARR_4(_this,ICON_IDC,_value,[ICON_VALUES])] call FUNC(toolboxAttributeLoad));

            h = QUOTE((3 * SIZE_M + 1) * GRID_H);
            class Controls: Controls {
                class IconTitle: Title {
                    style = 1;
                    y = QUOTE(1 * SIZE_M * GRID_H);
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Marker Icon";
                };
                class GVAR(iconSelect): ctrlToolbox {
                    idc = ICON_IDC;
                    style = QUOTE(ST_PICTURE + ST_KEEP_ASPECT_RATIO);
                    colorBackground[] = {0,0,0,0};
                    x = QUOTE((ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W);
                    y = QUOTE(0 * SIZE_M * GRID_H);
                    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
                    h = QUOTE(3 * SIZE_M * GRID_H);

                    rows = 3;
                    columns = 6;

                    strings[] = {
                        "\A3\ui_f\data\map\markers\military\dot_CA.paa",
                        "\A3\ui_f\data\map\markers\military\box_CA.paa",
                        "\A3\ui_f\data\map\markers\military\triangle_CA.paa",
                        "\A3\ui_f\data\map\markers\military\circle_CA.paa",
                        "\A3\ui_f\data\map\markers\military\unknown_CA.paa",
                        "\A3\ui_f\data\map\markers\military\warning_CA.paa",
                        "\A3\ui_f\data\map\markers\military\join_CA.paa",
                        "\A3\ui_f\data\map\markers\military\pickup_CA.paa",
                        "\A3\ui_f\data\map\markers\military\start_CA.paa",
                        "\A3\ui_f\data\map\markers\military\end_CA.paa",
                        "\A3\ui_f\data\map\markers\military\destroy_CA.paa",
                        "\A3\ui_f\data\map\markers\military\ambush_CA.paa",
                        "\A3\ui_f\data\map\markers\military\arrow_CA.paa",
                        "\A3\ui_f\data\map\markers\military\arrow2_CA.paa",
                        "\A3\ui_f\data\map\markers\military\flag_CA.paa",
                        "\A3\ui_f\data\map\markers\military\marker_CA.paa",
                        "\A3\ui_f\data\map\markers\military\objective_CA.paa"
                    };
                    values[] = {ICON_VALUES_STR};
                    tooltips[] = {
                        "Dot",
                        "Box",
                        "Triangle",
                        "Circle",
                        "Unknown",
                        "Warning",
                        "Join",
                        "Pickup",
                        "Start",
                        "End",
                        "Destroy",
                        "Ambush",
                        "Arrow",
                        "Arrow2",
                        "Flag",
                        "Marker",
                        "Objective"
                    };
                };
            };
        };
        class GVAR(sideMarkerColor): TitleWide {
            attributeSave = QUOTE([ARR_3(_this,COLOR_IDC,[COLOR_VALUES])] call FUNC(toolboxAttributeSave));
            attributeLoad = QUOTE([ARR_4(_this,COLOR_IDC,_value,[COLOR_VALUES])] call FUNC(toolboxAttributeLoad));

            h = QUOTE((2 * SIZE_M + 1) * GRID_H);
            class Controls: Controls {
                class IconTitle: Title {
                    style = 1;
                    y = QUOTE(0.5 * SIZE_M * GRID_H);
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Marker Color";
                };
                class GVAR(colorSelect): ctrlToolbox {
                    idc = COLOR_IDC;
                    colorBackground[] = {0,0,0,0};
                    x = QUOTE((ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W);
                    y = QUOTE(0 * SIZE_M * GRID_H);
                    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
                    h = QUOTE(2 * SIZE_M * GRID_H);

                    rows = 2;
                    columns = 5;

                    strings[] = {
                        "Black",
                        "Red",
                        "Brown",
                        "Orange",
                        "Yellow",
                        "Green",
                        "Blue",
                        "Pink",
                        "Purple",
                        "White"
                    };
                    values[] = {COLOR_VALUES_STR};
                    tooltips[] = {
                        "Black",
                        "Red",
                        "Brown",
                        "Orange",
                        "Yellow",
                        "Green",
                        "Blue",
                        "Pink",
                        "Purple",
                        "White"
                    };
                };
            };
        };

        class Slider: Title {
            class Controls: Controls {
                class Edit;
                class Title;
                class Value;
            };
        };

        class GVAR(sideMarkerDir): Slider {
            onLoad = "_ctrlGroup = _this select 0; [_ctrlGroup controlsgroupctrl 100,_ctrlGroup controlsgroupctrl 101,'°'] call bis_fnc_initSliderValue;";
            attributeLoad = "_ctrlGroup = _this; [_ctrlGroup controlsgroupctrl 100,_ctrlGroup controlsgroupctrl 101,'°',_value] call bis_fnc_initSliderValue;";
            class Controls: Controls {
                class Edit: Edit {};
                class Title: Title {};
                class Value: Value {
                    sliderRange[] = {0, 360};
                };
            };
        };
    };
};
