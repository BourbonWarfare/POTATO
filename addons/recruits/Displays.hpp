class RscStructuredText;

//Safe Start Overlay:
class RscTitles {
    class GVAR(message) {
        idd = -1;
        onLoad = QUOTE(with uiNamespace do { GVAR(message) = _this select 0; };);
        movingEnable = 0;
        duration = 2147483647;
        fadeIn = 0.5;
        fadeOut = 0.5;
        name = QGVAR(message);

        class controls {
            class GVAR(message): RscStructuredText {
                idc = MESSAGE_IDC;
                colorText[] = {1, 1, 1, 1};
                colorBackground[] = {0, 0, 0, 0.5};
                x = 0.88 * safezoneW + safezoneX;
                y = 0.15 * safezoneH + safezoneY;
                w = 0.105 * safezoneW;
                h = 0;
                font = "RobotoCondensed";
            };
        };
    };
};
