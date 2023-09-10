#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchAMP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "AMP_Breaching_Charge" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
class CfgVehicles {
    // AMP_Breaching_Charge
    class ACE_Explosives_Place_SLAM;
    class AMP_Breaching_Charge_Place: ACE_Explosives_Place_SLAM { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; };
};
