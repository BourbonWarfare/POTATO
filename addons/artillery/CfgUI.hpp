#include "\a3\ui_f\hpp\defineCommonGrids.inc"
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscCombo;
class RscMapControl;
class RscXSliderH;
class RscText;


class GVAR(ArtilleryDisplay) {
    idd = IDD_ARTILLERY_MENU;
    x = 0.425;
    y = 0.1;
    w = 0.75;
    h = 0.6;
    onUnload = QUOTE([ARR_2(true,_this)] call FUNC(ui_artilleryHandle));
    onLoad = QUOTE([ARR_2(false,_this)] call FUNC(ui_artilleryHandle));
    class ControlsBackground {
        class Background : RscText {
            idc = -1;
            x = QUOTE(-10 * GUI_GRID_CENTER_W);
            y = QUOTE(GUI_GRID_CENTER_Y);
            w = QUOTE(50 * GUI_GRID_CENTER_W);
            h = QUOTE(28 * GUI_GRID_CENTER_H);
            colorBackground[] = {0,0,0,0.8};
        };
    };
    class Controls {
        class RscText_title: RscText {
            idc = -1;
            text = "Potato Artillery Interface";
            style = 2;
            x = QUOTE(-10 * GUI_GRID_CENTER_W);
            y = 0.05;
            w = QUOTE(50 * GUI_GRID_CENTER_W);
            h = 0.1;
            sizeEx = 0.1;
        };
        class RscText_gunCount: RscText {
            idc = -1;
            text = "Gun Count";
            style = 1;
            x = 0.45;
            y = 0.2;
            w = 0.28;
            h = 0.06;
        };
        class RscCombo_gunCount: RscCombo {
            idc = IDC_ARTILLERY_GUUNCOUNT;
            x = 0.75;
            y = 0.2;
            w = 0.4;
            h = 0.06;
            onLBSelChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_GUUNCOUNT)] call FUNC(ui_updateArtillleryMenu););
            tooltip = "Type of Artillery Mission";
            class Items {
                class None {
                    text = "None";
                    value = 0;
                };
                class oneTube {
                    text = "One";
                    value = 1;
                };
                class twoTube {
                    text = "Two";
                    value = 2;
                    default = 1;
                };
                class threeTube {
                    text = "Three";
                    value = 3;
                };
                class fourTube {
                    text = "Four";
                    value = 4;
                };
                class fiveTube {
                    text = "Five";
                    value = 5;
                };
                class sixTube {
                    text = "Six";
                    value = 6;
                };
                class allTube {
                    text = "All";
                    value = 7;
                };
            };
        };
        class RscText_missionType: RscText_gunCount {
            text = "Mission Type";
            y = 0.3;
        };
        class RscCombo_missionType: RscCombo {
            idc = IDC_ARTILLERY_MISSIONTYPE;
            x = 0.75;
            y = 0.3;
            w = 0.4;
            h = 0.06;
            onLBSelChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_MISSIONTYPE)] call FUNC(ui_updateArtillleryMenu););
            tooltip = "Type of Artillery Mission";
            class Items {
                class lazyZero {
                    text = "Slow Adjust";
                    value = ARTILLERY_MISSIONTYPE_LAZY;
                    default = 1;
                };
                class bracket {
                    text = "Bracket";
                    value = ARTILLERY_MISSIONTYPE_BRACKET;
                };
                class point {
                    text = "Immediate";
                    value = ARTILLERY_MISSIONTYPE_POINT;
                };
                class linearBarrage {
                    text = "Linear";
                    value = ARTILLERY_MISSIONTYPE_LINEAR;
                };
                class linearBarrageCreep {
                    text = "Linear with Bracketing";
                    value = ARTILLERY_MISSIONTYPE_LINEAR_WITH_WALK;
                };
                class creeping {
                    text = "Creeping";
                    value = ARTILLERY_MISSIONTYPE_CREEPING;
                };
                class slowBarrage {
                    text = "Slow Barrage";
                    value = ARTILLERY_MISSIONTYPE_SLOW;
                };
                class slowBarrageWalk {
                    text = "Slow Barrage with Walk";
                    value = ARTILLERY_MISSIONTYPE_SLOW_WITH_WALK;
                };
            };
        };
        class RscText_roundType: RscText_gunCount {
            text = "Round Type";
            y = 0.4;
        };
        class RscCombo_roundType: RscCombo {
            idc = IDC_ARTILLERY_ROUNDTYPE;
            x = 0.75;
            y = 0.4;
            w = 0.4;
            h = 0.06;
	          sizeEx = 0.035;
            onLBSelChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_ROUNDTYPE)] call FUNC(ui_updateArtillleryMenu););
            tooltip = "Type of Round";
        };
        class RscText_dispersion: RscText_gunCount {
            text = "Round Dispersion";
            y = 0.51;
        };
        class RscSlider_dispersion: RscXSliderH {
            idc = IDC_ARTILLERY_DISPERSION;
            x = 0.75;
            y = 0.52;
            w = 0.4;
            h = 0.04;
            sliderPosition = 60;
            sliderRange[] = {10, 600};
            onSliderPosChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_DISPERSION)] call FUNC(ui_updateArtillleryMenu););
        };
        class RscText_lineAngle: RscText_gunCount {
            text = "Mission Rotation";
            y = 0.62;
        };
        class RscSlider_angle: RscSlider_dispersion {
            idc = IDC_ARTILLERY_ROTATION;
            y = 0.63;
            sliderPosition = 0;
            sliderRange[] = {-180, 180};
            onSliderPosChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_ROTATION)] call FUNC(ui_updateArtillleryMenu););
        };
        class RscText_missionLength: RscText_gunCount {
            idc = IDC_ARTILLERY_MISSIONGLENGTHTXT;
            text = "Rounds per gun (1-16): 06";
            y = 0.73;
        };
        class RscSlider_missionLength: RscSlider_dispersion {
            idc = IDC_ARTILLERY_MISSIONGLENGTH;
            y = 0.74;
            sliderPosition = 6;
            sliderRange[] = {1, 16};
            sliderStep = 1;
            onSliderPosChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_MISSIONGLENGTH)] call FUNC(ui_updateArtillleryMenu););
        };
        class RscText_missionDelay: RscText_gunCount {
            idc = IDC_ARTILLERY_MISSIONGDELAYTXT;
            text = "Mission delay: 00:05";
            y = 0.82;
        };
        class RscSlider_missionDelay: RscSlider_dispersion {
            idc = IDC_ARTILLERY_MISSIONGDELAY;
            y = 0.83;
            sliderPosition = ARTILLERY_MISSION_MIN_DELAY;
            sliderRange[] = {ARTILLERY_MISSION_MIN_DELAY, 900};
            sliderStep = 5;
            onSliderPosChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_MISSIONGDELAY)] call FUNC(ui_updateArtillleryMenu););
        };
        class RscText_missionTimeLength: RscText_gunCount {
            idc = IDC_ARTILLERY_MISSIONGLENGTHTIMETXT;
            text = "Mission length : 03:00";
            y = 0.91;
        };
        class RscSlider_missionTimeLength: RscSlider_dispersion {
            idc = IDC_ARTILLERY_MISSIONGLENGTHTIME;
            y = 0.92;
            sliderPosition = ARTILLERY_MISSION_DEF_LENGTH;
            sliderRange[] = {ARTILLERY_MISSION_MIN_LENGTH, 900};
            sliderStep = 5;
            onSliderPosChanged = QUOTE([ARR_2(_this,IDC_ARTILLERY_MISSIONGLENGTHTIME)] call FUNC(ui_updateArtillleryMenu););
        };
        /*class RscCheckBox_avoidPlayers: RscCheckBox {
            checked = 1;
            idc = IDC_ARTILLERY_AVOIDPLAYERS;
            onCheckedChanged = QUOTE(GVAR(artilleryParams) set [ARR_2(QQUOTE(avoidPlayers),1 == _this#1)];);
            h = 0.05;
            w = 0.0375;
            x = 0.75;
            y = 0.915;
        };
        class RscText_avoidPlayers: RscText_gunCount {
            idc = -1;
            text = "Attempt to avoid players";
            y = 0.91;
        };*/
        class RscButtonMenuOK_exit: RscButtonMenuOK {
            x = 1;
            y = 1;
            w = 0.15;
            h = 0.08;
            text = "Fire";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = "0.25 * (((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 40)";
                right = 0.005;
                top = "(((((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 1.2) / 25) - (((((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 1.2) / 25) * 1)) / 2";
                forceMiddle = 1;
            };
        };
        class RscButtonMenuCancel_exit: RscButtonMenuCancel {
            x = 0.45;
            y = 1;
            w = 0.15;
            h = 0.08;
            text = "Cancel";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = "0.25 * (((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 40)";
                right = 0.005;
                top = "(((((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 1.2) / 25) - (((((safeZoneW_LMD / safezoneH_LMD) min 1.2) / 1.2) / 25) * 1)) / 2";
                forceMiddle = 1;
            };
        };
        class RscMap_UIInterface: RscMapControl {
            idc = IDC_ARTILLERY_MAP;
            x = -0.275;
            y = 0.2;
            w = 0.6875;
            h = 0.86;
        };
    };
};
