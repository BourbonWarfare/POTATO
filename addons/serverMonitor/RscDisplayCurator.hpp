class RscButton;
class RscText;

class RscDisplayCurator {
    class Controls {
        class GVAR(acreSpectateButton): RscButton {
            idc = 777550;
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "12 * pixelH";
            sizeEx = "12 * pixelH";
            text = "ACRE Spectator";
            action = QUOTE(_this call FUNC(zeus_toggleAcreSepcator));
        };
        class GVAR(unitCount): RscText {
            idc = 777551;
            x = "safezoneX + 80 * pixelW";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Sample";
        };
    };
};
