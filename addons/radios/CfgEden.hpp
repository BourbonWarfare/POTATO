#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define EDIT_W 10
#define SIZE_XXS 1

class ctrlEdit;
class ctrlStatic;
class ctrlToolbox;
class ctrlListNBox;
class ctrlMenuStrip;

class GVAR(setAttribute): ctrlToolbox {
    idc = RADIO_SET_IDC;
    x = QUOTE((ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W);
    y = QUOTE(0.02 * SIZE_M * GRID_H);
    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
    h = QUOTE(0.96 * SIZE_M * GRID_H);

    rows = 1;
    columns = 2;
    strings[] = {"Don't Set", "Set Channels"};
    values[] = {0, 1};
};
class GVAR(radioSelect): ctrlToolbox {
    idc = RADIO_CHOOSE_IDC;
    style = QUOTE(ST_PICTURE + ST_KEEP_ASPECT_RATIO);
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.5};
    x = QUOTE(SIZE_M * GRID_W);
    y = QUOTE(2 * SIZE_M * GRID_H);
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
    h = QUOTE(2 * SIZE_M * GRID_H);

    rows = 1;
    columns = 3;
    strings[] = {
        QPATHTOF(data\prc343_icon.paa),
        QPATHTOF(data\prc148_icon.paa),
        QPATHTOF(data\PRC117F_ico.paa)
    };
    tooltips[] = {
        "343 (Short Range)",
        "148 (Medium Range)",
        "117 (Long Range)"
    };
};
class GVAR(channelSelectBackground): ctrlStatic {
    x = QUOTE(SIZE_M * GRID_W);
    y = QUOTE(4 * SIZE_M * GRID_H);
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
    h = QUOTE(13 * SIZE_M * GRID_H);
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(channelSelect): ctrlListNBox {
    idc = RADIO_CHANNEL_IDC;
    x = QUOTE(SIZE_M * GRID_W);
    y = QUOTE(4 * SIZE_M * GRID_H);
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
    h = QUOTE(13 * SIZE_M * GRID_H);
    columns[] = {0.05,0.15};
    disableOverflow = 1;
};
class GVAR(bableSelectBackground): ctrlStatic {
    x = QUOTE(SIZE_M * GRID_W);
    y = QUOTE(3.95 * SIZE_M * GRID_H);
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
    h = QUOTE(5.10 * SIZE_M * GRID_H);
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(bableSelect): ctrlListNBox {
    idc = BABEL_LIST_IDC;
    style = LB_MULTI;
    x = QUOTE(SIZE_M * GRID_W);
    y = QUOTE(4 * SIZE_M * GRID_H);
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
    h = QUOTE(5 * SIZE_M * GRID_H);
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
                    text = "ACRE Configuration";
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
            onLoad = QUOTE(call FUNC(channelControlLoad));
            attributeSave = QUOTE(call FUNC(channelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(channelAttributeLoad));
            h = QUOTE((17 * SIZE_M + 1) * GRID_H);
            class Controls: Controls {
                class SetTitle: Title {
                    style = 1;
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Set channels";
                };
                class SetControl: GVAR(setAttribute) {};
                class RadiosChooseTitle: Title {
                    y = QUOTE(1 * SIZE_M * GRID_H);
                    text = "Radios";
                };
                class RadioChooseControl: GVAR(radioSelect) {};
                class ChannelBackground: GVAR(channelSelectBackground) {};
                class ChannelList: GVAR(channelSelect) {};
            };
        };
        class GVAR(babel): TitleWide {
            onLoad = QUOTE(call FUNC(babelControlLoad));
            attributeSave = QUOTE(call FUNC(babelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(babelAttributeLoad));
            h = QUOTE((7 * SIZE_M + 1) * GRID_H);
            class Controls: Controls {
                class SetTitle: Title {
                    style = 1;
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Set languages";
                };
                class SetControl: GVAR(setAttribute) {
                    strings[] = {"Don't Set", "Set Languages"};
                };
                class BabelChooseTitle: Title {
                    y = QUOTE(1 * SIZE_M * GRID_H);
                    text = "Babel";
                };
                class BabelListBackground: GVAR(bableSelectBackground) {
                    y = QUOTE(2 * SIZE_M * GRID_H);
                };
                class BabelList: GVAR(bableSelect) {
                    y = QUOTE(2 * SIZE_M * GRID_H);
                };
            };
        };
        class GVAR(acreGlobalConfig): TitleWide {
            onLoad = QUOTE(call FUNC(acreGlobalControlLoad));
            attributeSave = QUOTE(call FUNC(acreGlobalAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreGlobalAttributeLoad));
            h = QUOTE((6 * SIZE_M + 1) * GRID_H);

            class Controls: Controls {
                class SetMasterTitle: Title {
                    style = 1;
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Master Enable";
                };
                class SetMasterControl: GVAR(setAttribute) {
                    idc = CFG_G_SET_IDC;
                    strings[] = {"Off", "On"};
                    tooltips[] = {"Turn Off", "Turn On"};
                };
                class SetCommonChannelNameTitle: SetMasterTitle {
                    y = QUOTE(1 * SIZE_M * GRID_H);
                    text = "Shared Channel Name";
                };
                class SetCommonChannelNameControl: ctrlEdit {
                    idc = CFG_G_CC_NAME_IDC;
                    x = QUOTE((ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W);
                    y = QUOTE(1.02 * SIZE_M * GRID_H);
                    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
                    h = QUOTE(0.96 * SIZE_M * GRID_H);
                };
                class SetCommonChannelNumberTitle: SetMasterTitle {
                    y = QUOTE(2.5 * SIZE_M * GRID_H);
                    text = "Shared Channel Number";
                };
                class SetCommonChannelNumberControl: SetMasterControl {
                    idc = CFG_G_CC_NUMBER_IDC;
                    y = QUOTE(2.02 * SIZE_M * GRID_H);
                    h = QUOTE(1.96 * SIZE_M * GRID_H);

                    rows = 2;
                    columns = 10;
                    strings[] = {
                        "1", "2", "3", "4", "5",
                        "6", "7", "8", "9", "10",
                        "11", "12", "13", "14", "15",
                        "16", "17", "18", "19", "20"
                    };
                    values[] = {
                        1, 2, 3, 4, 5,
                        6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15,
                        16, 17, 18, 19, 20
                    };
                    tooltips[] = {
                        "Channel 1", "Channel 2", "Channel 3", "Channel 4", "Channel 5",
                        "Channel 6", "Channel 7", "Channel 8", "Channel 9", "Channel 10",
                        "Channel 11", "Channel 12", "Channel 13", "Channel 14", "Channel 15",
                        "Channel 16", "Channel 17", "Channel 18", "Channel 19", "Channel 20"
                    };
                };
                class SetSharedMRTitle: SetMasterTitle {
                    y = QUOTE(4 * SIZE_M * GRID_H);
                    text = "Global Shared 148 Channel";
                };
                class SetSharedMRControl: SetMasterControl {
                    idc = CFG_G_CC_MR_IDC;
                    y = QUOTE(4.02 * SIZE_M * GRID_H);
                };
                class SetSharedLRTitle: SetMasterTitle {
                    y = QUOTE(5 * SIZE_M * GRID_H);
                    text = "Global Shared 117 Channel";
                };
                class SetSharedLRControl: SetMasterControl {
                    idc = CFG_G_CC_LR_IDC;
                    y = QUOTE(5.02 * SIZE_M * GRID_H);
                };
            };
        };
        class GVAR(acreSideConfig): TitleWide {
            onLoad = QUOTE(call FUNC(acreSideControlLoad));
            attributeSave = QUOTE(call FUNC(acreSideAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreSideAttributeLoad));
            h = QUOTE((26 * SIZE_M + 1) * GRID_H);
            class Controls: Controls {
                class SetSide: Title {
                    style = 1;
                    w = QUOTE((ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W);
                    text = "Choose Side";
                };
                class SetControl: GVAR(setAttribute) {
                    idc = CFG_S_SIDE_IDC;

                    columns = 4;
                    strings[] = {"BluFor", "OpFor", "Indy", "Civ"};
                    values[] = {0, 1, 2, 3};
                    tooltips[] = {
                        "BluFor (West)",
                        "OpFor (East)",
                        "Independent (Resistance)",
                        "Civilian (None of the others)"
                    };
                };
                class SharedMRTitle: SetSide {
                    y = QUOTE(1 * SIZE_M * GRID_H);
                    text = "Shared 148 Channel";
                };
                class SharedMRCheckbox: GVAR(setAttribute) {
                    idc = CFG_S_SHARED_MR;
                    y = QUOTE(1.02 * SIZE_M * GRID_H);
                    strings[] = {"Off", "On"};
                    tooltips[] = {"Turn Off", "Turn On"};
                };
                class SharedLRTitle: SetSide {
                    y = QUOTE(2 * SIZE_M * GRID_H);
                    text = "Shared 117 Channel";
                };
                class SharedLRCheckbox: SharedMRCheckbox {
                    idc = CFG_S_SHARED_LR;
                    y = QUOTE(2.02 * SIZE_M * GRID_H);
                };
                class BabelChooseTitle: Title {
                    y = QUOTE(3 * SIZE_M * GRID_H);
                    text = "Babel";
                };
                class BabelListBackground: GVAR(bableSelectBackground) {};
                class BabelList: GVAR(bableSelect) {};
                class RadiosChooseTitle: Title {
                    y = QUOTE(9 * SIZE_M * GRID_H);
                    text = "Radios";
                };
                class RadioChooseControl: GVAR(radioSelect) {
                    y = QUOTE(10 * SIZE_M * GRID_H);
                };
                class SetChannelName: ctrlEdit {
                    idc = CFG_S_CHANNEL_IDC;
                    x = QUOTE(SIZE_M * GRID_W);
                    y = QUOTE(12 * SIZE_M * GRID_H);
                    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W);
                    h = QUOTE(1 * SIZE_M * GRID_H);
                };
                class ChannelBackground: GVAR(channelSelectBackground) {
                    y = QUOTE(13 * SIZE_M * GRID_H);
                };
                class ChannelList: GVAR(channelSelect) {
                    y = QUOTE(13 * SIZE_M * GRID_H);
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Group ACRE Setup";
                collapsed = 1;
                class Attributes {
                    class GVAR(babel) {
                        property = QGVAR(babel);
                        control = QGVAR(babel);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setLanguages));
                        defaultValue = "(true)";
                    };
                    class GVAR(radios) {
                        property = QGVAR(radio);
                        control = QGVAR(radioChannels);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setChannels));
                        defaultValue = "(true)";
                    };
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Unit ACRE Setup";
                collapsed = 1;
                class Attributes {
                    class GVAR(babel) {
                        condition = "objectBrain";
                        property = QGVAR(babel);
                        control = QGVAR(babel);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setLanguages));
                        defaultValue = "(true)";
                    };
                    class GVAR(radios) {
                        condition = "objectBrain";
                        property = QGVAR(radio);
                        control = QGVAR(radioChannels);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setChannels));
                        defaultValue = "(true)";
                    };
                };
            };
        };
    };
    class Mission {
        class GVAR(configureAcre) {
            displayName = "ACRE Configuration";
            display = "Display3DENEditAttributes";
            class AttributeCategories {
                class GVAR(acreGlobalConfig) {
                    displayName = "ACRE Global Configuration";
                    collapsed = 0;
                    class Attributes {
                        class acreGlobalConfig {
                            control = QGVAR(acreGlobalConfig);
                            property = QGVAR(acreGlobalConfig);
                            expression = QUOTE([ARR_2(nil,_value)] call FUNC(acreGlobalAttributeLoad));
                        };
                    };
                };
                class GVAR(acreSideConfig) {
                    displayName = "ACRE Side Specific Configuration";
                    collapsed = 0;
                    class Attributes {
                        class acreSideConfig {
                            control = QGVAR(acreSideConfig);
                            property = QGVAR(acreSideConfig);
                            expression = QUOTE([ARR_2(nil,_value)] call FUNC(acreSideAttributeLoad));
                        };
                    };
                };
            };
        };
    };
};
