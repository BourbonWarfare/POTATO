class RscControlsGroupNoScrollbars;
class RscStructuredText;
class RscText;

//Safe Start Overlay:
class RscTitles {
    class GVAR(timerRscTitle_old) {
        idd = IDD_SAFESTART;
        onLoad = QUOTE(with uiNamespace do {GVAR(timerRscTitle) = _this select 0;};);
        movingEnable = "false";
        duration = 2147483647;
        fadeIn = 0;
        fadeOut = 0.5;
        class controls {
            class safeStartHint: RscStructuredText {
                idc = HINT_IDC;
                x = QUOTE(0 * safezoneW + safezoneX);
                y = QUOTE(0.05 * safezoneH + safezoneY);
                w = QUOTE(0.2 * safezoneW);
                h = QUOTE(0.2 * safezoneH);
            };
        };
    };
    class GVAR(timerRscTitle): GVAR(timerRscTitle_old) {
        idd = -1;
        movingEnable = 1;
        duration = 99999999;
        class controls {
            class controlGroup: RscControlsGroupNoScrollbars {
                idc = IDC_SAFESTARTINFO_BASEGRP;
                x = QUOTE(profileNamespace getVariable [ARR_2(QQUOTE(TRIPLES(igui,GVAR(grid),x)),SAFESTART_MENU_DEFAULT_X)]);
                y = QUOTE(profileNamespace getVariable [ARR_2(QQUOTE(TRIPLES(igui,GVAR(grid),y)),SAFESTART_MENU_DEFAULT_Y)]);
                w = SAFESTART_MENU_WIDTH;
                h = SAFESTART_MENU_HEIGHT;
                class controls {
                    class Background: RscText { // We need to hide this when we don't show the info
                        idc = IDC_SAFESTARTEQUIP_BACKGROUND;
                        x = 0;
                        y = 0;
                        w = SAFESTART_MENU_WIDTH;
                        h = SAFESTART_MENU_HEIGHT;
                        colorBackground[] = {0,0,0,0.6};
                    };
                    class safeStartHint: RscStructuredText {
                        idc = HINT_IDC;
                        x = 0;
                        y = "0.25 * ((safezoneW / safezoneH) min 1.2) / 25";
                        w = SAFESTART_MENU_WIDTH_ALIGN_NUMBER;
                        h = "3 * ((safezoneW / safezoneH) min 1.2) / 40";
                        class Attributes {
                            font = "RobotoCondensed";
                            color = "#ffffff";
                            colorLink = "#D09B43";
                            align = "center";
                            shadow = 1;
                        };
                    };
                    class safeStartInfoGroup: RscControlsGroupNoScrollbars {
                        idc = IDC_SAFESTARTINFO_DISP;
                        x = 0;
                        y = "2.25 * ((safezoneW / safezoneH) min 1.2) / 25";
                        w = SAFESTART_MENU_WIDTH;
                        h = "13.4 * ((safezoneW / safezoneH) min 1.2) / 25";
                        onLoad = QUOTE(_this call FUNC(fillSafeStartEquip));
                        class controls {
                            class RscText_title: RscStructuredText {
                                idc = IDC_SAFESTARTEQUIP_TITLE;
                                text = "Safe Start Info";
                                font = "PuristaBold";
                                sizeEx = "0.048";
                                size = "0.048";
                                x = SAFESTART_TEXT_OFFSET_X;
                                y = 0;
                                w = SAFESTART_MENU_WIDTH_OFFSET;
                                h = "1.25 * ((safezoneW / safezoneH) min 1.2) / 25";
                                class Attributes {
                                    font = "RobotoCondensed";
                                    color = "#ffffff";
                                    colorLink = "#D09B43";
                                    align = "left";
                                    shadow = 0;
                                };
                            };
                            class RscText_equip: RscStructuredText {
                                idc = IDC_SAFESTARTEQUIP_TEXT;
                                text = "";
                                sizeEx = "0.053";
                                size = "0.038";
                                x = SAFESTART_TEXT_OFFSET_X;
                                y = "0.8 * ((safezoneW / safezoneH) min 1.2) / 25";
                                w = SAFESTART_MENU_WIDTH_OFFSET;
                                h = "13 * ((safezoneW / safezoneH) min 1.2) / 25";
                                class Attributes {
                                    font = "RobotoCondensed";
                                    color = "#ffffff";
                                    colorLink = "#D09B43";
                                    align = "left";
                                    shadow = 0;
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    class GVAR(startingRscTitle) {
        idd = -1;
        onLoad = QUOTE(with uiNamespace do { GVAR(startingRscTitle) = _this select 0; };);
        movingEnable = "false";
        duration = 8;
        fadeIn = 0.5;
        fadeOut = 0.5;
        class controls {
            class safeStartHint: RscStructuredText {
                idc = HINT_IDC;
                text = "<t align='center'>Safe Start Ending<br/><t color='#ff0000'>Start Mission</t></t>";
                x = QUOTE(0.4 * safezoneW + safezoneX);
                y = QUOTE(0.4 * safezoneH + safezoneY);
                w = QUOTE(0.2 * safezoneW);
                h = QUOTE(0.2 * safezoneH);
            };
        };
    };
};
