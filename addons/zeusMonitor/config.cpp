#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

class RscText;
class RscDisplayCurator {
    class ControlsBackground {
        class GVAR(unitCount): RscText {
            idc = 777551;
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "128 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Sample";
        };
    };
};
