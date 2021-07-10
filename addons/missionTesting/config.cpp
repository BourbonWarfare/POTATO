#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(missionTesting)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"BadWolf"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "testingDialogs.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgEden.hpp"
#include "CfgVehicles.hpp"

