class RscButton;
class RscDisplayCurator {
    class Controls {
        class GVAR(displayFPSButton): RscButton {
            idc = ZEUSUTILS_IDC_DISPLAYFPSBUTTON;
            // based on Potato's ACRE spectate button
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 42 * pixelH";
            w = "80 * pixelW";
            h = "12 * pixelH";
            sizeEx = "12 * pixelH";
            text = "FPS Display";
            tooltip = "Display player FPS under each the unit of each client.";
            onLoad = QUOTE([ARR_2(_this#0,true)] call FUNC(changeFPSDisplayState));
            onButtonClick = QUOTE([_this#0] call FUNC(changeFPSDisplayState));
        };
        class GVAR(displayMarkersButton): GVAR(displayFPSButton) {
            idc = ZEUSUTILS_IDC_DISPLAYMARKERBUTTON;
            y = "safezoneY + safeZoneH - 28 * pixelH";
            text = "Marker Display";
            tooltip = "Display markers above units with them.";
            onLoad = QUOTE([ARR_2(_this#0,true)] call FUNC(changeMarkerDisplayState));
            onButtonClick = QUOTE([_this#0] call FUNC(changeMarkerDisplayState));
        };
    };
};
