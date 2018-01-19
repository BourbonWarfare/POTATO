#include "script_component.hpp"

#ifndef POTATO_LEAN_CONFIGS

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_radios"};
        author = "Potato";
        authors[] = {"AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgRespawnTemplates.hpp"
#include "CfgVehicleIcons.hpp"
#include "CfgVehicles.hpp"
#include "Displays.hpp"

#endif
