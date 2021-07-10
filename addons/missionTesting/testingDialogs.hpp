class GVAR(displayMissionTesting) {
    idd = 9999;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};
class GVAR(displayBreifings) {
    idd = 9998;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};

class IGUIBack;
class RscPicture;
class RscCombo;
class RscSlider;

class GVAR(LoadoutPID) {
    idd = 9997;
    movingEnable = 1;
    duration = 9999999;
    fadein = 0;
    fadeout = 0;
    onLoad = QUOTE(with uiNamespace do {GVAR(LoadoutPID) = _this select 0;};);
    onKeyDown = QUOTE(with uiNamespace do {_this spawn FUNC(cutRscPID)});


    class controls {
        class IGUIBack_2200: IGUIBack
        {
            idc = 2200;
            x = 0.283378 * safezoneW + safezoneX;
            y = 0.6 * safezoneH + safezoneY;
            w = 0.433243 * safezoneW;
            h = 0.175 * safezoneH;
            moving = 1;
        };
        class RscCombo_2100: RscCombo
        {
            idc = 2100;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2101: RscCombo
        {
            idc = 2101;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2102: RscCombo
        {
            idc = 2102;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.643 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Faction"; //--- ToDo: Localize;
        };
        class RscCombo_2103: RscCombo
        {
            idc = 2103;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2104: RscCombo
        {
            idc = 2104;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2105: RscCombo
        {
            idc = 2105;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Class"; //--- ToDo: Localize;
        };
        class RscCombo_2106: RscCombo
        {
            idc = 2106;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscCombo_2107: RscCombo
        {
            idc = 2107;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscCombo_2108: RscCombo
        {
            idc = 2108;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Select Stance"; //--- ToDo: Localize;
        };
        class RscSlider_1900: RscSlider
        {
            idc = 1900;
            x = 0.29421 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscSlider_1901: RscSlider
        {
            idc = 1901;
            x = 0.435014 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscSlider_1902: RscSlider
        {
            idc = 1902;
            x = 0.575818 * safezoneW + safezoneX;
            y = 0.61 * safezoneH + safezoneY;
            w = 0.129973 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };
    class objects {};
};
