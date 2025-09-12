#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_common",
            "potato_core"
        };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = { "AChesheireCat", "ARK", "Ampersand" };
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
