#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"

class ctrlEdit;
class ctrlStatic;
class ctrlToolbox;
class ctrlListNBox;
class ctrlMenuStrip;

class GVAR(setAttribute): ctrlToolbox {
    idc = RADIO_SET_IDC;
    x = SIZE_M * GRID_W;
    y = 1 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 1 * SIZE_M * GRID_H;

    rows = 1;
    columns = 2;
    strings[] = {"Don't Set", "Set Channels"};
};
class GVAR(radioSelect): ctrlToolbox {
    idc = RADIO_CHOOSE_IDC;
    style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.5};
    x = SIZE_M * GRID_W;
    y = 3 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 2 * SIZE_M * GRID_H;

    rows = 1;
    columns = 3;
    strings[] = {
        "\idi\clients\acre\addons\sys_prc343\Data\343_icon.paa",
        "\idi\clients\acre\addons\sys_prc148\Data\148_icon.paa",
        "\idi\clients\acre\addons\sys_prc117f\Data\PRC117F_ico.paa"
    };
    tooltips[] = {
        "343 (Short Range)",
        "148 (Medium Range)",
        "117 (Long Range)"
    };
};
class GVAR(channelSelectBackground): ctrlStatic {
    x = SIZE_M * GRID_W;
    y = 5 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 13 * SIZE_M * GRID_H;
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(channelSelect): ctrlListNBox {
    idc = RADIO_CHANNEL_IDC;
    x = SIZE_M * GRID_W;
    y = 5 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 13 * SIZE_M * GRID_H;
    columns[] = {0.05,0.15};
    disableOverflow = 1;
};
class GVAR(bableSelectBackground): ctrlStatic {
    x = SIZE_M * GRID_W;
    y = 3 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 5 * SIZE_M * GRID_H;
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(bableSelect): ctrlListNBox {
    idc = BABEL_LIST_IDC;
    style = LB_MULTI;
    x = SIZE_M * GRID_W;
    y = 3 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 5 * SIZE_M * GRID_H;
    columns[] = {0.05,0.15};
    disableOverflow = 1;
};

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(radios)};
                };
                class GVAR(radios) {
                    text = "Radio Setup";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(configureAcre)););
                };
            };
        };
    };
};

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title;
        class TitleWide: Default {
            class Controls;
        };
        class GVAR(radioChannels): TitleWide {
            onLoad = QUOTE(_this call FUNC(channelControlLoad));
            onUnload = "";
            attributeSave = QUOTE(_this call FUNC(channelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(channelAttributeLoad));
            //attributeLoad = "['attributeLoad',_this] call (uinamespace getvariable 'AmmoBox_script');";
            //attributeSave = "['attributeSave',_this] call (uinamespace getvariable 'AmmoBox_script');";
            h = (18 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetTitle: Title {
                    text = "Set channels";
                };
                class SetControl: GVAR(setAttribute) {};
                class RadiosChooseTitle: Title {
                    text = "Radios";
                    y = 2 * SIZE_M * GRID_H;
                };
                class RadioChooseControl: GVAR(radioSelect) {};
                class ChannelBackground: GVAR(channelSelectBackground) {};
                class ChannelList: GVAR(channelSelect) {};
            };
        };
        class GVAR(configureAcre): TitleWide {
            onLoad = QUOTE(_this call FUNC(acreControlLoad));
            onUnload = "";
            attributeSave = QUOTE(_this call FUNC(acreAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreAttributeLoad));
            //attributeLoad = "['attributeLoad',_this] call (uinamespace getvariable 'AmmoBox_script');";
            //attributeSave = "['attributeSave',_this] call (uinamespace getvariable 'AmmoBox_script');";
            h = (26 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetSide: Title {
                    text = "Choose Side";
                };
                class SetControl: ctrlToolbox {
                    idc = CFG_SIDE_IDC;
                    x = SIZE_M * GRID_W;
                    y = 1 * SIZE_M * GRID_H;
                    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
                    h = 1 * SIZE_M * GRID_H;

                    rows = 1;
                    columns = 4;
                    strings[] = {"BluFor", "OpFor", "Indy", "Civ"};
                    tooltips[] = {
                        "BluFor (West)",
                        "OpFor (East)",
                        "Independent (Resistance)",
                        "Civilian (None of the others)"
                    };
                };
                class BabelChooseTitle: Title {
                    text = "Babel";
                    y = 2 * SIZE_M * GRID_H;
                };
                class BabelListBackground: GVAR(bableSelectBackground) {};
                class BabelList: GVAR(bableSelect) {};
                class RadiosChooseTitle: Title {
                    text = "Radios";
                    y = 9 * SIZE_M * GRID_H;
                };
                class RadioChooseControl: GVAR(radioSelect) {
                    y = 10 * SIZE_M * GRID_H;
                };
                class SetChannelName: ctrlEdit {
                    idc = RADIO_CHANNEL_IDC;
                    x = SIZE_M * GRID_W;
                    y = 12 * SIZE_M * GRID_H;
                    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
                    h = 1 * SIZE_M * GRID_H;
                };
                class ChannelBackground: GVAR(channelSelectBackground) {
                    y = 13 * SIZE_M * GRID_H;
                };
                class ChannelList: GVAR(channelSelect) {
                    y = 13 * SIZE_M * GRID_H;
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Group Radio Setup";
                collapsed = 1;
                class Attributes {
                    class GVAR(radios) {
                        displayName = "Group Radio Setup";
                        property = QGVAR(radio);
                        control = QGVAR(radioChannels);
                    };
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Unit Radio Setup";
                collapsed = 1;
                class Attributes {
                    class GVAR(radios) {
                        condition = "objectBrain";
                        displayName = "Unit Radio Setup";
                        property = QGVAR(radio);
                        control = QGVAR(radioChannels);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setChannels));
                    };
                };
            };
        };
    };
    class Mission {
        class GVAR(configureAcre) {// Custom section class, everything inside will be opened in one window
            displayName = "Radio Setup"; // Text visible in the window title as "Edit <displayName>"
            display = "Display3DENEditAttributes"; // Optional - display for attributes window. Must have the same structure and IDCs as the default Display3DENEditAttributes
            class AttributeCategories {
                class ACRE {
                    displayName = "Babel and Radio Setup"; // Category name visible in Edit Attributes window
                    collapsed = 0; // When 1, the category is collapsed by default
                    class Attributes {
                        class GVAR(acreConfig) {
                            displayName = "West Babel";
                            property = QGVAR(westBabel);
                            control = QGVAR(configureAcre);
                        };
                    };
                };
            };
        };
    };
};
