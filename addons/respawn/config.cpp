#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(placeRespawnPoint), QGVAR(openRespawnMenu)};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgRespawnFactions.hpp"
#include "CfgRespawnGroups.hpp"
#include "CfgVehicles.hpp"
#include "Displays.hpp"
