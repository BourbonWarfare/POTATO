#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPRAA

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "praa_tunnels" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Logic;
    class PRAA_module_tunnels: Logic { XEH_ENABLED; }; // "PR: Tunnels module" 2782377305
};
