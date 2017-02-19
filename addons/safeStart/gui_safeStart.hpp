class RscStructuredText;

//Safe Start Overlay:
class RscTitles {
    class GVAR(timerRscTitle) {
        idd = -1;
        onLoad = QUOTE(with uiNamespace do { GVAR(timerRscTitle) = _this select 0; };);
        movingEnable = "false";
        duration = 2147483647;
        fadeIn = 0;
        fadeOut = 0.5;
        class controls {
            class safeStartHint: RscStructuredText {
                idc = HINT_IDC;
                x = 0 * safezoneW + safezoneX;
                y = 0.05 * safezoneH + safezoneY;
                w = 0.2 * safezoneW;
                h = 0.2 * safezoneH;
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
                x = 0.4 * safezoneW + safezoneX;
                y = 0.4 * safezoneH + safezoneY;
                w = 0.2 * safezoneW;
                h = 0.2 * safezoneH;
            };
        };
    };
};
