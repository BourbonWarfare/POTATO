class RscStructuredText;

//Safe Start Overlay:
class RscTitles {
    class GVAR(safeStartRscTitle) {
        idd = -1;
        onLoad = QUOTE( with uiNamespace do {GVAR(safeStartRscTitle) = _this select 0;};);
        movingEnable = "false";
        duration = 2147483647;
        fadeIn = 1;
        fadeOut = 1;
        class controls {
            class safeStartHint: RscStructuredText {
                idc = 1100;
                x = 0.4 * safezoneW + safezoneX;
                y = 0.4 * safezoneH + safezoneY;
                w = 0.2 * safezoneW;
                h = 0.2 * safezoneH;
            };
        };
    };
};
