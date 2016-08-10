#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"

class ctrlEdit;
class ctrlStatic;
class ctrlToolbox;
class ctrlListNBox;
class ctrlMenuStrip;
class ctrlCheckboxBaseline;

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
    y = 5 * SIZE_M * GRID_H;
    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
    h = 5 * SIZE_M * GRID_H;
    colorBackground[] = {1,1,1,0.1};
};
class GVAR(bableSelect): ctrlListNBox {
    idc = BABEL_LIST_IDC;
    style = LB_MULTI;
    x = SIZE_M * GRID_W;
    y = 5 * SIZE_M * GRID_H;
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
            onUnload = "";
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
                    y = 2 * SIZE_M * GRID_H;
                };
                class RadioChooseControl: GVAR(radioSelect) {};
                class ChannelBackground: GVAR(channelSelectBackground) {};
                class ChannelList: GVAR(channelSelect) {};
            };
        };
        class GVAR(babel): TitleWide {
            onLoad = QUOTE(_this call FUNC(babelControlLoad));
            onUnload = "";
            attributeSave = QUOTE(_this call FUNC(babelAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(babelAttributeLoad));
            h = (9 * SIZE_M + 1) * GRID_H;
            class Controls: Controls {
                class SetTitle: Title {
                    text = "Set languages";
                };
                class SetControl: GVAR(setAttribute) {
                    strings[] = {"Don't Set", "Set Languages"};
                };
                class BabelChooseTitle: Title {
                    text = "Babel";
                    y = 3 * SIZE_M * GRID_H;
                };
                class BabelListBackground: GVAR(bableSelectBackground) {
                    y = 4 * SIZE_M * GRID_H;
                };
                class BabelList: GVAR(bableSelect) {
                    y = 4 * SIZE_M * GRID_H;
                };
            };
        };
        class GVAR(configureAcre): TitleWide {
            onLoad = QUOTE(_this call FUNC(acreControlLoad));
            onUnload = "";
            attributeSave = QUOTE(_this call FUNC(acreAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(acreAttributeLoad));
            h = (28 * SIZE_M + 1) * GRID_H;
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
                class SharedMRTitle: Title {
                    text = "Shared 148 Channel";
                    y = 2 * SIZE_M * GRID_H;
                };
                class SharedMRCheckbox: GVAR(sharedMRCheckbox) {
                    y = 2 * SIZE_M * GRID_H;
                    onCheckedChanged = QUOTE(_this pushBack false; _this call FUNC(acreControlSharedChange););
                };
                class SharedLRTitle: Title {
                    text = "Shared 117 Channel";
                    y = 3 * SIZE_M * GRID_H;
                };
                class SharedLRCheckbox: GVAR(sharedLRCheckbox) {
                    y = 3 * SIZE_M * GRID_H;
                    onCheckedChanged = QUOTE(_this pushBack true; _this call FUNC(acreControlSharedChange););
                };
                class BabelChooseTitle: Title {
                    text = "Babel";
                    y = 4 * SIZE_M * GRID_H;
                };
                class BabelListBackground: GVAR(bableSelectBackground) {};
                class BabelList: GVAR(bableSelect) {};
                class RadiosChooseTitle: Title {
                    text = "Radios";
                    y = 11 * SIZE_M * GRID_H;
                };
                class RadioChooseControl: GVAR(radioSelect) {
                    y = 12 * SIZE_M * GRID_H;
                };
                class SetChannelName: ctrlEdit {
                    idc = CFG_CHANNEL_IDC;
                    x = SIZE_M * GRID_W;
                    y = 14 * SIZE_M * GRID_H;
                    w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - SIZE_M) * GRID_W;
                    h = 1 * SIZE_M * GRID_H;
                };
                class ChannelBackground: GVAR(channelSelectBackground) {
                    y = 15 * SIZE_M * GRID_H;
                };
                class ChannelList: GVAR(channelSelect) {
                    y = 15 * SIZE_M * GRID_H;
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
                class GVAR(globalConfig) {
                    displayName = "ACRE Configuration global";
                    collapsed = 0;
                    class Attributes {
                        class masterEnabled {
                            displayName = "Master Enable";
                            property = QGVAR(enabled);
                            control = "Checkbox";
                            defaultValue = QUOTE((GVAR(enabled)));
                            typeName = "BOOL";
                            expression = "";
                        };
                        class radioInterference {
                            displayName = "Allow radio to radio interference";
                            property = QGVAR(radioInterference);
                            control = "Checkbox";
                            defaultValue = QUOTE((GVAR(radioInterference)));
                            typeName = "BOOL";
                            expression = "";
                        };
                        class terrainInterference {
                            displayName = "Set level of terrain interference";
                            property = QGVAR(terrainInterference);
                            control = "Slider";
                            defaultValue = QUOTE((GVAR(terrainInterference)));
                            typeName = "NUMBER";
                            expression = "";
                        };
                        class addCommonChannelName {
                            displayName = "Shared channel name";
                            property = QGVAR(addCommonChannelName);
                            control = "Edit";
                            defaultValue = QUOTE((GVAR(addCommonChannelName)));
                            typeName = "STRING";
                            expression = "";
                        };
                        class addCommonChannelNumber {
                            displayName = "Shared channel number";
                            property = QGVAR(addCommonChannelNumber);
                            control = "Combo";
                            defaultValue = QUOTE((GVAR(addCommonChannelNumber)));
                            typeName = "NUMBER";
                            expression = "";
                            class values {
                                class 1 { name = "1"; value = 1; };
                                class 2 { name = "2"; value = 2; };
                                class 3 { name = "3"; value = 3; };
                                class 4 { name = "4"; value = 4; };
                                class 5 { name = "5"; value = 5; };
                                class 6 { name = "6"; value = 6; };
                                class 7 { name = "7"; value = 7; };
                                class 8 { name = "8"; value = 8; };
                                class 9 { name = "9"; value = 9; };
                                class 10 { name = "10"; value = 10; };
                                class 11 { name = "11"; value = 11; };
                                class 12 { name = "12"; value = 12; };
                                class 13 { name = "13"; value = 13; };
                                class 14 { name = "14"; value = 14; };
                                class 15 { name = "15"; value = 15; };
                                class 16 { name = "16"; value = 16; };
                                class 17 { name = "17"; value = 17; };
                                class 18 { name = "18"; value = 18; };
                                class 19 { name = "19"; value = 19; };
                                class 20 { name = "20"; value = 20; };
                            };
                        };
                        class addCommonChannelAllMR {
                            displayName = "Global shared 148 channel";
                            property = QGVAR(addCommonChannelAllMR);
                            control = "Checkbox";
                            defaultValue = QUOTE((GVAR(addCommonChannelAllMR)));
                            typeName = "BOOL";
                            expression = "";
                        };
                        class addCommonChannelAllLR {
                            displayName = "Global shared 117 channel";
                            property = QGVAR(addCommonChannelAllLR);
                            control = "Checkbox";
                            defaultValue = QUOTE((GVAR(addCommonChannelAllLR)));
                            typeName = "BOOL";
                            expression = "";
                        };
                    };
                };
                class GVAR(sideConfig) {
                    displayName = "ACRE Configuration per side";
                    collapsed = 0;
                    class Attributes {
                        class GVAR(sideConfig) {
                            property = QGVAR(channelsAndBabel);
                            control = QGVAR(configureAcre);
                            expression = QUOTE([ARR_2(_this,_value)] call FUNC(acreAttributeLoad));
                        };
                    };
                };
            };
        };
    };
};
