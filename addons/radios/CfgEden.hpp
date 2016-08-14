#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define EDIT_W	10

class ctrlEdit;
class ctrlStatic;
class ctrlToolbox;
class ctrlListNBox;
class ctrlXSliderH;
class ctrlMenuStrip;
class ctrlCheckboxBaseline;

class GVAR(setAttribute): ctrlToolbox {
    idc = RADIO_SET_IDC;
    x = (ATTRIBUTE_TITLE_W + SIZE_M) * GRID_W;
    y = 0;
    w = (ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 0.98 * SIZE_M * GRID_H;

    rows = 1;
    columns = 2;
    strings[] = {"Don't Set", "Set Channels"};
    values[] = {0, 1};
};
class GVAR(radioSelect): ctrlToolbox {
    idc = RADIO_CHOOSE_IDC;
    style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.5};
    x = SIZE_M * GRID_W;
    y = 2 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 2 * SIZE_M * GRID_H;

    rows = 1;
    columns = 3;
    strings[] = {
        "\idi\clients\acre\addons\sys_prc343\Data\static\prc343_icon.paa",
        "\idi\clients\acre\addons\sys_prc148\Data\static\prc148_icon.paa",
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
    y = 4 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 13 * SIZE_M * GRID_H;
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(channelSelect): ctrlListNBox {
    idc = RADIO_CHANNEL_IDC;
    x = SIZE_M * GRID_W;
    y = 4 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 13 * SIZE_M * GRID_H;
    columns[] = {0.05,0.15};
    disableOverflow = 1;
};
class GVAR(bableSelectBackground): ctrlStatic {
    x = SIZE_M * GRID_W;
    y = 3.95 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 5.10 * SIZE_M * GRID_H;
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(bableSelect): ctrlListNBox {
    idc = BABEL_LIST_IDC;
    style = LB_MULTI;
    x = SIZE_M * GRID_W;
    y = 4 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 5 * SIZE_M * GRID_H;
    columns[] = {0.05,0.15};
    disableOverflow = 1;
};
class GVAR(sharedMRCheckbox): ctrlCheckboxBaseline {
    idc = CFG_SHARED_MR;
    x = ATTRIBUTE_TITLE_W * GRID_W;
    w = SIZE_M * GRID_W;
    h = SIZE_M * GRID_H;
};
class GVAR(sharedLRCheckbox): GVAR(sharedMRCheckbox) {
    idc = CFG_SHARED_LR;
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
            onLoad = QUOTE(_this call FUNC(channelControlLoad));
            attributeSave = QUOTE(_this call FUNC(channelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(channelAttributeLoad));
            h = (18 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetTitle: Title {
                    text = "Set channels";
                };
                class SetControl: GVAR(setAttribute) {};
                class RadiosChooseTitle: Title {
                    text = "Radios";
                    y = 1 * SIZE_M * GRID_H;
                };
                class RadioChooseControl: GVAR(radioSelect) {};
                class ChannelBackground: GVAR(channelSelectBackground) {};
                class ChannelList: GVAR(channelSelect) {};
            };
        };
        class GVAR(babel): TitleWide {
            onLoad = QUOTE(_this call FUNC(babelControlLoad));
            attributeSave = QUOTE(_this call FUNC(babelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(babelAttributeLoad));
            h = (7 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetTitle: Title {
                    text = "Set languages";
                };
                class SetControl: GVAR(setAttribute) {
                    strings[] = {"Don't Set", "Set Languages"};
                };
                class BabelChooseTitle: Title {
                    text = "Babel";
                    y = 1 * SIZE_M * GRID_H;
                };
                class BabelListBackground: GVAR(bableSelectBackground) {
                    y = 2 * SIZE_M * GRID_H;
                };
                class BabelList: GVAR(bableSelect) {
                    y = 2 * SIZE_M * GRID_H;
                };
            };
        };
        class GVAR(acreGlobalConfig): TitleWide {
            onLoad = QUOTE(_this call FUNC(acreGlobalControlLoad));
            attributeSave = QUOTE(_this call FUNC(acreGlobalAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreGlobalAttributeLoad));
            h = (9 * SIZE_M + 1) * GRID_H;

            class Controls: Controls {
                class SetMasterTitle: Title {
                    text = "Master Enable";
                };
                class SetMasterControl: GVAR(setAttribute) {
                    idc = CFG_G_SET_IDC;
                    strings[] = {"Off", "On"};
                    tooltips[] = {"Turn Off", "Turn On"};
                };
                class SetRadioInterferenceTitle: Title {
                    text = "Radio to Radio Interference";
                    y = 1 * SIZE_M * GRID_H;
                };
                class SetRadioInterferenceControl: SetMasterControl {
                    idc = CFG_G_RI_IDC;
                    y = 1 * SIZE_M * GRID_H;
                };
                class SetOmnidirectionalRadiosTitle: Title {
                    text = "Omnidirectional Radio Antenna";
                    y = 2 * SIZE_M * GRID_H;
                };
                class SetOmnidirectionalRadiosControl: SetMasterControl {
                    idc = CFG_G_OMNI_IDC;
                    y = 2 * SIZE_M * GRID_H;
                };
                class SetTerrainInterferenceTitle: Title {
                    text = "Terrain Interference";
                    y = 3 * SIZE_M * GRID_H;
                };
                class SetTerrainInterferenceSlider: ctrlXSliderH {
                    idc = CFG_G_TI_SLIDER_IDC;
                    y = 3 * SIZE_M * GRID_H;
                    x = (ATTRIBUTE_TITLE_W + SIZE_M) * GRID_W;
                    w = (ATTRIBUTE_CONTENT_W - SIZE_M - EDIT_W - 0.75) * GRID_W;
                    h = 0.95 * SIZE_M * GRID_H;

                    sliderRange[] = {0,1};
                    sliderPosition = 0;
                    lineSize = 0.1;

                    color[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
                    colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
                    colorDisabled[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.5};
                };
                class SetTerrainInterferenceEdit: ctrlEdit {
                    idc = CFG_G_TI_EDIT_IDC;
                    y = 3 * SIZE_M * GRID_H;
                    x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
                    w = EDIT_W * GRID_W;
                    h = 0.95 * SIZE_M * GRID_H;
                };
                class SetCommonChannelNameTitle: Title {
                    text = "Shared Channel Name";
                    y = 4 * SIZE_M * GRID_H;
                };
                class SetCommonChannelNameControl: ctrlEdit {
                    idc = CFG_G_CC_NAME_IDC;
                    x = (ATTRIBUTE_TITLE_W + SIZE_M) * GRID_W;
                    y = 4 * SIZE_M * GRID_H;
                    w = (ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
                    h = 0.98 * SIZE_M * GRID_H;
                };
                class SetCommonChannelNumberTitle: Title {
                    text = "Shared Channel Number";
                    y = 5.5 * SIZE_M * GRID_H;
                };
                class SetCommonChannelNumberControl: SetMasterControl {
                    idc = CFG_G_CC_NUMBER_IDC;
                    y = 5 * SIZE_M * GRID_H;
                    h = 1.96 * SIZE_M * GRID_H;

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
                class SetSharedMRTitle: Title {
                    text = "Global Shared 148 Channel";
                    y = 7 * SIZE_M * GRID_H;
                };
                class SetSharedMRControl: SetMasterControl {
                    idc = CFG_G_CC_MR_IDC;
                    y = 7 * SIZE_M * GRID_H;
                };
                class SetSharedLRTitle: Title {
                    text = "Global Shared 117 Channel";
                    y = 8 * SIZE_M * GRID_H;
                };
                class SetSharedLRControl: SetMasterControl {
                    idc = CFG_G_CC_LR_IDC;
                    y = 8 * SIZE_M * GRID_H;
                };
            };
        };
        class GVAR(acreSideConfig): TitleWide {
            onLoad = QUOTE(_this call FUNC(acreSideControlLoad));
            attributeSave = QUOTE(_this call FUNC(acreSideAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreSideAttributeLoad));
            h = (26 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetSide: Title {
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
                class SharedMRTitle: Title {
                    text = "Shared 148 Channel";
                    y = 1 * SIZE_M * GRID_H;
                };
                class SharedMRCheckbox: GVAR(setAttribute) {
                    idc = CFG_S_SHARED_MR;
                    y = 1 * SIZE_M * GRID_H;
                    strings[] = {"Off", "On"};
                    tooltips[] = {"Turn Off", "Turn On"};
                };
                class SharedLRTitle: Title {
                    text = "Shared 117 Channel";
                    y = 2 * SIZE_M * GRID_H;
                };
                class SharedLRCheckbox: SharedMRCheckbox {
                    idc = CFG_S_SHARED_LR;
                    y = 2 * SIZE_M * GRID_H;
                };
                class BabelChooseTitle: Title {
                    text = "Babel";
                    y = 3 * SIZE_M * GRID_H;
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
                    idc = CFG_S_CHANNEL_IDC;
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
                            expression = QUOTE([_value] call FUNC(setAcreGlobalSetting));
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
                            expression = QUOTE([ARR_2(_this,_value)] call FUNC(setAcreSideSetting));
                        };
                    };
                };
            };
        };
    };
};
