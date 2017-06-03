#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"MikeMatrix"};
        authorUrl = "https://github.com/MikeMatrix";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
