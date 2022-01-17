#include "script_component.hpp"

class GVAR(displayMissionTesting) {
    idd = DISPLAY_TESTMENU_IDD;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};
class GVAR(displayBreifings) {
    idd = DISPLAY_BRIEF_IDD;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};

import RscPicture;
import RscCombo;
import RscXSliderH;

class GVAR(LoadoutPID) {
    idd = DISPLAY_PID_IDD;
    onLoad = QUOTE(with uiNamespace do {GVAR(LoadoutPID) = _this select 0;};);
    onKeyDown = QUOTE(with uiNamespace do {_this call FUNC(freeMoveInitPID)});


    class controls {
        class IGUIBack_2200: RscPicture
        {
            idc = 2200;
            x = 0.283378 * safezoneW + safezoneX;
            y = 0.6 * safezoneH + safezoneY;
            w = 0.433243 * safezoneW;
            h = 0.175 * safezoneH;
            moving = 0;
        };
        class RscCombo_2100: RscCombo
        {
            idc = PID_SIDE_2_IDC;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2101: RscCombo
        {
            idc = PID_SIDE_1_IDC;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2102: RscCombo
        {
            idc = PID_SIDE_3_IDC;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2103: RscCombo
        {
            idc = PID_CLASS_2_IDC;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2104: RscCombo
        {
            idc = PID_CLASS_1_IDC;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2105: RscCombo
        {
            idc = PID_CLASS_3_IDC;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2106: RscCombo
        {
            idc = PID_STANCE_2_IDC;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscCombo_2107: RscCombo
        {
            idc = PID_STANCE_1_IDC;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscCombo_2108: RscCombo
        {
            idc = PID_STANCE_3_IDC;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscSlider_1900: RscXSliderH
        {
            idc = PID_DIR_SLIDER_2_IDC;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscSlider_1901: RscXSliderH
        {
            idc = PID_DIR_SLIDER_1_IDC;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscSlider_1902: RscXSliderH
        {
            idc = PID_DIR_SLIDER_3_IDC;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };
    class objects {};
};

import RscDisplayEmpty;

class RscTitles
{
	class GVAR(RscTitleLoadoutPID) : RscDisplayEmpty {
        movingEnable = 0;
        duration = 9999999;
        fadein = 0;
        fadeout = 0;
        onKeyDown = QUOTE(with uiNamespace do {_this call FUNC(freeMoveExitPID)});
    };
};
