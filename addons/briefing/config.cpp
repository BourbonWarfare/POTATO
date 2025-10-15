#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "3DEN"};
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"


class RscText;
class RscStandardDisplay;
class RscDisplayDebriefing: RscStandardDisplay {
    class controls {
        class PlayerName: RscText {
            onLoad = QUOTE(call FUNC(DisplayDebriefing));
        };
    };
};
