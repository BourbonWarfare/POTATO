#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "potato_safeStart"};
        author = "Potato";
        authors[] = {"Bismarck"};
        authorUrl = "https://github.com/SignalCommunity/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
