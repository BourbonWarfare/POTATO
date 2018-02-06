#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(zeus_missionHint), QGVAR(zeus_globalSetSkill), QGVAR(sideMarker), QGVAR(zeus_banziCharge)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "Displays.hpp"
