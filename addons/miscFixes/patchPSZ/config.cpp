#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPSZ

class CfgPatches {
    class ADDON {
        weapons[] = {};
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "psz_common", "psz_weapons" };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// fix WARNING: PSZ_VirtualAmmoBox does not support Extended Event Handlers! Addon: 2098564124
class CBA_Extended_EventHandlers;
class CfgVehicles {
    class B_supplyCrate_F;
    class PSZ_VirtualAmmoBox: B_supplyCrate_F {
        class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; };
    };
};
