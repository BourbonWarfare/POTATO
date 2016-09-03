class RscButton;
class RscText;

class RscDisplayCurator {
    class Controls {
        class GVAR(acreSpectateButton): RscButton {
            idc = 777550;
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "ACRE Spectator";
            action = QUOTE(_this call FUNC(toggleAcreSepcator));
        };       
        class GVAR(cleanupButton): RscButton {
            idc = 777551;
            x = "safezoneX + 85 * pixelW";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Cleanup Dead: xx";
            action = QUOTE(_this call FUNC(toggleAutoCleanup));
        };
        class GVAR(unitCount): RscText {
            idc = 777552;
            x = "safezoneX + 170 * pixelW";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "safeZoneW - 170 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Sample";
        };
    };
};
