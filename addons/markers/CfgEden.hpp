#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define SIZE_XXS 1

class ctrlEdit;
class ctrlToolbox;

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title;
        class TitleWide: Default {
            class Controls;
        };
        class GVAR(configureMarker): TitleWide {
            onLoad = QUOTE(_this call FUNC(markerControlLoad));
            attributeSave = QUOTE(_this call FUNC(markerAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(markerAttributeLoad));
            h = (12 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetTitle: Title {
                    style = 1;
                    w = (ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W;
                    text = "Set Marker";
                };
                class GVAR(set): ctrlToolbox {
                    idc = MARKER_SET_IDC;
                    x = (ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W;
                    y = 0.02 * SIZE_M * GRID_H;
                    w = ATTRIBUTE_CONTENT_W * GRID_W;
                    h = 0.96 * SIZE_M * GRID_H;

                    rows = 1;
                    columns = 2;
                    strings[] = {"Don't Set", "Set Marker"};
                    values[] = {0, 1};
                };
                class NameTitle: SetTitle {
                    text = "Marker Text";
                    y = 1 * SIZE_M * GRID_H;
                };
                class GVAR(name): ctrlEdit {
                    idc = MARKER_NAME_IDC;
                    x = (ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W;
                    y = 1.02 * SIZE_M * GRID_H;
                    w = ATTRIBUTE_CONTENT_W * GRID_W;
                    h = 0.96 * SIZE_M * GRID_H;
                };
                class SizeTitle: SetTitle {
                    text = "Marker Size";
                    y = 2 * SIZE_M * GRID_H;
                };
                class GVAR(size): GVAR(set) {
                    idc = MARKER_SIZE_IDC;
                    y = 2.02 * SIZE_M * GRID_H;
                    columns = 3;
                    strings[] = {UNIT_MARKER_SIZES_STRINGS};
                    values[] = {UNIT_MARKER_SIZES};
                };
                class ColorTitle: SetTitle {
                    text = "Marker Color";
                    y = 3.5 * SIZE_M * GRID_H;
                };
                class GVAR(color): GVAR(set) {
                    idc = MARKER_COLOR_IDC;
                    y = 3.02 * SIZE_M * GRID_H;
                    h = 1.96 * SIZE_M * GRID_H;

                    rows = 2;
                    columns = 4;
                    strings[] = {UNIT_MARKER_COLORS_STRINGS};
                    values[] = {UNIT_MARKER_COLORS};
                };
                class IconTitle: SetTitle {
                    text = "Marker Icon";
                    y = 5.5 * SIZE_M * GRID_H;
                };
                class GVAR(iconSelect): GVAR(color) {
                    idc = MARKER_ICON_IDC;
                    style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
                    colorBackground[] = {0,0,0,0};
                    y = 5.02 * SIZE_M * GRID_H;

                    columns = 7;
                    strings[] = {UNIT_MARKERS_STRINGS};
                    values[] = {UNIT_MARKERS};
                    tooltips[] = {
                        "Unknown",
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
                        control = QGVAR(configureMarker);
                        property = QGVAR(addMarker);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setMarker););
                        defaultValue = "(true)";
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
                    class GVAR(addUnitMarker) {
                        control = QGVAR(configureMarker);
                        property = QGVAR(addMarker);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setMarker););
                        condition = "objectBrain";
                        defaultValue = "(true)";
                    };
                };
            };
        };
    };
};
