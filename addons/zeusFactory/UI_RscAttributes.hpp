class RscControlsGroupNoScrollbars;
class RscText;
class RscListBox;
class RscToolbox;
class RscXSliderH;
class RscEdit;
class RscCheckBox;

class RscDisplayAttributes {
    class Controls {
        class Background;
        class Title;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    };
};
class GVAR(RscDisplayAttributes_factory): RscDisplayAttributes {
    onLoad = QUOTE([ARR_3('onLoad', _this, QUOTE(QGVAR(RscDisplayAttributes_factory)))] call ace_zeus_fnc_zeusAttributes);
    onUnload = QUOTE([ARR_3('onUnload', _this, QUOTE(QGVAR(RscDisplayAttributes_factory)))] call ace_zeus_fnc_zeusAttributes);
    class Controls: Controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class factoryAttributes: RscControlsGroupNoScrollbars {
                    onSetFocus = QUOTE(_this call FUNC(zeusAttributes_factory));
                    idc = 26422;
                    x = "0";
                    y = "0";
                    w = "26 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "20 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    class controls {
                        class sideList: RscToolbox {
                            idc = 23071;
                            strings[] = {"Blufor", "Opfor", "Independent"};
                            rows = 1;
                            columns = 3;
                            colorBackground[] = {0, 0, 0, 0.5};
                            colorText[] = {1, 1, 1, 1};
                            colorTextSelect[] = {1, 1, 1, 1};
                            color[] = {1, 0, 1, 1};
                            colorSelect[] = {0, 0, 0, 0};
                            colorTextDisable[] = {0, 0, 0, 0};
                            colorDisable[] = {0, 0, 0, 0};
                            x = "6.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0.25 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "13 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class carTypeText: RscText {
                            idc = -1;
                            text = "Car:";
                            style = 2;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class carTypeCombo: RscListBox {
                            idc = 23072;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "16.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class apcTypeText: RscText {
                            idc = -1;
                            text = "APC:";
                            style = 2;
                            x = "9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class apcTypeCombo: RscListBox {
                            idc = 23073;
                            x = "9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "16.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class heliTypeText: RscText {
                            idc = -1;
                            text = "Air:";
                            style = 2;
                            x = "17.2 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class heliTypeCombo: RscListBox {
                            idc = 23074;
                            x = "17.2 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "16.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };

                    };
                };
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
class GVAR(RscDisplayAttributes_place): RscDisplayAttributes {
    onLoad = QUOTE([ARR_3('onLoad', _this, QUOTE(QGVAR(RscDisplayAttributes_place)))] call ace_zeus_fnc_zeusAttributes);
    onUnload = QUOTE([ARR_3('onUnload', _this, QUOTE(QGVAR(RscDisplayAttributes_place)))] call ace_zeus_fnc_zeusAttributes);
    class Controls: Controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class placeAttributes: RscControlsGroupNoScrollbars {
                    onSetFocus = QUOTE(_this call FUNC(zeusAttributes_place));
                    idc = 26422;
                    x = "0";
                    y = "0";
                    w = "26 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "9.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    class controls {
                        class transportText: RscText {
                            text = "Transport:";
                            idc = -1;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class transportList: RscListBox {
                            idc = 23071;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class ordersText: RscText {
                            text = "Orders:";
                            idc = -1;
                            x = "9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class ordersList: RscListBox {
                            idc = 23072;
                            x = "9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class radiusText: RscText {
                            text = "Radius:";
                            idc = -1;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "8.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "4 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class radiusValue: RscXSliderH {
                            idc = 23074;
                            x = "4.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "8.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "17.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class radiusEdit: RscEdit {
                            idc = 23075;
                            x = "22.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "8.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "3 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class attackMarkText: RscText {
                            text = "Complete orders at target";
                            idc = -1;
                            x = "17.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class attackMarkCheckbox: RscCheckBox {
                            idc = 23076;
                            x = "17.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "1 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class useLAMBSText: RscText {
                            text = "Use LAMBS AI Waypoints";
                            idc = -1;
                            x = "17.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "2.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "8.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class useLAMBSCheckbox: RscCheckBox {
                            idc = 23077;
                            x = "17.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "1 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                    };
                };
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
