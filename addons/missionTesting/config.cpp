#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(missionTesting)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"BadWolf"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

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


#include "CfgEventHandlers.hpp"
#include "CfgEden.hpp"
#include "CfgVehicles.hpp"

