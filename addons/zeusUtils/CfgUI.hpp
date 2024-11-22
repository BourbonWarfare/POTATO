class RscButton;
class RscDisplayCurator {
    class Controls {
        class GVAR(displayFPSButton): RscButton {
            idc = ZEUSUTILS_IDC_DISPLAYFPSBUTTON;
            // based on Potato's ACRE spectate button
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 28 * pixelH";
            w = "80 * pixelW";
            h = "12 * pixelH";
            sizeEx = "12 * pixelH";
            text = "FPS Display";
            onLoad = QUOTE([ARR_2(_this#0,1)] call FUNC(changeFPSDisplayState));
            onButtonClick = QUOTE([_this#0] call FUNC(changeFPSDisplayState));
        };
    };
};