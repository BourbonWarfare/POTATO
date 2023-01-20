#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchAMP

#if __has_include("\z\bcdw\addons\main\script_mod.hpp")
#else
#define PATCH_SKIP "AMP Breaching"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "AMP_Breaching_Charge" };
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

#endif
